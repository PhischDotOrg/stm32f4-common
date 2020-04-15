set(OPENOCD_BOARD_CFG       "stm32f4discovery.cfg")
set(STM32F4_STARTUP_CODE    "boards/STM32F4_Discovery/startup_stm32f407xx.S")
set(STM32F4_LDSCRIPT        "boards/STM32F4_Discovery/STM32F407VGTx_FLASH.ld")

# Used to select include directory for CPU-/Board-specific Headers in common/contrib/STM32F4.cmake
set(STM32F4_CPU_TYPE        "STM32F407xE")

add_definitions("-DSTM32F407xx")
add_definitions("-DHSE_VALUE=((uint32_t)8000000)")
add_definitions("-DHSI_VALUE=((uint32_t)16000000)")