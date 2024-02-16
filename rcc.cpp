#include "rcc.h"
#include <cstdint>
#include <cstddef>

namespace
{
  namespace Registers
  {
    namespace CR
    {
      namespace Position
      {
        constexpr uint32_t PLLSAIRDY = 29UL;
        constexpr uint32_t PLLSAION  = 28UL;
        constexpr uint32_t PLLI2SRDY = 27UL;
        constexpr uint32_t PLLI2SON  = 26UL;
        constexpr uint32_t PLLRDY    = 25UL;
        constexpr uint32_t PLLON     = 24UL;
        constexpr uint32_t CSSON     = 19UL;
        constexpr uint32_t HSEBYP    = 18UL;
        constexpr uint32_t HSERDY    = 17UL;
        constexpr uint32_t HSEON     = 16UL;
        constexpr uint32_t HSICAL    = 8UL;
        constexpr uint32_t HSITRIM   = 3UL;
        constexpr uint32_t HSIRDY    = 1UL;
        constexpr uint32_t HSION     = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t PLLSAIRDY = (1UL << Position::PLLSAIRDY);
        [[maybe_unused]] constexpr uint32_t PLLSAION  = (1UL << Position::PLLSAION);
        [[maybe_unused]] constexpr uint32_t PLLI2SRDY = (1UL << Position::PLLI2SRDY);
        [[maybe_unused]] constexpr uint32_t PLLI2SON  = (1UL << Position::PLLI2SON);
        [[maybe_unused]] constexpr uint32_t PLLRDY    = (1UL << Position::PLLRDY);
        [[maybe_unused]] constexpr uint32_t PLLON     = (1UL << Position::PLLON);
        [[maybe_unused]] constexpr uint32_t CSSON     = (1UL << Position::CSSON);
        [[maybe_unused]] constexpr uint32_t HSEBYP    = (1UL << Position::HSEBYP);
        [[maybe_unused]] constexpr uint32_t HSERDY    = (1UL << Position::HSERDY);
        [[maybe_unused]] constexpr uint32_t HSEON     = (1UL << Position::HSEON);
        [[maybe_unused]] constexpr uint32_t HSICAL    = (0xFFUL << Position::HSICAL);
        [[maybe_unused]] constexpr uint32_t HSITRIM   = (0x1FUL << Position::HSITRIM);
        [[maybe_unused]] constexpr uint32_t HSIRDY    = (1UL << Position::HSIRDY);
        [[maybe_unused]] constexpr uint32_t HSION     = (1UL << Position::HSION);
      }
    }
    
    namespace PLLCFGR
    {
      namespace Position
      {
        constexpr uint32_t PLLQ   = 24UL;
        constexpr uint32_t PLLSRC = 22UL;
        constexpr uint32_t PLLP   = 16UL;
        constexpr uint32_t PLLN   = 6UL;
        constexpr uint32_t PLLM   = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t PLLQ   = (0x0FUL << Position::PLLQ);
        [[maybe_unused]] constexpr uint32_t PLLSRC = (0x01UL << Position::PLLSRC);
        [[maybe_unused]] constexpr uint32_t PLLP   = (0x03UL << Position::PLLP);
        [[maybe_unused]] constexpr uint32_t PLLN   = (0x1FFUL << Position::PLLN);
        [[maybe_unused]] constexpr uint32_t PLLM   = (0x3FUL << Position::PLLM);
      }
    }
    
    namespace CFGR
    {
      namespace Position
      {
        constexpr uint32_t MCO2    = 30UL;
        constexpr uint32_t MCO2PRE = 27UL;
        constexpr uint32_t MCO1PRE = 24UL;
        constexpr uint32_t I2SSRC  = 23UL;
        constexpr uint32_t MCO1    = 21UL;
        constexpr uint32_t RTCPRE  = 16UL;
        constexpr uint32_t PPRE2   = 13UL;
        constexpr uint32_t PPRE1   = 10UL;
        constexpr uint32_t HPRE    = 4UL;
        constexpr uint32_t SWS     = 2UL;
        constexpr uint32_t SW      = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t MCO2    = (0x03UL << Position::MCO2);
        [[maybe_unused]] constexpr uint32_t MCO2PRE = (0x07UL << Position::MCO2PRE);
        [[maybe_unused]] constexpr uint32_t MCO1PRE = (0x07UL << Position::MCO1PRE);
        [[maybe_unused]] constexpr uint32_t I2SSRC  = (0x01UL << Position::I2SSRC);
        [[maybe_unused]] constexpr uint32_t MCO1    = (0x03UL << Position::MCO1);
        [[maybe_unused]] constexpr uint32_t RTCPRE  = (0x1FUL << Position::RTCPRE);
        [[maybe_unused]] constexpr uint32_t PPRE2   = (0x07UL << Position::PPRE2);
        [[maybe_unused]] constexpr uint32_t PPRE1   = (0x07UL << Position::PPRE1);
        [[maybe_unused]] constexpr uint32_t HPRE    = (0x0FUL << Position::HPRE);
        [[maybe_unused]] constexpr uint32_t SWS     = (0x03UL << Position::SWS);
        [[maybe_unused]] constexpr uint32_t SW      = (0x03UL << Position::SW);
      }
    }
    
