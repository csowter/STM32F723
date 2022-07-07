#include "sai.h"
#include <cstdint>
#include <cstddef>
#include <array>
namespace
{
  namespace Registers
  {
    namespace GCR
    {
      namespace Position
      {
        constexpr uint32_t SYNCOUT = 4UL;
        constexpr uint32_t SYNCIN  = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t SYNCOUT = (0x03 << Position::SYNCOUT);
        [[maybe_unused]] constexpr uint32_t SYNCIN  = (0x03 << Position::SYNCIN);
      }
    }
    
    namespace xCR1
    {
      namespace Position
      {
        constexpr uint32_t MCKDIV   = 20UL;
        constexpr uint32_t NODIV    = 19UL;
        constexpr uint32_t DMAEN    = 17UL;
        constexpr uint32_t SAIEN    = 16UL;
        constexpr uint32_t OUTDRIV  = 13UL;
        constexpr uint32_t MONO     = 12UL;
        constexpr uint32_t SYNCEN   = 10UL;
        constexpr uint32_t CKSTR    = 9UL;
        constexpr uint32_t LSBFIRST = 8UL;
        constexpr uint32_t DS       = 5UL;
        constexpr uint32_t PRTCFG   = 2UL;
        constexpr uint32_t MODE     = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t MCKDIV   = (0x0FUL << Position::MCKDIV);
        [[maybe_unused]] constexpr uint32_t NODIV    = (0x01UL << Position::NODIV);
        [[maybe_unused]] constexpr uint32_t DMAEN    = (0x01UL << Position::DMAEN);
        [[maybe_unused]] constexpr uint32_t SAIEN    = (0x01UL << Position::SAIEN);
        [[maybe_unused]] constexpr uint32_t OUTDRIV  = (0x01UL << Position::OUTDRIV);
        [[maybe_unused]] constexpr uint32_t MONO     = (0x01UL << Position::MONO);
        [[maybe_unused]] constexpr uint32_t SYNCEN   = (0x03UL << Position::SYNCEN);
        [[maybe_unused]] constexpr uint32_t CKSTR    = (0x01UL << Position::CKSTR);
        [[maybe_unused]] constexpr uint32_t LSBFIRST = (0x01UL << Position::LSBFIRST);
        [[maybe_unused]] constexpr uint32_t DS       = (0x07UL << Position::DS);
        [[maybe_unused]] constexpr uint32_t PRTCFG   = (0x03UL << Position::PRTCFG);
        [[maybe_unused]] constexpr uint32_t MODE     = (0x03UL << Position::MODE);
      }
    }
    
    namespace xCR2
    {
      namespace Position
      {
        constexpr uint32_t COMP    = 14UL;
        constexpr uint32_t CPL     = 13UL;
        constexpr uint32_t MUTECNT = 7UL;
        constexpr uint32_t MUTEVAL = 6UL;
        constexpr uint32_t MUTE    = 5UL;
        constexpr uint32_t TRIS    = 4UL;
        constexpr uint32_t FFLUSH  = 3UL;
        constexpr uint32_t FTH     = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t COMP    = (0x03UL << Position::COMP);
        [[maybe_unused]] constexpr uint32_t CPL     = (0x01UL << Position::CPL);
        [[maybe_unused]] constexpr uint32_t MUTECNT = (0x3FUL << Position::MUTECNT);
        [[maybe_unused]] constexpr uint32_t MUTEVAL = (0x01UL << Position::MUTEVAL);
        [[maybe_unused]] constexpr uint32_t MUTE    = (0x01UL << Position::MUTE);
        [[maybe_unused]] constexpr uint32_t TRIS    = (0x01UL << Position::TRIS);
        [[maybe_unused]] constexpr uint32_t FFLUSH  = (0x01UL << Position::FFLUSH);
        [[maybe_unused]] constexpr uint32_t FTH     = (0x07UL << Position::FTH);
      }
    }
    
    namespace xFRCR
    {
      namespace Position
      {
        constexpr uint32_t FSOFF = 18UL;
        constexpr uint32_t FSPOL = 17UL;
        constexpr uint32_t FSDEF = 16UL;
        constexpr uint32_t FSALL = 8UL;
        constexpr uint32_t FRL   = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t FSOFF = (0x01UL << Position::FSOFF);
        [[maybe_unused]] constexpr uint32_t FSPOL = (0x01UL << Position::FSPOL);
        [[maybe_unused]] constexpr uint32_t FSDEF = (0x01UL << Position::FSDEF);
        [[maybe_unused]] constexpr uint32_t FSALL = (0x7FUL << Position::FSALL);
        [[maybe_unused]] constexpr uint32_t FRL   = (0xFFUL << Position::FRL);
      }
    }
    
