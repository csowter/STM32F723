#include "gpio.h"

#include <cstdint>
#include <cstddef>
#include <array>

namespace
{ 
  namespace Registers
  {
    namespace MODER
    {
      [[maybe_unused]] constexpr uint32_t Mask              = 3UL;
      [[maybe_unused]] constexpr uint32_t Input             = 0UL;
      [[maybe_unused]] constexpr uint32_t Output            = 1UL;
      [[maybe_unused]] constexpr uint32_t AlternateFunction = 2UL;
      [[maybe_unused]] constexpr uint32_t Analogue          = 3UL;
    }
    
    namespace OSPEEDR
    {
      [[maybe_unused]] constexpr uint32_t Mask     = 3UL;
      [[maybe_unused]] constexpr uint32_t Low      = 0UL;
      [[maybe_unused]] constexpr uint32_t Medium   = 1UL;
      [[maybe_unused]] constexpr uint32_t High     = 2UL;
      [[maybe_unused]] constexpr uint32_t VeryHigh = 3UL;
    }
  }
  
  struct GPIORegisters
  {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFR[2];
  };
  
  static_assert(0x00UL == offsetof(GPIORegisters, MODER));
  static_assert(0x04UL == offsetof(GPIORegisters, OTYPER));
  static_assert(0x08UL == offsetof(GPIORegisters, OSPEEDR));
  static_assert(0x0CUL == offsetof(GPIORegisters, PUPDR));
  static_assert(0x10UL == offsetof(GPIORegisters, IDR));
  static_assert(0x14UL == offsetof(GPIORegisters, ODR));
  static_assert(0x18UL == offsetof(GPIORegisters, BSRR));
  static_assert(0x1CUL == offsetof(GPIORegisters, LCKR));
  static_assert(0x20UL == offsetof(GPIORegisters, AFR[0]));
  
  constexpr uint32_t GPIOABaseAddress = 0x40020000UL;
  constexpr uint32_t GPIOBBaseAddress = 0x40020400UL;
  constexpr uint32_t GPIOCBaseAddress = 0x40020800UL;
  constexpr uint32_t GPIODBaseAddress = 0x40020C00UL;
  constexpr uint32_t GPIOEBaseAddress = 0x40021000UL;
  constexpr uint32_t GPIOFBaseAddress = 0x40021400UL;
  constexpr uint32_t GPIOGBaseAddress = 0x40021800UL;
  constexpr uint32_t GPIOHBaseAddress = 0x40021C00UL;
  constexpr uint32_t GPIOIBaseAddress = 0x40022000UL;
  
  const std::array<GPIORegisters *, 9UL> GPIOPorts {
    reinterpret_cast<GPIORegisters *>( GPIOABaseAddress ),
    reinterpret_cast<GPIORegisters *>( GPIOBBaseAddress ),
    reinterpret_cast<GPIORegisters *>( GPIOCBaseAddress ),
    reinterpret_cast<GPIORegisters *>( GPIODBaseAddress ),
    reinterpret_cast<GPIORegisters *>( GPIOEBaseAddress ),
    reinterpret_cast<GPIORegisters *>( GPIOFBaseAddress ),
    reinterpret_cast<GPIORegisters *>( GPIOGBaseAddress ),
    reinterpret_cast<GPIORegisters *>( GPIOHBaseAddress ),
    reinterpret_cast<GPIORegisters *>( GPIOIBaseAddress ),
  };
  
  GPIORegisters *GPIOInstance(GPIO::Port port)
  {
    return GPIOPorts[static_cast<std::size_t>(port)];
  }
}

GPIO::GPIO(Port port, Pin pin)
: port_m{port}
, pin_m{pin}
{}
  
void GPIO::SetMode(Mode mode)
{
   GPIORegisters * const instance{GPIOInstance(port_m)};
  
  const uint32_t position = static_cast<uint32_t>(pin_m) * 2;
  
  instance->MODER &= ~(Registers::MODER::Mask << position);
  
  switch(mode)
  {
    case Mode::Input:
      // 00 
      break;
    case Mode::Output:
      instance->MODER |= (Registers::MODER::Output << position);
      break;
    case Mode::AlternateFunction:
      instance->MODER |= (Registers::MODER::AlternateFunction << position);
      break;
    case Mode::Analogue:
      instance->MODER |= (Registers::MODER::Analogue << position);
      break;
  }
}

void GPIO::SetSpeed(Speed speed)
{
  GPIORegisters * const instance{GPIOInstance(port_m)};
  
  const uint32_t position = static_cast<uint32_t>(pin_m) * 2;
  
  instance->OSPEEDR &= ~(Registers::OSPEEDR::Mask << position);
  
  switch(speed)
  {
    case Speed::Low:
      //00
      break;
    case Speed::Medium:
      instance->OSPEEDR |= (Registers::OSPEEDR::Medium << position);
      break;
    case Speed::High:
      instance->OSPEEDR |= (Registers::OSPEEDR::High << position);
      break;
    case Speed::VeryHigh:
      instance->OSPEEDR |= (Registers::OSPEEDR::VeryHigh << position);
      break;
  }
}

void GPIO::SetAlternateFunction(AlternateFunction af)
{
  GPIORegisters * const instance{GPIOInstance(port_m)};
  const uint32_t position = ((4UL * static_cast<uint32_t>(pin_m)) % 32UL);
  uint32_t index = (static_cast<uint32_t>(pin_m) < 8UL) ? 0UL : 1UL;
  
  instance->AFR[index] &= ~(0xFUL << position);
  instance->AFR[index] |= (static_cast<uint32_t>(af) << position);  
}

void GPIO::SetOutputState(State state)
{
  GPIORegisters * const instance{GPIOInstance(port_m)};
  const uint32_t position = (1UL << static_cast<uint32_t>(pin_m));
  
  if(State::High == state)
  {
    instance->BSRR = position;
  }
  else
  {
    instance->BSRR = (position << 16UL);
  }
}

GPIO::State GPIO::GetInputState()
{
  GPIORegisters * const instance{GPIOInstance(port_m)};
  const uint32_t position = static_cast<uint32_t>(pin_m);
  
  if((1UL << position) == (instance->IDR & (1UL << position)))
  {
    return State::High;
  }
  else
  {
    return State::Low;
  }
}