    namespace AHB1ENR
    {
      namespace Position
      {
        constexpr uint32_t OTGHSEN   = 29UL;
        constexpr uint32_t DMA2EN    = 22UL;
        constexpr uint32_t DMA1EN    = 21UL;
        constexpr uint32_t DTCMRAMEN = 20UL;
        constexpr uint32_t BKPSRAMEN = 18UL;
        constexpr uint32_t CRCEN     = 12UL;
        constexpr uint32_t GPIOIEN   = 8UL;
        constexpr uint32_t GPIOHEN   = 7UL;
        constexpr uint32_t GPIOGEN   = 6UL;
        constexpr uint32_t GPIOFEN   = 5UL;
        constexpr uint32_t GPIOEEN   = 4UL;
        constexpr uint32_t GPIODEN   = 3UL;
        constexpr uint32_t GPIOCEN   = 2UL;
        constexpr uint32_t GPIOBEN   = 1UL;
        constexpr uint32_t GPIOAEN   = 0UL;
      }
      
       namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t OTGHSEN   = (1UL << Position::OTGHSEN);
        [[maybe_unused]] constexpr uint32_t DMA2EN    = (1UL << Position::DMA2EN);
        [[maybe_unused]] constexpr uint32_t DMA1EN    = (1UL << Position::DMA1EN);
        [[maybe_unused]] constexpr uint32_t DTCMRAMEN = (1UL << Position::DTCMRAMEN);
        [[maybe_unused]] constexpr uint32_t BKPSRAMEN = (1UL << Position::BKPSRAMEN);
        [[maybe_unused]] constexpr uint32_t CRCEN     = (1UL << Position::CRCEN);
        [[maybe_unused]] constexpr uint32_t GPIOIEN   = (1UL << Position::GPIOIEN);
        [[maybe_unused]] constexpr uint32_t GPIOHEN   = (1UL << Position::GPIOHEN);
        [[maybe_unused]] constexpr uint32_t GPIOGEN   = (1UL << Position::GPIOGEN);
        [[maybe_unused]] constexpr uint32_t GPIOFEN   = (1UL << Position::GPIOFEN);
        [[maybe_unused]] constexpr uint32_t GPIOEEN   = (1UL << Position::GPIOEEN);
        [[maybe_unused]] constexpr uint32_t GPIODEN   = (1UL << Position::GPIODEN);
        [[maybe_unused]] constexpr uint32_t GPIOCEN   = (1UL << Position::GPIOCEN);
        [[maybe_unused]] constexpr uint32_t GPIOBEN   = (1UL << Position::GPIOBEN);
        [[maybe_unused]] constexpr uint32_t GPIOAEN   = (1UL << Position::GPIOAEN);
      }
    }
    
    namespace AHB2ENR
    {
      namespace Position
      {
        constexpr uint32_t OTGFSEN = 7UL;
        constexpr uint32_t RNGEN   = 6UL;
        constexpr uint32_t AESEN   = 4UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t OTGFSEN = (1UL << Position::OTGFSEN);
        [[maybe_unused]] constexpr uint32_t RNGEN   = (1UL << Position::RNGEN);
        [[maybe_unused]] constexpr uint32_t AESEN   = (1UL << Position::AESEN);
      }
    }
    
    namespace AHB3ENR
    {
      namespace Position
      {
        constexpr uint32_t QSPIEN = 1UL;
        constexpr uint32_t FMCEN  = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t QSPIEN = (1UL << Position::QSPIEN);
        [[maybe_unused]] constexpr uint32_t FMCEN  = (1UL << Position::FMCEN);
      }
    }
    
