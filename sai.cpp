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
  
  struct SAIRegisters
  {
    volatile uint32_t GCR;
    volatile uint32_t ACR1;
    volatile uint32_t ACR2;
    volatile uint32_t AFRCR;
    volatile uint32_t ASLOTR;
    volatile uint32_t AIM;
    volatile uint32_t ASR;
    volatile uint32_t ACLRFR;
    volatile uint32_t ADR;
    volatile uint32_t BCR1;
    volatile uint32_t BCR2;
    volatile uint32_t BFRCR;
    volatile uint32_t BSLOTR;
    volatile uint32_t BIM;
    volatile uint32_t BSR;
    volatile uint32_t BCLRFR;
    volatile uint32_t BDR;
  };
  
  static_assert(0x00U == offsetof(SAIRegisters, GCR));
  static_assert(0x04U == offsetof(SAIRegisters, ACR1));
  static_assert(0x08U == offsetof(SAIRegisters, ACR2));
  static_assert(0x0CU == offsetof(SAIRegisters, AFRCR));
  static_assert(0x10U == offsetof(SAIRegisters, ASLOTR));
  static_assert(0x14U == offsetof(SAIRegisters, AIM));
  static_assert(0x18U == offsetof(SAIRegisters, ASR));
  static_assert(0x1CU == offsetof(SAIRegisters, ACLRFR));
  static_assert(0x20U == offsetof(SAIRegisters, ADR));
  static_assert(0x24U == offsetof(SAIRegisters, BCR1));
  static_assert(0x28U == offsetof(SAIRegisters, BCR2));
  static_assert(0x2CU == offsetof(SAIRegisters, BFRCR));
  static_assert(0x30U == offsetof(SAIRegisters, BSLOTR));
  static_assert(0x34U == offsetof(SAIRegisters, BIM));
  static_assert(0x38U == offsetof(SAIRegisters, BSR));
  static_assert(0x3CU == offsetof(SAIRegisters, BCLRFR));
  static_assert(0x40U == offsetof(SAIRegisters, BDR));
  
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
