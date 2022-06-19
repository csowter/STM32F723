#include "pwr.h"
#include <cstdint>
#include <cstddef>

namespace
{
  namespace Registers
  {
    namespace CR1
    {
      namespace Position
      {
        constexpr uint32_t UDEN   = 18UL;
        constexpr uint32_t ODSWEN = 17UL;
        constexpr uint32_t ODEN   = 16UL;
        constexpr uint32_t VOS    = 14UL;
        constexpr uint32_t ADCDC1 = 13UL;
        constexpr uint32_t MRUDS  = 11UL;
        constexpr uint32_t LPUDS  = 10UL;
        constexpr uint32_t FPDS   = 9UL;
        constexpr uint32_t DBP    = 8UL;
        constexpr uint32_t PLS    = 5UL;
        constexpr uint32_t PVDE   = 4UL;
        constexpr uint32_t CSBF   = 3UL;
        constexpr uint32_t PDDS   = 1UL;
        constexpr uint32_t LPDS   = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t UDEN   = (3UL << Position::UDEN);
        [[maybe_unused]] constexpr uint32_t ODSWEN = (1UL << Position::ODSWEN);
        [[maybe_unused]] constexpr uint32_t ODEN   = (1UL << Position::ODEN);
        [[maybe_unused]] constexpr uint32_t VOS    = (3UL << Position::VOS);
        [[maybe_unused]] constexpr uint32_t ADCDC1 = (1UL << Position::ADCDC1);
        [[maybe_unused]] constexpr uint32_t MRUDS  = (1UL << Position::MRUDS);
        [[maybe_unused]] constexpr uint32_t LPUDS  = (1UL << Position::LPUDS);
        [[maybe_unused]] constexpr uint32_t FPDS   = (1UL << Position::FPDS);
        [[maybe_unused]] constexpr uint32_t DBP    = (1UL << Position::DBP);
        [[maybe_unused]] constexpr uint32_t PLS    = (7UL << Position::PLS);
        [[maybe_unused]] constexpr uint32_t PVDE   = (1UL << Position::PVDE);
        [[maybe_unused]] constexpr uint32_t CSBF   = (1UL << Position::CSBF);
        [[maybe_unused]] constexpr uint32_t PDDS   = (1UL << Position::PDDS);
        [[maybe_unused]] constexpr uint32_t LPDS   = (1UL << Position::LPDS);
      }
    }
    
    namespace CSR1
    {
      namespace Position
      {
        constexpr uint32_t UDRDY   = 18UL;
        constexpr uint32_t ODSWRDY = 17UL;
        constexpr uint32_t ODRDY   = 16UL;
        constexpr uint32_t VOSRDY  = 14UL;
        constexpr uint32_t BRE     = 9UL;
        constexpr uint32_t EIWUP   = 8UL;
        constexpr uint32_t BRR     = 3UL;
        constexpr uint32_t PVDO    = 2UL;
        constexpr uint32_t SBF     = 1UL;
        constexpr uint32_t WUIF    = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t UDRDY   = (3UL << Position::UDRDY);
        [[maybe_unused]] constexpr uint32_t ODSWRDY = (1UL << Position::ODSWRDY);
        [[maybe_unused]] constexpr uint32_t ODRDY   = (1UL << Position::ODRDY);
        [[maybe_unused]] constexpr uint32_t VOSRDY  = (1UL << Position::VOSRDY);
        [[maybe_unused]] constexpr uint32_t BRE     = (1UL << Position::BRE);
        [[maybe_unused]] constexpr uint32_t EIWUP   = (1UL << Position::EIWUP);
        [[maybe_unused]] constexpr uint32_t BRR     = (1UL << Position::BRR);
        [[maybe_unused]] constexpr uint32_t PVDO    = (1UL << Position::PVDO);
        [[maybe_unused]] constexpr uint32_t SBF     = (1UL << Position::SBF);
        [[maybe_unused]] constexpr uint32_t WUIF    = (1UL << Position::WUIF);
      }
    }
  }
  struct PWRRegisters
  {
    volatile uint32_t CR1;
    volatile uint32_t CSR1;
    volatile uint32_t CR2;
    volatile uint32_t CSR2;
  };
  
  static_assert(0x00 == offsetof(PWRRegisters, CR1));
  static_assert(0x04 == offsetof(PWRRegisters, CSR1));
  static_assert(0x08 == offsetof(PWRRegisters, CR2));
  static_assert(0x0C == offsetof(PWRRegisters, CSR2));
  
  constexpr uint32_t PWRBaseAddress = 0x40007000UL;
  PWRRegisters *Interface = reinterpret_cast<PWRRegisters *>(PWRBaseAddress);
}

void PWR::EnableOverdrive()
{
  Interface->CR1 |= Registers::CR1::Mask::ODEN;
  while(Registers::CSR1::Mask::ODRDY != (Interface->CSR1 & Registers::CSR1::Mask::ODRDY)); //todo timeout
  
  Interface->CR1 |= Registers::CR1::Mask::ODSWEN;
  while(Registers::CSR1::Mask::ODSWRDY != (Interface->CSR1 & Registers::CSR1::Mask::ODSWRDY)); //todo timeout
}

void PWR::SetVoltageScale(VoltageScale voltageScale)
{
  uint32_t cr1 = Interface->CR1;
  cr1 &= ~Registers::CR1::Mask::VOS;
  
  switch(voltageScale)
  {
    case VoltageScale::Scale1:
      cr1 |= (3UL << Registers::CR1::Position::VOS);
      break;
    case VoltageScale::Scale2:
      cr1 |= (2UL << Registers::CR1::Position::VOS);
      break;
    case VoltageScale::Scale3:
      cr1 |= (1UL << Registers::CR1::Position::VOS);
      break;
  }
  
  Interface->CR1 = cr1;
}