    namespace APB1ENR
    {
      namespace Position
      {
        constexpr uint32_t UART8EN  = 31UL;
        constexpr uint32_t UART7EN  = 30UL;
        constexpr uint32_t DACEN    = 29UL;
        constexpr uint32_t PWREN    = 28UL;
        constexpr uint32_t CAN1EN   = 25UL;
        constexpr uint32_t I2C3EN   = 23UL;
        constexpr uint32_t I2C2EN   = 22UL;
        constexpr uint32_t I2C1EN   = 21UL;
        constexpr uint32_t UART5EN  = 20UL;
        constexpr uint32_t UART4EN  = 19UL;
        constexpr uint32_t USART3EN = 18UL;
        constexpr uint32_t USART2EN = 17UL;
        constexpr uint32_t SPI3EN   = 15UL;
        constexpr uint32_t SPI2EN   = 14UL;
        constexpr uint32_t WWDGEN   = 11UL;
        constexpr uint32_t RTCAPBEN = 10UL;
        constexpr uint32_t LPTIM1EN = 9UL;
        constexpr uint32_t TIM14EN  = 8UL;
        constexpr uint32_t TIM13EN  = 7UL;
        constexpr uint32_t TIM12EN  = 6UL;
        constexpr uint32_t TIM7EN   = 5UL;
        constexpr uint32_t TIM6EN   = 4UL;
        constexpr uint32_t TIM5EN   = 3UL;
        constexpr uint32_t TIM4EN   = 2UL;
        constexpr uint32_t TIM3EN   = 1UL;
        constexpr uint32_t TIM2EN   = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t UART8EN  = (1UL << Position::UART8EN);
        [[maybe_unused]] constexpr uint32_t UART7EN  = (1UL << Position::UART7EN);
        [[maybe_unused]] constexpr uint32_t DACEN    = (1UL << Position::DACEN);
        [[maybe_unused]] constexpr uint32_t PWREN    = (1UL << Position::PWREN);
        [[maybe_unused]] constexpr uint32_t CAN1EN   = (1UL << Position::CAN1EN);
        [[maybe_unused]] constexpr uint32_t I2C3EN   = (1UL << Position::I2C3EN);
        [[maybe_unused]] constexpr uint32_t I2C2EN   = (1UL << Position::I2C2EN);
        [[maybe_unused]] constexpr uint32_t I2C1EN   = (1UL << Position::I2C1EN);
        [[maybe_unused]] constexpr uint32_t UART5EN  = (1UL << Position::UART5EN);
        [[maybe_unused]] constexpr uint32_t UART4EN  = (1UL << Position::UART4EN);
        [[maybe_unused]] constexpr uint32_t USART3EN = (1UL << Position::USART3EN);
        [[maybe_unused]] constexpr uint32_t USART2EN = (1UL << Position::USART2EN);
        [[maybe_unused]] constexpr uint32_t SPI3EN   = (1UL << Position::SPI3EN);
        [[maybe_unused]] constexpr uint32_t SPI2EN   = (1UL << Position::SPI2EN);
        [[maybe_unused]] constexpr uint32_t WWDGEN   = (1UL << Position::WWDGEN);
        [[maybe_unused]] constexpr uint32_t RTCAPBEN = (1UL << Position::RTCAPBEN);
        [[maybe_unused]] constexpr uint32_t LPTIM1EN = (1UL << Position::LPTIM1EN);
        [[maybe_unused]] constexpr uint32_t TIM14EN  = (1UL << Position::TIM14EN);
        [[maybe_unused]] constexpr uint32_t TIM13EN  = (1UL << Position::TIM13EN);
        [[maybe_unused]] constexpr uint32_t TIM12EN  = (1UL << Position::TIM12EN);
        [[maybe_unused]] constexpr uint32_t TIM7EN   = (1UL << Position::TIM7EN);
        [[maybe_unused]] constexpr uint32_t TIM6EN   = (1UL << Position::TIM6EN);
        [[maybe_unused]] constexpr uint32_t TIM5EN   = (1UL << Position::TIM5EN);
        [[maybe_unused]] constexpr uint32_t TIM4EN   = (1UL << Position::TIM4EN);
        [[maybe_unused]] constexpr uint32_t TIM3EN   = (1UL << Position::TIM3EN);
        [[maybe_unused]] constexpr uint32_t TIM2EN   = (1UL << Position::TIM2EN);
      }
    }
    
