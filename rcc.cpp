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
      break;
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
