#include "flash.h"
#include <cstddef>

namespace
{
  namespace Registers
  {
    namespace ACR
    {
      namespace Position
      {
        constexpr uint32_t ARTRST  = 11UL;
        constexpr uint32_t ARTEN   = 9UL;
        constexpr uint32_t PRFTEN  = 8UL;
        constexpr uint32_t LATENCY = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t ARTRST  = (1UL << Position::ARTRST);
        [[maybe_unused]] constexpr uint32_t ARTEN   = (1UL << Position::ARTEN);
        [[maybe_unused]] constexpr uint32_t PRFTEN  = (1UL << Position::PRFTEN);
        [[maybe_unused]] constexpr uint32_t LATENCY = (0xFUL << Position::LATENCY);
      }
    }
  }
  
  struct FlashRegisters
  {
    volatile uint32_t ACR;
    volatile uint32_t KEYR;
    volatile uint32_t OPTKEYR;
    volatile uint32_t SR;
    volatile uint32_t CR;
    volatile uint32_t OPTCR;
    volatile uint32_t OPTCR1;
    volatile uint32_t OPTCR2;
  };
  
  static_assert(0x00 == offsetof(FlashRegisters, ACR));
  static_assert(0x04 == offsetof(FlashRegisters, KEYR));
  static_assert(0x08 == offsetof(FlashRegisters, OPTKEYR));
  static_assert(0x0C == offsetof(FlashRegisters, SR));
  static_assert(0x10 == offsetof(FlashRegisters, CR));
  static_assert(0x14 == offsetof(FlashRegisters, OPTCR));
  static_assert(0x18 == offsetof(FlashRegisters, OPTCR1));
  static_assert(0x1C == offsetof(FlashRegisters, OPTCR2));
  
  constexpr uint32_t FlashPeripheralBaseAddress = 0x40023C00UL;
  
  FlashRegisters *FLASH = reinterpret_cast<FlashRegisters *>(FlashPeripheralBaseAddress);
}

void Flash::EnablePrefetch()
{
  FLASH->ACR |= Registers::ACR::Mask::PRFTEN;
}

void Flash::EnableARTAccelerator()
{
  FLASH->ACR |= Registers::ACR::Mask::ARTEN;
}
  
void Flash::SetWaitStates(uint32_t waitStates)
{
  uint32_t acr = FLASH->ACR;
  acr &= ~Registers::ACR::Mask::LATENCY;
  acr |= ((waitStates << Registers::ACR::Position::LATENCY) & Registers::ACR::Mask::LATENCY);
  FLASH->ACR = acr;
}