    namespace APB2ENR
    {
      namespace Position
      {
        constexpr uint32_t OTGPHYCEN = 31UL;
        constexpr uint32_t SAI2EN    = 23UL;
        constexpr uint32_t SAI1EN    = 22UL;
        constexpr uint32_t SPI5EN    = 20UL;
        constexpr uint32_t TIM11EN   = 18UL;
        constexpr uint32_t TIM10EN   = 17UL;
        constexpr uint32_t TIM9EN    = 16UL;
        constexpr uint32_t SYSCFGEN  = 14UL;
        constexpr uint32_t SPI4EN    = 13UL;
        constexpr uint32_t SPI1EN    = 12UL;
        constexpr uint32_t SDMMC1EN  = 11UL;
        constexpr uint32_t ADC3EN    = 10UL;
        constexpr uint32_t ADC2EN    = 9UL;
        constexpr uint32_t ADC1EN    = 8UL;
        constexpr uint32_t SDMMC2EN  = 7UL;
        constexpr uint32_t USART6EN  = 5UL;
        constexpr uint32_t USART1EN  = 4UL;
        constexpr uint32_t TIM8EN    = 1UL;
        constexpr uint32_t TIM1EN    = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t OTGPHYCEN = (1UL << Position::OTGPHYCEN);
        [[maybe_unused]] constexpr uint32_t SAI2EN    = (1UL << Position::SAI2EN);
        [[maybe_unused]] constexpr uint32_t SAI1EN    = (1UL << Position::SAI1EN);
        [[maybe_unused]] constexpr uint32_t SPI5EN    = (1UL << Position::SPI5EN);
        [[maybe_unused]] constexpr uint32_t TIM11EN   = (1UL << Position::TIM11EN);
        [[maybe_unused]] constexpr uint32_t TIM10EN   = (1UL << Position::TIM10EN);
        [[maybe_unused]] constexpr uint32_t TIM9EN    = (1UL << Position::TIM9EN);
        [[maybe_unused]] constexpr uint32_t SYSCFGEN  = (1UL << Position::SYSCFGEN);
        [[maybe_unused]] constexpr uint32_t SPI4EN    = (1UL << Position::SPI4EN);
        [[maybe_unused]] constexpr uint32_t SPI1EN    = (1UL << Position::SPI1EN);
        [[maybe_unused]] constexpr uint32_t SDMMC1EN  = (1UL << Position::SDMMC1EN);
        [[maybe_unused]] constexpr uint32_t ADC3EN    = (1UL << Position::ADC3EN);
        [[maybe_unused]] constexpr uint32_t ADC2EN    = (1UL << Position::ADC2EN);
        [[maybe_unused]] constexpr uint32_t ADC1EN    = (1UL << Position::ADC1EN);
        [[maybe_unused]] constexpr uint32_t SDMMC2EN  = (1UL << Position::SDMMC2EN);
        [[maybe_unused]] constexpr uint32_t USART6EN  = (1UL << Position::USART6EN);
        [[maybe_unused]] constexpr uint32_t USART1EN  = (1UL << Position::USART1EN);
        [[maybe_unused]] constexpr uint32_t TIM8EN    = (1UL << Position::TIM8EN);
        [[maybe_unused]] constexpr uint32_t TIM1EN    = (1UL << Position::TIM1EN);
      }
    }
    
    namespace PLLSAICFGR
    {
      namespace Position
      {
        constexpr uint32_t PLLSAIQ = 24UL;
        constexpr uint32_t PLLSAIP = 16UL;
        constexpr uint32_t PLLSAIN = 6UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t PLLSAIQ = (0x0FUL << Position::PLLSAIQ);
        [[maybe_unused]] constexpr uint32_t PLLSAIP = (0x03UL << Position::PLLSAIP);
        [[maybe_unused]] constexpr uint32_t PLLSAIN = (0x1FFUL << Position::PLLSAIN);
      }
    }
    