    namespace xSLOTR
    {
      namespace Position
      {
        constexpr uint32_t SLOTEN = 16UL;
        constexpr uint32_t NBSLOT = 8UL;
        constexpr uint32_t SLOTSZ = 6UL;
        constexpr uint32_t FBOFF  = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t SLOTEN = (0xFFFFUL << Position::SLOTEN);
        [[maybe_unused]] constexpr uint32_t NBSLOT = (0x000FUL << Position::NBSLOT);
        [[maybe_unused]] constexpr uint32_t SLOTSZ = (0x0003UL << Position::SLOTSZ);
        [[maybe_unused]] constexpr uint32_t FBOFF  = (0x001FUL << Position::FBOFF);
      }
    }
    
    namespace xIM
    {
      namespace Position
      {
        constexpr uint32_t LFSDETIE  = 6UL;
        constexpr uint32_t AFSDETIE  = 5UL;
        constexpr uint32_t CNRDYIE   = 4UL;
        constexpr uint32_t FREQIE    = 3UL;
        constexpr uint32_t WCKCFGIE  = 2UL;
        constexpr uint32_t MUTEDETIE = 1UL;
        constexpr uint32_t OVRUDRIE  = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t LFSDETIE  = (0x01UL << Position::LFSDETIE);
        [[maybe_unused]] constexpr uint32_t AFSDETIE  = (0x01UL << Position::AFSDETIE);
        [[maybe_unused]] constexpr uint32_t CNRDYIE   = (0x01UL << Position::CNRDYIE);
        [[maybe_unused]] constexpr uint32_t FREQIE    = (0x01UL << Position::FREQIE);
        [[maybe_unused]] constexpr uint32_t WCKCFGIE  = (0x01UL << Position::WCKCFGIE);
        [[maybe_unused]] constexpr uint32_t MUTEDETIE = (0x01UL << Position::MUTEDETIE);
        [[maybe_unused]] constexpr uint32_t OVRUDRIE  = (0x01UL << Position::OVRUDRIE);
      }
    }
    
    namespace xSR
    {
      namespace Position
      {
        constexpr uint32_t FLVL    = 16UL;
        constexpr uint32_t LFSDET  = 6UL;
        constexpr uint32_t AFSDET  = 5UL;
        constexpr uint32_t CNRDY   = 4UL;
        constexpr uint32_t FREQ    = 3UL;
        constexpr uint32_t WCKCFG  = 2UL;
        constexpr uint32_t MUTEDET = 1UL;
        constexpr uint32_t OVRUDR  = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t FLVL    = (0x07UL << Position::FLVL);
        [[maybe_unused]] constexpr uint32_t LFSDET  = (0x01UL << Position::LFSDET);
        [[maybe_unused]] constexpr uint32_t AFSDET  = (0x01UL << Position::AFSDET);
        [[maybe_unused]] constexpr uint32_t CNRDY   = (0x01UL << Position::CNRDY);
        [[maybe_unused]] constexpr uint32_t FREQ    = (0x01UL << Position::FREQ);
        [[maybe_unused]] constexpr uint32_t WCKCFG  = (0x01UL << Position::WCKCFG);
        [[maybe_unused]] constexpr uint32_t MUTEDET = (0x01UL << Position::MUTEDET);
        [[maybe_unused]] constexpr uint32_t OVRUDR  = (0x01UL << Position::OVRUDR);
      }
    }
    
    namespace xCLRFR
    {
      namespace Position 
      {
        constexpr uint32_t CLFSDET  = 6UL;
        constexpr uint32_t CAFSDET  = 5UL;
        constexpr uint32_t CCNRDY   = 4UL;
        constexpr uint32_t CWCKCFG  = 2UL;
        constexpr uint32_t CMUTEDET = 1UL;
        constexpr uint32_t COVRUDR  = 0UL;
      }
      
      namespace Mask 
      {
        [[maybe_unused]] constexpr uint32_t CLFSDET  = (0x01UL << Position::CLFSDET);
        [[maybe_unused]] constexpr uint32_t CAFSDET  = (0x01UL << Position::CAFSDET);
        [[maybe_unused]] constexpr uint32_t CCNRDY   = (0x01UL << Position::CCNRDY);
        [[maybe_unused]] constexpr uint32_t CWCKCFG  = (0x01UL << Position::CWCKCFG);
        [[maybe_unused]] constexpr uint32_t CMUTEDET = (0x01UL << Position::CMUTEDET);
        [[maybe_unused]] constexpr uint32_t COVRUDR  = (0x01UL << Position::COVRUDR);
      }
    }
    
    namespace xDR
    {
      namespace Position
      {
        constexpr uint32_t DATA = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t DATA = (0xFFFFFFFFUL << Position::DATA);
      }
    }
    
  }
  
