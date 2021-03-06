/*-
 * $Copyright$
 */

#include "common/Infrastructure.hpp"
#include "stm32f4xx.h"      /* for SysTick_Type */
#include "FreeRTOSConfig.h" /* for SystemCoreClock */
#include "phisch/log.h"
#include "version.h"
#include <cassert>

/******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif /* defined (__cplusplus) */
/******************************************************************************/

/******************************************************************************/
#if !defined(HOSTBUILD)
void __assert_func (const char *p_file, int p_line, const char *p_func, const char *p_msg) {
#if defined(NO_LOGGING)
    (void) p_file;
    (void) p_line;
    (void) p_func;
    (void) p_msg;
#endif

    PHISCH_LOG("%s() @ %s : %d \r\n%s\r\n", p_func, p_file, p_line, p_msg);

#if !defined(HOSTBUILD)
    asm volatile("bkpt #0");
#endif

    while (1) { };
}

void
__assert (const char *p_file, int p_line, const char *p_msg) {
    __assert_func (p_file, p_line, __func__, p_msg);
}
#endif /* defined(HOSTBUILD) */
/******************************************************************************/

/******************************************************************************/
void
PrintStartupMessage(unsigned p_sysclk, unsigned p_ahb, unsigned p_apb1, unsigned p_apb2) {
#if defined(NO_LOGGING)
    (void) p_sysclk;
    (void) p_ahb;
    (void) p_apb1;
    (void) p_apb2;
#endif

    PHISCH_LOG("Copyright (c) 2013-2020 Philip Schulz <phs@phisch.org>\r\n");
    PHISCH_LOG("All rights reserved.\r\n");
    PHISCH_LOG("\r\n");
    PHISCH_LOG("Project Name: %s\r\n", gProjectName);
    PHISCH_LOG("SW Version: %s\r\n", gSwVersionId);
    PHISCH_LOG("SW Build Timestamp: %s\r\n", gSwBuildTime);
    PHISCH_LOG("\r\n");
    PHISCH_LOG("Fixed Data: [0x0%x - 0x0%x]\t(%d Bytes total, %d Bytes used)\r\n",
      &gFixedDataBegin, &gFixedDataEnd, &gFixedDataEnd - &gFixedDataBegin, &gFixedDataUsed- &gFixedDataBegin);
    PHISCH_LOG("      Code: [0x0%x - 0x0%x]\t(%d Bytes)\r\n", &stext, &etext, &etext - &stext);
    PHISCH_LOG("      Data: [0x%x - 0x%x]\t(%d Bytes)\r\n", &sdata, &edata, &edata - &sdata);
    PHISCH_LOG("       BSS: [0x%x - 0x%x]\t(%d Bytes)\r\n", &sbss, &ebss, &ebss - &sbss);
    PHISCH_LOG(" Total RAM: [0x%x - 0x%x]\t(%d Bytes)\r\n", &sdata, &ebss, &ebss - &sdata);
    PHISCH_LOG("     Stack: [0x%x - 0x%x]\t(%d Bytes)\r\n", &bstack, &estack, &estack - &bstack);
    PHISCH_LOG("\r\n");

    PHISCH_LOG("CPU running @ %d kHz\r\n", p_sysclk);
    PHISCH_LOG("        AHB @ %d kHz\r\n", p_ahb);
    PHISCH_LOG("       APB1 @ %d kHz\r\n", p_apb1);
    PHISCH_LOG("       APB2 @ %d kHz\r\n", p_apb2);
    PHISCH_LOG("\r\n");
}
/******************************************************************************/

/******************************************************************************/
#if !defined(HOSTBUILD)
int
usleep(unsigned p_usec) {
    SysTick_Type *sysTick = reinterpret_cast<SysTick_Type *>(SysTick_BASE);

    /*
     * Halt SysTick, if already running. Also, store current SysTick status.
     */
    bool enabled = (sysTick->CTRL & SysTick_CTRL_ENABLE_Msk) != 0;
    if (enabled) {
        sysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    }

    unsigned safeCtrl = sysTick->CTRL;
    unsigned safeLoad = sysTick->LOAD;
    unsigned safeVal  = sysTick->VAL;

    /*
     * Configure SysTick for 1ms Overflow, then wait for required number of
     * milliseconds.
     */
    const unsigned ticksPerMs = SystemCoreClock / 1000;
    assert((ticksPerMs & 0x00FFFFFF) == ticksPerMs); 
    unsigned waitMs = p_usec / 1000;

    sysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;
    sysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;

    sysTick->LOAD = ticksPerMs;
    sysTick->VAL = ticksPerMs;
    sysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    while (waitMs > 0) {
        while (!(sysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)) ;
        waitMs--;
    }
    sysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;

    /*
     * Configure SysTick for 1us Overflow, then wait for required number of
     * microseconds.
     */
    const unsigned ticksPerUs = SystemCoreClock / (1000 * 1000);
    assert((ticksPerUs & 0x00FFFFFF) == ticksPerUs);
    unsigned waitUs = p_usec & 1024; // Assumes 1ms = 1024us. Close enough.

    sysTick->LOAD = ticksPerUs;
    sysTick->VAL = ticksPerUs;
    sysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    while (waitUs > 0) {
        while (!(sysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)) ;
        waitUs--;
    }
    sysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;

    /*
     * Restore SysTick status.
     */
    sysTick->VAL  = safeVal;
    sysTick->LOAD = safeLoad;
    sysTick->CTRL = safeCtrl;
    if (enabled) {
        sysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    }
    
    return 0;
}
#endif /* defined(HOSTBUILD) */
/******************************************************************************/

/******************************************************************************/
#if defined(__cplusplus)
} /* extern "C" */
#endif /* defined (__cplusplus) */
/******************************************************************************/

/******************************************************************************/
#if !defined(NO_LOGGING)
#include <uart/UartDevice.hpp>

    __attribute__((weak))
    extern uart::UartDevice g_uart;

    #if defined(__cplusplus)
    extern "C" {
    #endif /* defined (__cplusplus) */

        __attribute__((weak))
        void
        debug_printf(const char * const p_fmt, ...) {
            va_list va;
            va_start(va, p_fmt);

        /*
         * Remove this call from the Host Build as this weak-symbol implementation
         * of the debug_printf() method ends up in the ELF file which can lead to
         * an unresolved symbol in linking.
         */
        #if !defined(HOSTBUILD)
            g_uart.vprintf(p_fmt, va);
        #endif

            va_end(va);
        }
    #if defined(__cplusplus)
    } /* extern "C" */
    #endif /* defined (__cplusplus) */

#endif
/******************************************************************************/