    namespace DKCFGR1
    {
      namespace Position
      {
        constexpr uint32_t TIMPRE     = 24UL;
        constexpr uint32_t SAI2SEL    = 22UL;
        constexpr uint32_t SAI1SEL    = 20UL;
        constexpr uint32_t PLLSAIDIVQ = 8UL;
        constexpr uint32_t PLLI2SDIVQ = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t TIMPRE     = (0x01UL << Position::TIMPRE);
        [[maybe_unused]] constexpr uint32_t SAI2SEL    = (0x03UL << Position::SAI2SEL);
        [[maybe_unused]] constexpr uint32_t SAI1SEL    = (0x03UL << Position::SAI1SEL);
        [[maybe_unused]] constexpr uint32_t PLLSAIDIVQ = (0x1FUL << Position::PLLSAIDIVQ);
        [[maybe_unused]] constexpr uint32_t PLLI2SDIVQ = (0x1FUL << Position::PLLI2SDIVQ);
      }
    }
  }
  
  struct RCCRegisters
  {
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    volatile uint32_t AHB3RSTR;
    uint32_t unused;
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    uint32_t unused2[2];
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;
    uint32_t unused3;
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
    uint32_t unused4[2];
    volatile uint32_t AHB1LPENR;
    volatile uint32_t AHB2LPENR;
    volatile uint32_t AHB3LPENR;
    uint32_t unused5;
    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR;
    uint32_t unused6[2];
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    uint32_t unused7[2];
    volatile uint32_t SSCGR;
    volatile uint32_t PLLI2SCFGR;
    volatile uint32_t PLLSAICFGR;
    volatile uint32_t DCKCFGR1;
    volatile uint32_t DCKCFGR2;    
  };
  
  static_assert(0x00 == offsetof(RCCRegisters, CR));
  static_assert(0x04 == offsetof(RCCRegisters, PLLCFGR));
  static_assert(0x08 == offsetof(RCCRegisters, CFGR));
  static_assert(0x0C == offsetof(RCCRegisters, CIR));
  static_assert(0x10 == offsetof(RCCRegisters, AHB1RSTR));
  static_assert(0x14 == offsetof(RCCRegisters, AHB2RSTR));
  static_assert(0x18 == offsetof(RCCRegisters, AHB3RSTR));
  static_assert(0x20 == offsetof(RCCRegisters, APB1RSTR));
  static_assert(0x24 == offsetof(RCCRegisters, APB2RSTR));
  static_assert(0x30 == offsetof(RCCRegisters, AHB1ENR));
  static_assert(0x34 == offsetof(RCCRegisters, AHB2ENR));
  static_assert(0x38 == offsetof(RCCRegisters, AHB3ENR));
  static_assert(0x40 == offsetof(RCCRegisters, APB1ENR));
  static_assert(0x44 == offsetof(RCCRegisters, APB2ENR));
  static_assert(0x50 == offsetof(RCCRegisters, AHB1LPENR));
  static_assert(0x54 == offsetof(RCCRegisters, AHB2LPENR));
  static_assert(0x58 == offsetof(RCCRegisters, AHB3LPENR));
  static_assert(0x60 == offsetof(RCCRegisters, APB1LPENR));
  static_assert(0x64 == offsetof(RCCRegisters, APB2LPENR));
  static_assert(0x70 == offsetof(RCCRegisters, BDCR));
  static_assert(0x74 == offsetof(RCCRegisters, CSR));
  static_assert(0x80 == offsetof(RCCRegisters, SSCGR));
  static_assert(0x84 == offsetof(RCCRegisters, PLLI2SCFGR));
  static_assert(0x88 == offsetof(RCCRegisters, PLLSAICFGR));
  static_assert(0x8C == offsetof(RCCRegisters, DCKCFGR1));
  static_assert(0x90 == offsetof(RCCRegisters, DCKCFGR2));
  
  constexpr uint32_t RCCBaseAddress = 0x40023800UL;
  RCCRegisters * const Interface = reinterpret_cast<RCCRegisters *>(RCCBaseAddress);
}

void RCC::DisableHSI()
{
  uint32_t cr = Interface->CR;
  cr &= ~Registers::CR::Mask::HSION;
  Interface->CR = cr;
}

void RCC::EnableHSE(bool bypass)
{
  uint32_t cr = Interface->CR;
  cr |= Registers::CR::Mask::HSEON;
  
  if(true == bypass)
  {
    cr |= Registers::CR::Mask::HSEBYP;
  }
  
  Interface->CR = cr;
  
  while(Registers::CR::Mask::HSERDY != (Interface->CR & Registers::CR::Mask::HSERDY));  
}

void RCC::EnablePLL()
{
  Interface->CR |= Registers::CR::Mask::PLLON;
}

bool RCC::PLLReady()
{
  return (Registers::CR::Mask::PLLRDY == (Interface->CR & Registers::CR::Mask::PLLRDY));
}

void RCC::SetClockSource(SystemClockSource clockSource)
{
  uint32_t cfgr = Interface->CFGR;
  
  cfgr &= ~Registers::CFGR::Mask::SW;
  uint32_t readyMask{0UL};
  
  switch(clockSource)
  {
    case SystemClockSource::HSIOscillator:
      // 00 - already cleared
      break;
    case SystemClockSource::HSEOscillator:
      cfgr |= 0x01UL << Registers::CFGR::Position::SW;
      readyMask = 0x01UL << Registers::CFGR::Position::SWS;
      break;
    case SystemClockSource::PLL:
      cfgr |= 0x02UL << Registers::CFGR::Position::SW;
      readyMask = 0x02UL << Registers::CFGR::Position::SWS;
      break;
  }
  
  Interface->CFGR = cfgr;
  
  while(readyMask != (Interface->CFGR & readyMask));
}
  
