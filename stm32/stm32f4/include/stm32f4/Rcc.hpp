/*-
 * $Copyright$
 */
#ifndef _STM32F4_RCC_HPP_EC38BF53_FF32_450A_9BF6_45322EBBAC33
#define _STM32F4_RCC_HPP_EC38BF53_FF32_450A_9BF6_45322EBBAC33

#include <stm32f4xx.h>

#include <stm32/Rcc.hpp>
#include <stm32/Gpio.hpp>
#include <stm32f4/Mco.hpp>

/*****************************************************************************/
namespace stm32 {
    namespace f4 {
        template<
            typename PllCfg,
            typename Flash,
            typename Pwr
        >
        class RccT
          : public RccViaSTM32T<
                RccT<PllCfg, Flash, Pwr>,
                ::stm32::f4::Mco
            >
        {
        public:
            typedef enum FunctionAPB1_e {
#if defined(RCC_APB1ENR_TIM2EN)
                e_Tim2      = RCC_APB1ENR_TIM2EN,
#endif
#if defined(RCC_APB1ENR_TIM3EN)
                e_Tim3      = RCC_APB1ENR_TIM3EN,
#endif
#if defined(RCC_APB1ENR_TIM4EN)
                e_Tim4      = RCC_APB1ENR_TIM4EN,
#endif
#if defined(RCC_APB1ENR_TIM5EN)
                e_Tim5      = RCC_APB1ENR_TIM5EN,
#endif
#if defined(RCC_APB1ENR_TIM6EN)
                e_Tim6      = RCC_APB1ENR_TIM6EN,
#endif
#if defined(RCC_APB1ENR_TIM7EN)
                e_Tim7      = RCC_APB1ENR_TIM7EN,
#endif
#if defined(RCC_APB1ENR_TIM12EN)
                e_Tim12     = RCC_APB1ENR_TIM12EN,
#endif
#if defined(RCC_APB1ENR_TIM13EN)
                e_Tim13     = RCC_APB1ENR_TIM13EN,
#endif
#if defined(RCC_APB1ENR_TIM14EN)
                e_Tim14     = RCC_APB1ENR_TIM14EN,
#endif
#if defined(RCC_APB1ENR_WWDGEN)
                e_Wwdg      = RCC_APB1ENR_WWDGEN,
#endif
#if defined(RCC_APB1ENR_SPI2EN)
                e_SPI2      = RCC_APB1ENR_SPI2EN,
#endif
#if defined(RCC_APB1ENR_SPI3EN)
                e_SPI3      = RCC_APB1ENR_SPI3EN,
#endif
#if defined(RCC_APB1ENR_USART2EN)
                e_USART2    = RCC_APB1ENR_USART2EN,
#endif
#if defined(RCC_APB1ENR_USART3EN)
                e_USART3    = RCC_APB1ENR_USART3EN,
#endif
#if defined(RCC_APB1ENR_UART4EN)
                e_UART4     = RCC_APB1ENR_UART4EN,
#endif
#if defined(RCC_APB1ENR_UART5EN)
                e_UART5     = RCC_APB1ENR_UART5EN,
#endif
#if defined(RCC_APB1ENR_I2C1EN)
                e_I2c1      = RCC_APB1ENR_I2C1EN,
#endif
#if defined(RCC_APB1ENR_I2C2EN)
                e_I2c2      = RCC_APB1ENR_I2C2EN,
#endif
#if defined(RCC_APB1ENR_I2C3EN)
                e_I2c3      = RCC_APB1ENR_I2C3EN,
#endif
#if defined(RCC_APB1ENR_CAN1EN)
                e_Can1      = RCC_APB1ENR_CAN1EN,
#endif
#if defined(RCC_APB1ENR_CAN2EN)
                e_Can2      = RCC_APB1ENR_CAN2EN,
#endif
#if defined(RCC_APB1ENR_PWREN)
                e_Pwr       = RCC_APB1ENR_PWREN,
#endif
#if defined(RCC_APB1ENR_DACEN)
                e_Dac       = RCC_APB1ENR_DACEN,
#endif
            } FunctionAPB1_t;

            typedef enum FunctionAPB2_e {
#if defined(RCC_APB2ENR_TIM1EN)
                e_Tim1      = RCC_APB2ENR_TIM1EN,
#endif
#if defined(RCC_APB2ENR_TIM8EN)
                e_Tim8      = RCC_APB2ENR_TIM8EN,
#endif
#if defined(RCC_APB2ENR_USART1EN)
                e_USART1    = RCC_APB2ENR_USART1EN,
#endif
#if defined(RCC_APB2ENR_USART6EN)
                e_USART6    = RCC_APB2ENR_USART6EN,
#endif
#if defined(RCC_APB2ENR_ADC1EN)
                e_Adc1      = RCC_APB2ENR_ADC1EN,
#endif
#if defined(RCC_APB2ENR_ADC2EN)
                e_Adc2      = RCC_APB2ENR_ADC2EN,
#endif
#if defined(RCC_APB2ENR_ADC3EN)
                e_Adc3      = RCC_APB2ENR_ADC3EN,
#endif
#if defined(RCC_APB2ENR_SDIOEN)
                e_Sdio      = RCC_APB2ENR_SDIOEN,
#endif
#if defined(RCC_APB2ENR_SPI1EN)
                e_SPI1      = RCC_APB2ENR_SPI1EN,
#endif
#if defined(RCC_APB2ENR_SYSCFGEN)
                e_SysCfg    = RCC_APB2ENR_SYSCFGEN,
#endif
#if defined(RCC_APB2ENR_TIM9EN)
                e_Tim9      = RCC_APB2ENR_TIM9EN,
#endif
#if defined(RCC_APB2ENR_TIM10EN)
                e_Tim10     = RCC_APB2ENR_TIM10EN,
#endif
#if defined(RCC_APB2ENR_TIM11EN)
                e_Tim11     = RCC_APB2ENR_TIM11EN,
#endif
            } FunctionAPB2_t;

            typedef enum FunctionAHB1_e {
#if defined(RCC_AHB1ENR_GPIOAEN)
                e_GPIOA         = RCC_AHB1ENR_GPIOAEN,
#endif
#if defined(RCC_AHB1ENR_GPIOBEN)
                e_GPIOB         = RCC_AHB1ENR_GPIOBEN,
#endif
#if defined(RCC_AHB1ENR_GPIOCEN)
                e_GPIOC         = RCC_AHB1ENR_GPIOCEN,
#endif
#if defined(RCC_AHB1ENR_GPIODEN)
                e_GPIOD         = RCC_AHB1ENR_GPIODEN,
#endif
#if defined(RCC_AHB1ENR_GPIOEEN)
                e_GPIOE         = RCC_AHB1ENR_GPIOEEN,
#endif
#if defined(RCC_AHB1ENR_GPIOFEN)
                e_GPIOF         = RCC_AHB1ENR_GPIOFEN,
#endif
#if defined(RCC_AHB1ENR_GPIOGEN)
                e_GPIOG         = RCC_AHB1ENR_GPIOGEN,
#endif
#if defined(RCC_AHB1ENR_GPIOHEN)
                e_GPIOH         = RCC_AHB1ENR_GPIOHEN,
#endif
#if defined(RCC_AHB1ENR_GPIOIEN)
                e_GPIOI         = RCC_AHB1ENR_GPIOIEN,
#endif
#if defined(RCC_AHB1ENR_CRCEN)
                e_Crc           = RCC_AHB1ENR_CRCEN,
#endif
#if defined(RCC_AHB1ENR_BKPSRAMEN)
                e_BackupSram    = RCC_AHB1ENR_BKPSRAMEN,
#endif
#if defined(RCC_AHB1ENR_CCMDATARAMEN)
                e_CcmDataRam    = RCC_AHB1ENR_CCMDATARAMEN,
#endif
#if defined(RCC_AHB1ENR_DMA1EN)
                e_DMA1          = RCC_AHB1ENR_DMA1EN,
#endif
#if defined(RCC_AHB1ENR_DMA2EN)
                e_DMA2          = RCC_AHB1ENR_DMA2EN,
#endif
#if defined(RCC_AHB1ENR_ETHMACEN)
                e_EthMac        = RCC_AHB1ENR_ETHMACEN,
#endif
#if defined(RCC_AHB1ENR_ETHMACTXEN)
                e_EthMacTx      = RCC_AHB1ENR_ETHMACTXEN,
#endif
#if defined(RCC_AHB1ENR_ETHMACRXEN)
                e_EthMacRx      = RCC_AHB1ENR_ETHMACRXEN,
#endif
#if defined(RCC_AHB1ENR_ETHMACPTPEN)
                e_EthMacPtp     = RCC_AHB1ENR_ETHMACPTPEN,
#endif
#if defined(RCC_AHB1ENR_OTGHSEN)
                e_USB_OTG_HS_PERIPH = RCC_AHB1ENR_OTGHSEN,
#endif
#if defined(RCC_AHB1ENR_OTGHSULPIEN)
                e_OtgHsUlpi     = RCC_AHB1ENR_OTGHSULPIEN,
#endif
            } FunctionAHB1_t;

            typedef enum FunctionAHB2_e {
#if defined(RCC_AHB2ENR_DCMIEN)
                e_DCMIEN    = RCC_AHB2ENR_DCMIEN,
#endif
#if defined(RCC_AHB2ENR_RNGEN)
                e_RNGEN     = RCC_AHB2ENR_RNGEN,
#endif
#if defined(RCC_AHB2ENR_OTGFSEN)
                e_USB_OTG_FS_PERIPH = RCC_AHB2ENR_OTGFSEN,
#endif
            } FunctionAHB2_t;

            typedef enum FunctionAHB3_e {
#if defined(RCC_AHB3ENR_FSMCEN)
                e_FSMCEN    = RCC_AHB3ENR_FSMCEN,
#endif
            } FunctionAHB3_t;

            RccT(RCC_TypeDef * const p_rcc, const PllCfg &p_pllCfg, const Flash &p_flash, const Pwr &p_pwr)
             : RccViaSTM32T< RccT< PllCfg, Flash, Pwr >, ::stm32::f4::Mco>(*p_rcc), m_pllCfg(p_pllCfg) {
                this->setupSafeMode();

                p_flash.setupLatency(p_pllCfg.getSysclkSpeedInHz());

                this->enableHSE(p_pllCfg.enableHSE());

                this->setupPLL(p_pllCfg);
                this->enablePLL(p_pllCfg.enablePLL());

                this->switchSysclk(p_pllCfg.getSysclkSource());

                this->setupFlash(p_flash);
                p_pwr.setupVoltageScaling();

                /* Turn off HSI, if not required */
                this->enableHSI(p_pllCfg.enableHSI());
            }

            void setupPLL(const PllCfg &p_pllCfg) const {
                this->m_rcc.PLLCFGR = p_pllCfg.getPllCfgReg();

                /*
                * Set up dividers for AHB, APB1 (low-speed peripheral) and APB2 (high
                * speed peripheral) busses.
                */
                this->m_rcc.CFGR &= ~(RCC_CFGR_HPRE_Msk | RCC_CFGR_PPRE1_Msk | RCC_CFGR_PPRE2_Msk);

                this->m_rcc.CFGR |= (p_pllCfg.m_ahbPrescaler << RCC_CFGR_HPRE_Pos) & RCC_CFGR_HPRE_Msk;
                this->m_rcc.CFGR |= (p_pllCfg.m_apb1Prescaler << RCC_CFGR_PPRE1_Pos) & RCC_CFGR_PPRE1_Msk;
                this->m_rcc.CFGR |= (p_pllCfg.m_apb2Prescaler << RCC_CFGR_PPRE2_Pos) & RCC_CFGR_PPRE2_Msk;
            }

            void enable(const FunctionAPB1_t p_function) const {
                this->m_rcc.APB1ENR |= p_function;
            }

            void disable(const FunctionAPB1_t p_function) const {
                this->m_rcc.APB1ENR &= ~p_function;
            }

            void enable(const FunctionAPB2_t p_function) const {
                this->m_rcc.APB2ENR |= p_function;
            }

            void disable(const FunctionAPB2_t p_function) const {
                this->m_rcc.APB2ENR &= ~p_function;
            }

            void enable(const FunctionAHB1_t p_function) const {
                this->m_rcc.AHB1ENR |= p_function;
            }

            void disable(const FunctionAHB1_t p_function) const {
                this->m_rcc.AHB1ENR &= ~p_function;
            }

            void enable(const FunctionAHB2_t p_function) const {
                this->m_rcc.AHB2ENR |= p_function;
            }

            void disable(const FunctionAHB2_t p_function) const {
                this->m_rcc.AHB2ENR &= ~p_function;
            }

            void enable(const FunctionAHB3_t p_function) const;
            void disable(const FunctionAHB3_t p_function) const;

            unsigned getClockSpeed(const FunctionAPB1_t /* p_function */) const {
                return this->m_pllCfg.getApb1SpeedInHz();
            }

            unsigned getClockSpeed(const FunctionAPB2_t /* p_function */) const {
                return this->m_pllCfg.getApb2SpeedInHz();
            }

        private:
            const PllCfg &  m_pllCfg;

            void setupSafeMode(void) const {
                /* Enable HSI and wait until it's ready */
                this->m_rcc.CR |= RCC_CR_HSION;
                while (!(this->m_rcc.CR & RCC_CR_HSIRDY)) ;

                /* Set up the internal oscillator as the system clock */
                this->m_rcc.CFGR &= ~RCC_CFGR_SW;
                while (this->m_rcc.CFGR & RCC_CFGR_SWS);

                /* Disable external Oscillator, the clock security system and the internal PLL */
                this->m_rcc.CR &= ~(RCC_CR_HSEON | RCC_CR_CSSON | RCC_CR_PLLON /* | RCC_CR_MSION */);
            }

            void setupFlash(const Flash &p_flash) const {
                p_flash.enableICache(true);
                p_flash.enableDCache(true);
                p_flash.enablePrefetch(true);
            }
        };
    } /* namespace f4 */
} /* namespace stm32 */

#endif /* _STM32F4_RCC_HPP_EC38BF53_FF32_450A_9BF6_45322EBBAC33 */