  struct Block
  {
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t FRCR;
    volatile uint32_t SLOTR;
    volatile uint32_t IM;
    volatile uint32_t SR;
    volatile uint32_t CLRFR;
    volatile uint32_t DR;
  };
  
  struct SAIRegisters
  {
    volatile uint32_t GCR;
    Block block[2];
  };
  
  static_assert(0x00U == offsetof(SAIRegisters, GCR));
  static_assert(0x04U == offsetof(SAIRegisters, block[0].CR1));
  static_assert(0x08U == offsetof(SAIRegisters, block[0].CR2));
  static_assert(0x0CU == offsetof(SAIRegisters, block[0].FRCR));
  static_assert(0x10U == offsetof(SAIRegisters, block[0].SLOTR));
  static_assert(0x14U == offsetof(SAIRegisters, block[0].IM));
  static_assert(0x18U == offsetof(SAIRegisters, block[0].SR));
  static_assert(0x1CU == offsetof(SAIRegisters, block[0].CLRFR));
  static_assert(0x20U == offsetof(SAIRegisters, block[0].DR));
  static_assert(0x24U == offsetof(SAIRegisters, block[1].CR1));
  static_assert(0x28U == offsetof(SAIRegisters, block[1].CR2));
  static_assert(0x2CU == offsetof(SAIRegisters, block[1].FRCR));
  static_assert(0x30U == offsetof(SAIRegisters, block[1].SLOTR));
  static_assert(0x34U == offsetof(SAIRegisters, block[1].IM));
  static_assert(0x38U == offsetof(SAIRegisters, block[1].SR));
  static_assert(0x3CU == offsetof(SAIRegisters, block[1].CLRFR));
  static_assert(0x40U == offsetof(SAIRegisters, block[1].DR));
  
  constexpr uint32_t SAI1BaseAddress = 0x40015800UL;
  constexpr uint32_t SAI2BaseAddress = 0x40015C00UL;
  
  const std::array<SAIRegisters *, 2U> SAIPorts{
    reinterpret_cast<SAIRegisters *>(SAI1BaseAddress),
    reinterpret_cast<SAIRegisters *>(SAI2BaseAddress),  
  };
  
  SAIRegisters *GetInstance(SAI::Port port)
  {
    return SAIPorts[static_cast<std::size_t>(port)];
  }
}

SAI::SAI(Port port)
: port_m{port}
{}
  
void SAI::SetMode(Block block, Mode mode)
{
  uint32_t newMode;
  switch(mode)
  {
    case Mode::MasterTransmitter:
      newMode = 0x00UL << Registers::xCR1::Position::MODE;
      break;
    case Mode::MasterReceiver:
      newMode = 0x01UL << Registers::xCR1::Position::MODE;
      break;
    case Mode::SlaveTransmitter:
      newMode = 0x02UL << Registers::xCR1::Position::MODE;
      break;
    case Mode::SlaveReceiver:
      newMode = 0x03UL << Registers::xCR1::Position::MODE;
      break;
  }
  
  SAIRegisters * const instance = GetInstance(port_m);
  
  uint32_t cr1 = instance->block[static_cast<uint32_t>(block)].CR1;
  cr1 &= ~Registers::xCR1::Mask::MODE;
  cr1 |= newMode;
  instance->block[static_cast<uint32_t>(block)].CR1 = newMode;
}
  
void SAI::Enable(Block block)
{
  SAIRegisters * const instance = GetInstance(port_m);
  instance->block[static_cast<uint32_t>(block)].CR1 |= Registers::xCR1::Mask::SAIEN;
}
  
void SAI::Disable(Block block)
{
  SAIRegisters * const instance = GetInstance(port_m);
  instance->block[static_cast<uint32_t>(block)].CR1 &= ~Registers::xCR1::Mask::SAIEN;
}
  
void SAI::SetDataSize(Block block, DataSize size)
{
  uint32_t dataSizeBits;
  switch(size)
  {
    case DataSize::DS_8Bit:
      dataSizeBits = 0x02UL << Registers::xCR1::Position::DS;
      break;
    case DataSize::DS_10Bit:
      dataSizeBits = 0x03UL << Registers::xCR1::Position::DS;
      break;
    case DataSize::DS_16Bit:
      dataSizeBits = 0x04UL << Registers::xCR1::Position::DS;
      break;
    case DataSize::DS_20Bit:
      dataSizeBits = 0x05UL << Registers::xCR1::Position::DS;
      break;
    case DataSize::DS_24Bit:
      dataSizeBits = 0x06UL << Registers::xCR1::Position::DS;
      break;
    case DataSize::DS_32Bit: 
      dataSizeBits = 0x07UL << Registers::xCR1::Position::DS;
      break;
  }
  
  SAIRegisters * const instance = GetInstance(port_m);
  uint32_t cr1 = instance->block[static_cast<uint32_t>(block)].CR1;
  cr1 &= ~Registers::xCR1::Mask::DS;
  cr1 |= dataSizeBits;
  instance->block[static_cast<uint32_t>(block)].CR1 = cr1;
}
  