void RCC::ConfigurePLL(uint32_t PLLQ, uint32_t PLLP, uint32_t PLLN, uint32_t PLLM, PLLClockSource clockSource)
{
  uint32_t pllcfgr = (PLLQ << Registers::PLLCFGR::Position::PLLQ) |
                     (PLLN << Registers::PLLCFGR::Position::PLLN) |
                     (PLLM << Registers::PLLCFGR::Position::PLLM);
  
  switch(PLLP)
  {
    case 2:
      // 00 nothing to do
      break;
    case 4:
      pllcfgr |= (0x01UL << Registers::PLLCFGR::Position::PLLP);
      break;
    case 6:
      pllcfgr |= (0x02UL << Registers::PLLCFGR::Position::PLLP);
      break;
    case 8:
      pllcfgr |= (0x03UL << Registers::PLLCFGR::Position::PLLP);
      break;
    default:
      while(1); //todo assert
//      break;
  }
  
  if(PLLClockSource::HSEOscillator == clockSource)
  {
    pllcfgr |= Registers::PLLCFGR::Mask::PLLSRC;
  }
  
  Interface->PLLCFGR = pllcfgr;
}
  
void RCC::ConfigureBusDividers(APBDivider apb1Divider, APBDivider apb2Divider, AHBDivider ahbDivider)
{
  constexpr uint32_t clearMask = Registers::CFGR::Mask::PPRE2 |
                                 Registers::CFGR::Mask::PPRE1 |
                                 Registers::CFGR::Mask::HPRE;
  
  uint32_t cfgr = Interface->CFGR;
  cfgr &= ~clearMask;
  
  switch(apb1Divider)
  {
    case APBDivider::AHBClockDiv1:
      // 000 - nothing needed
      break;      
    case APBDivider::AHBClockDiv2:
      cfgr |= (0x04UL << Registers::CFGR::Position::PPRE1);
      break;
    case APBDivider::AHBClockDiv4:
      cfgr |= (0x05UL << Registers::CFGR::Position::PPRE1);
      break;
    case APBDivider::AHBClockDiv8:
      cfgr |= (0x06UL << Registers::CFGR::Position::PPRE1);
      break;
    case APBDivider::AHBClockDiv16:
      cfgr |= (0x07UL << Registers::CFGR::Position::PPRE1);
      break;
  }
  
  switch(apb2Divider)
  {
    case APBDivider::AHBClockDiv1:
      // 000 - nothing needed
      break;      
    case APBDivider::AHBClockDiv2:
      cfgr |= (0x04UL << Registers::CFGR::Position::PPRE2);
      break;
    case APBDivider::AHBClockDiv4:
      cfgr |= (0x05UL << Registers::CFGR::Position::PPRE2);
      break;
    case APBDivider::AHBClockDiv8:
      cfgr |= (0x06UL << Registers::CFGR::Position::PPRE2);
      break;
    case APBDivider::AHBClockDiv16:
      cfgr |= (0x07UL << Registers::CFGR::Position::PPRE2);
      break;
  }
  
  switch(ahbDivider)
  {
    case AHBDivider::SystemClockDiv1:
      // 0000 - nothing needed
      break;
    case AHBDivider::SystemClockDiv2:
      cfgr |= (0x08UL << Registers::CFGR::Position::HPRE);
      break;
    case AHBDivider::SystemClockDiv4:
      cfgr |= (0x09UL << Registers::CFGR::Position::HPRE);
      break;
    case AHBDivider::SystemClockDiv8:
      cfgr |= (0x0AUL << Registers::CFGR::Position::HPRE);
      break;
    case AHBDivider::SystemClockDiv16:
      cfgr |= (0x0BUL << Registers::CFGR::Position::HPRE);
      break;
    case AHBDivider::SystemClockDiv64:
      cfgr |= (0x0CUL << Registers::CFGR::Position::HPRE);
      break;
    case AHBDivider::SystemClockDiv128:
      cfgr |= (0x0DUL << Registers::CFGR::Position::HPRE);
      break;
    case AHBDivider::SystemClockDiv256:
      cfgr |= (0x0EUL << Registers::CFGR::Position::HPRE);
      break;
    case AHBDivider::SystemClockDiv512:
      cfgr |= (0x0FUL << Registers::CFGR::Position::HPRE);
      break;
  }
  
  Interface->CFGR = cfgr;
}

