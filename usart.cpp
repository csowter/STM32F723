#include "usart.h"
#include <cstdint>
#include <cstddef>

namespace
{
  struct USARTRegisters
  {
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t CR3;
    volatile uint32_t BRR;
    volatile uint32_t GTPR;
    volatile uint32_t RTOR;
    volatile uint32_t RQR;
    volatile uint32_t ISR;
    volatile uint32_t ICR;
    const volatile uint32_t RDR;
    volatile uint32_t TDR;
  };
  
  static_assert(0x00UL == offsetof(USARTRegisters, CR1));
  static_assert(0x04UL == offsetof(USARTRegisters, CR2));
  static_assert(0x08UL == offsetof(USARTRegisters, CR3));
  static_assert(0x0CUL == offsetof(USARTRegisters, BRR));
  static_assert(0x10UL == offsetof(USARTRegisters, GTPR));
  static_assert(0x14UL == offsetof(USARTRegisters, RTOR));
  static_assert(0x18UL == offsetof(USARTRegisters, RQR));
  static_assert(0x1CUL == offsetof(USARTRegisters, ISR));
  static_assert(0x20UL == offsetof(USARTRegisters, ICR));
  static_assert(0x24UL == offsetof(USARTRegisters, RDR));
  static_assert(0x28UL == offsetof(USARTRegisters, TDR));
}