void SAI::SetFirstBit(Block block, FirstBit bit)
{
  SAIRegisters * const instance = GetInstance(port_m);
  
  if(FirstBit::MSB == bit)
  {
    instance->block[static_cast<uint32_t>(block)].CR1 &= ~Registers::xCR1::Mask::LSBFIRST;
  }
  else
  {
    instance->block[static_cast<uint32_t>(block)].CR1 |= Registers::xCR1::Mask::LSBFIRST;
  }
}
  
void SAI::SetFrameLength(Block block, uint16_t length)
{
  SAIRegisters * const instance = GetInstance(port_m);
  
  instance->block[static_cast<uint32_t>(block)].FRCR &= ~Registers::xFRCR::Mask::FRL;
  uint32_t lengthBits = (length - 1U) << Registers::xFRCR::Position::FRL;
  lengthBits &= Registers::xFRCR::Mask::FRL;
  instance->block[static_cast<uint32_t>(block)].FRCR |= lengthBits;  
}
  
void SAI::SetFrameSynchronizationPolarity(Block block, FrameSyncEdge edge)
{
  SAIRegisters * const instance = GetInstance(port_m);
  if(FrameSyncEdge::Falling == edge)
  {
    instance->block[static_cast<uint32_t>(block)].FRCR &= ~Registers::xFRCR::Mask::FSPOL;
  }
  else
  {
    instance->block[static_cast<uint32_t>(block)].FRCR |= Registers::xFRCR::Mask::FSPOL;
  }
}
  
void SAI::SetFrameSynchronizationActiveLevelLength(Block block, uint8_t clockCycleCount)
{
  SAIRegisters * const instance = GetInstance(port_m);
  uint32_t countBits = clockCycleCount - 1U;
  countBits <<= Registers::xFRCR::Position::FSALL;
  countBits &= Registers::xFRCR::Mask::FSALL;
  
  uint32_t frcr = instance->block[static_cast<uint32_t>(block)].FRCR;
  frcr &= ~Registers::xFRCR::Mask::FSALL;
  frcr |= countBits;
  instance->block[static_cast<uint32_t>(block)].FRCR = frcr;
}
  
void SAI::SetFrameSynchronizationOffset(Block block, FrameSyncOffset offset)
{
  SAIRegisters * const instance = GetInstance(port_m);
  
  if(FrameSyncOffset::FirstBit == offset)
  {
    instance->block[static_cast<uint32_t>(block)].FRCR &= ~Registers::xFRCR::Mask::FSOFF;
  }
  else
  {
    instance->block[static_cast<uint32_t>(block)].FRCR |= Registers::xFRCR::Mask::FSOFF;
  }
}
  
void SAI::SetFrameSynchronizationSignalRole(Block block, FrameSyncRole role)
{
  SAIRegisters * const instance = GetInstance(port_m);
  
  if(FrameSyncRole::StartOfFrame == role)
  {
    instance->block[static_cast<uint32_t>(block)].FRCR &= ~Registers::xFRCR::Mask::FSDEF;
  }
  else
  {
    instance->block[static_cast<uint32_t>(block)].FRCR |= Registers::xFRCR::Mask::FSDEF;
  }
}
  
void SAI::SetSlotConfiguration(Block block, uint8_t numberOfSlots, SlotSize slotSize)
{
  SAIRegisters * const instance = GetInstance(port_m);
  constexpr uint32_t mask = Registers::xSLOTR::Mask::SLOTSZ |
                            Registers::xSLOTR::Mask::NBSLOT;
  
  uint32_t slotr = instance->block[static_cast<uint32_t>(block)].SLOTR;
  slotr &= ~mask;
  
  uint32_t slotSizeBits;
  switch(slotSize)
  {
    case SlotSize::sz_DataSize:
      slotSizeBits = (0x00U << Registers::xSLOTR::Position::SLOTSZ);
      break;
    case SlotSize::sz_16Bit:
      slotSizeBits = (0x01U << Registers::xSLOTR::Position::SLOTSZ);
      break;
    case SlotSize::sz_32Bit:
      slotSizeBits = (0x02U << Registers::xSLOTR::Position::SLOTSZ);
      break;
  }
  
  uint32_t slotBits = ((numberOfSlots - 1U) << Registers::xSLOTR::Position::NBSLOT) |
                      slotSizeBits;
  
  slotBits &= mask;
  slotr |= slotBits;
  instance->block[static_cast<uint32_t>(block)].SLOTR |= slotr;
  
}