void RCC::EnablePeripheralClock(Peripheral peripheral)
{
  switch(peripheral)
  {
    case Peripheral::OTGHS:
      Interface->AHB1ENR |= Registers::AHB1ENR::Mask::OTGHSEN;
      break;
    case Peripheral::DMA2:
      Interface->AHB1ENR |= Registers::AHB1ENR::Mask::DMA2EN;
      break;
    case Peripheral::DMA1:
      Interface->AHB1ENR |= Registers::AHB1ENR::Mask::DMA1EN;
      break;
    case Peripheral::DTCMRAM:
      Interface->AHB1ENR |= Registers::AHB1ENR::Mask::DTCMRAMEN;
      break;
    case Peripheral::BKPSRAMEN:
      Interface->AHB1ENR |= Registers::AHB1ENR::Mask::BKPSRAMEN;
      break;
    case Peripheral::CRC:
      Interface->AHB1ENR |= Registers::AHB1ENR::Mask::CRCEN;
      break;
    case Peripheral::GPIOI:
      Interface->AHB1ENR |= Registers::AHB1ENR::Mask::GPIOIEN;
      break;
    case Peripheral::GPIOH:
      Interface->AHB1ENR |= Registers::AHB1ENR::Mask::GPIOHEN;
      break;
    case Peripheral::GPIOG:
      Interface->AHB1ENR |= Registers::AHB1ENR::Mask::GPIOGEN;
      break;
    case Peripheral::GPIOF:
      Interface->AHB1ENR |= Registers::AHB1ENR::Mask::GPIOFEN;
      break;
    case Peripheral::GPIOE:
      Interface->AHB1ENR |= Registers::AHB1ENR::Mask::GPIOEEN;
      break;
    case Peripheral::GPIOD:
      Interface->AHB1ENR |= Registers::AHB1ENR::Mask::GPIODEN;
      break;
    case Peripheral::GPIOC:
      Interface->AHB1ENR |= Registers::AHB1ENR::Mask::GPIOCEN;
      break;
    case Peripheral::GPIOB:
      Interface->AHB1ENR |= Registers::AHB1ENR::Mask::GPIOBEN;
      break;
    case Peripheral::GPIOA:
      Interface->AHB1ENR |= Registers::AHB1ENR::Mask::GPIOAEN;
      break;
    case Peripheral::OTGFS:
      Interface->AHB2ENR |= Registers::AHB2ENR::Mask::OTGFSEN;
      break;
    case Peripheral::RNG:
      Interface->AHB2ENR |= Registers::AHB2ENR::Mask::RNGEN;
      break;
    case Peripheral::AES:
      Interface->AHB2ENR |= Registers::AHB2ENR::Mask::AESEN;
      break;
    case Peripheral::QSPI:
      Interface->AHB3ENR |= Registers::AHB3ENR::Mask::QSPIEN;
      break;
    case Peripheral::FMC:
      Interface->AHB3ENR |= Registers::AHB3ENR::Mask::FMCEN;
      break;
    case Peripheral::UART8:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::UART8EN;
      break;
    case Peripheral::UART7:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::UART7EN;
      break;
    case Peripheral::DAC:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::DACEN;
      break;
    case Peripheral::PWR:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::PWREN;
      break;
    case Peripheral::CAN1:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::CAN1EN;
      break;
    case Peripheral::I2C3:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::I2C3EN;
      break;
    case Peripheral::I2C2:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::I2C2EN;
      break;
    case Peripheral::I2C1:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::I2C1EN;
      break;
    case Peripheral::UART5:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::UART5EN;
      break;
    case Peripheral::UART4:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::UART4EN;
      break;
    case Peripheral::USART3:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::USART3EN;
      break;
    case Peripheral::USART2:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::USART2EN;
      break;
    case Peripheral::SPI3:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::SPI3EN;
      break;
    case Peripheral::SPI2:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::SPI2EN;
      break;
    case Peripheral::WWDG:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::WWDGEN;
      break;
    case Peripheral::RTCAPB:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::RTCAPBEN;
      break;
    case Peripheral::LPTIM1:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::LPTIM1EN;
      break;
    case Peripheral::TIM14:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::TIM14EN;
      break;
    case Peripheral::TIM13:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::TIM13EN;
      break;
    case Peripheral::TIM12:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::TIM12EN;
      break;
    case Peripheral::TIM7:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::TIM7EN;
      break;
    case Peripheral::TIM6:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::TIM6EN;
      break;
    case Peripheral::TIM5:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::TIM5EN;
      break;
    case Peripheral::TIM4:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::TIM4EN;
      break;
    case Peripheral::TIM3:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::TIM3EN;
      break;
    case Peripheral::TIM2:
      Interface->APB1ENR |= Registers::APB1ENR::Mask::TIM2EN;
      break;
    case Peripheral::OTGPHYC:
      Interface->APB2ENR |= Registers::APB2ENR::Mask::OTGPHYCEN;
      break;
    case Peripheral::SAI2:
      Interface->APB2ENR |= Registers::APB2ENR::Mask::SAI2EN;
      break;
    case Peripheral::SAI1:
      Interface->APB2ENR |= Registers::APB2ENR::Mask::SAI1EN;
      break;
    case Peripheral::SPI5EN:
      Interface->APB2ENR |= Registers::APB2ENR::Mask::SPI5EN;
      break;
    case Peripheral::TIM11:
      Interface->APB2ENR |= Registers::APB2ENR::Mask::TIM11EN;
      break;
    case Peripheral::TIM10:
      Interface->APB2ENR |= Registers::APB2ENR::Mask::TIM10EN;
      break;
    case Peripheral::TIM9:
      Interface->APB2ENR |= Registers::APB2ENR::Mask::TIM9EN;
      break;
    case Peripheral::SYSCFG:
      Interface->APB2ENR |= Registers::APB2ENR::Mask::SYSCFGEN;
      break;
    case Peripheral::SPI4:
      Interface->APB2ENR |= Registers::APB2ENR::Mask::SPI4EN;
      break;
    case Peripheral::SPI1:
      Interface->APB2ENR |= Registers::APB2ENR::Mask::SPI1EN;
      break;
    case Peripheral::SDMMC1:
      Interface->APB2ENR |= Registers::APB2ENR::Mask::SDMMC1EN;
      break;
    case Peripheral::ADC3:
      Interface->APB2ENR |= Registers::APB2ENR::Mask::ADC3EN;
      break;
    case Peripheral::ADC2:
      Interface->APB2ENR |= Registers::APB2ENR::Mask::ADC2EN;
      break;
    case Peripheral::ADC1:
      Interface->APB2ENR |= Registers::APB2ENR::Mask::ADC1EN;
      break;
    case Peripheral::SDMMC2:
      Interface->APB2ENR |= Registers::APB2ENR::Mask::SDMMC2EN;
      break;
    case Peripheral::USART6:
      Interface->APB2ENR |= Registers::APB2ENR::Mask::USART6EN;
      break;
    case Peripheral::USART1:
      Interface->APB2ENR |= Registers::APB2ENR::Mask::USART1EN;
      break;
    case Peripheral::TIM8:
      Interface->APB2ENR |= Registers::APB2ENR::Mask::TIM8EN;
      break;
    case Peripheral::TIM1:
      Interface->APB2ENR |= Registers::APB2ENR::Mask::TIM1EN;
      break;
  }
  
  //delay a couple of clock cycles
  asm("isb");
  asm("dmb");
}

