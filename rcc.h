#ifndef rcc_h
#define rcc_h

#include <cstdint>

class RCC
{
public:
  enum class SystemClockSource
  {
    HSIOscillator,
    HSEOscillator,
    PLL
  };
  
  enum class PLLClockSource
  {
    HSIOscillator,
    HSEOscillator
  };
  
  enum class APBDivider
  {
    AHBClockDiv1,
    AHBClockDiv2,
    AHBClockDiv4,
    AHBClockDiv8,
    AHBClockDiv16
  };
  
  enum class AHBDivider
  {
    SystemClockDiv1,
    SystemClockDiv2,
    SystemClockDiv4,
    SystemClockDiv8,
    SystemClockDiv16,
    SystemClockDiv64,
    SystemClockDiv128,
    SystemClockDiv256,
    SystemClockDiv512
  };
  
  enum class Peripheral
  {
    OTGHS,
    DMA2,
    DMA1,
    DTCMRAM,
    BKPSRAMEN,
    CRC,
    GPIOI,
    GPIOH,
    GPIOG,
    GPIOF,
    GPIOE,
    GPIOD,
    GPIOC,
    GPIOB,
    GPIOA,
    OTGFS,
    RNG,
    AES,
    QSPI,
    FMC,
    UART8,
    UART7,
    DAC,
    PWR,
    CAN1,
    I2C3,
    I2C2,
    I2C1,
    UART5,
    UART4,
    USART3,
    USART2,
    SPI3,
    SPI2,
    WWDG,
    RTCAPB,
    LPTIM1,
    TIM14,
    TIM13,
    TIM12,
    TIM7,
    TIM6,
    TIM5,
    TIM4,
    TIM3,
    TIM2,
    OTGPHYC,
    SAI2,
    SAI1,
    SPI5EN,
    TIM11,
    TIM10,
    TIM9,
    SYSCFG,
    SPI4,
    SPI1,
    SDMMC1,
    ADC3,
    ADC2,
    ADC1,
    SDMMC2,
    USART6,
    USART1,
    TIM8,
    TIM1
  };
  
  enum class SAIInstance 
  {
    SAI1,
    SAI2
  };
  
  enum class SAIClockSource
  {
    PLLSAI,
    PLLI2S,
    AlternateFunctionInput
  };

  static void DisableHSI();
  static void EnableHSE(bool bypass);
  static void EnablePLL();
  static bool PLLReady();
  static void EnableSAIPLL();
  static bool SAIPLLReady();
  static void SetClockSource(SystemClockSource clockSource);
  static void ConfigurePLL(uint32_t PLLQ, uint32_t PLLP, uint32_t PLLN, uint32_t PLLM, PLLClockSource clockSource);
  static void ConfigureSAIPLL(uint32_t PLLQ, uint32_t PLLP, uint32_t PLLN, uint32_t DIVQ);
  static void ConfigureBusDividers(APBDivider apb1Divider, APBDivider apb2Divider, AHBDivider ahbDivider);
  static void EnablePeripheralClock(Peripheral peripheral);
  static void SetSAIClockSource(SAIInstance instance, SAIClockSource clockSource);
};
#endif