void RCC::EnableSAIPLL()
{
  Interface->CR |= Registers::CR::Mask::PLLSAION;
}

bool RCC::SAIPLLReady()
{
  return Registers::CR::Mask::PLLSAIRDY == (Interface->CR & Registers::CR::Mask::PLLSAIRDY);
}

void RCC::ConfigureSAIPLL(uint32_t PLLQ, uint32_t PLLP, uint32_t PLLN, uint32_t DIVQ)
{
  PLLQ <<= Registers::PLLSAICFGR::Position::PLLSAIQ;
  PLLP <<= Registers::PLLSAICFGR::Position::PLLSAIP;
  PLLN <<= Registers::PLLSAICFGR::Position::PLLSAIN;
  
  const uint32_t pllsaicfgr = PLLQ | PLLP | PLLN;
  
  constexpr uint32_t mask = Registers::PLLSAICFGR::Mask::PLLSAIQ | 
                            Registers::PLLSAICFGR::Mask::PLLSAIP |
                            Registers::PLLSAICFGR::Mask::PLLSAIN;
  
  Interface->PLLSAICFGR = (pllsaicfgr & mask);
  
  
  DIVQ <<= Registers::DKCFGR1::Position::PLLSAIDIVQ;
  DIVQ &= Registers::DKCFGR1::Mask::PLLSAIDIVQ;
  
  uint32_t dckcfgr1 = Interface->DCKCFGR1;
  dckcfgr1 &= ~Registers::DKCFGR1::Mask::PLLSAIDIVQ;
  dckcfgr1 |= DIVQ;
  Interface->DCKCFGR1 = dckcfgr1;
}

void RCC::SetSAIClockSource(SAIInstance instance, SAIClockSource clockSource)
{
  uint32_t clockSourceBits{0UL};
  
  switch(clockSource)
  {
    case SAIClockSource::PLLSAI:
      clockSourceBits = 0x00UL;
      break;
    case SAIClockSource::PLLI2S:
      clockSourceBits = 0x01UL;
      break;
    case SAIClockSource::AlternateFunctionInput:
      clockSourceBits = 0x02UL;
      break;
  }
  
  uint32_t dckcfgr1 = Interface->DCKCFGR1;
  if(SAIInstance::SAI1 == instance)
  {
    
    dckcfgr1 &= ~Registers::DKCFGR1::Mask::SAI1SEL;
    clockSourceBits <<= Registers::DKCFGR1::Position::SAI1SEL;
  }
  else
  {
    dckcfgr1 &= ~Registers::DKCFGR1::Mask::SAI2SEL;
    clockSourceBits <<= Registers::DKCFGR1::Position::SAI2SEL;
  }
  dckcfgr1 |= clockSourceBits;
  Interface->DCKCFGR1 = dckcfgr1;
}
