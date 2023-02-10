#include "usart.h"

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
        constexpr uint32_t M1     = 28U;
        constexpr uint32_t EOBIE  = 27U;
        constexpr uint32_t RTOIE  = 26U;
        constexpr uint32_t DEAT   = 21U;
        constexpr uint32_t DEDT   = 16U;
        constexpr uint32_t OVER8  = 15U;
        constexpr uint32_t CMIE   = 14U;
        constexpr uint32_t MME    = 13U;
        constexpr uint32_t M0     = 12U;
        constexpr uint32_t WAKE   = 11U;
        constexpr uint32_t PCE    = 10U;
        constexpr uint32_t PS     = 9U;
        constexpr uint32_t PEIE   = 8U;
        constexpr uint32_t TXEIE  = 7U;
        constexpr uint32_t TCIE   = 6U;
        constexpr uint32_t RXNEIE = 5U;
        constexpr uint32_t IDLEIE = 4U;
        constexpr uint32_t TE     = 3U;
        constexpr uint32_t RE     = 2U;
        constexpr uint32_t UE     = 0U;
      }
        
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t M1     = (0x01U << Position::M1);
        [[maybe_unused]] constexpr uint32_t EOBIE  = (0x01U << Position::EOBIE);
        [[maybe_unused]] constexpr uint32_t RTOIE  = (0x01U << Position::RTOIE);
        [[maybe_unused]] constexpr uint32_t DEAT   = (0x1FU << Position::DEAT);
        [[maybe_unused]] constexpr uint32_t DEDT   = (0x1FU << Position::DEDT);
        [[maybe_unused]] constexpr uint32_t OVER8  = (0x01U << Position::OVER8);
        [[maybe_unused]] constexpr uint32_t CMIE   = (0x01U << Position::CMIE);
        [[maybe_unused]] constexpr uint32_t MME    = (0x01U << Position::MME);
        [[maybe_unused]] constexpr uint32_t M0     = (0x01U << Position::M0);
        [[maybe_unused]] constexpr uint32_t WAKE   = (0x01U << Position::WAKE);
        [[maybe_unused]] constexpr uint32_t PCE    = (0x01U << Position::PCE);
        [[maybe_unused]] constexpr uint32_t PS     = (0x01U << Position::PS);
        [[maybe_unused]] constexpr uint32_t PEIE   = (0x01U << Position::PEIE);
        [[maybe_unused]] constexpr uint32_t TXEIE  = (0x01U << Position::TXEIE);
        [[maybe_unused]] constexpr uint32_t TCIE   = (0x01U << Position::TCIE);
        [[maybe_unused]] constexpr uint32_t RXNEIE = (0x01U << Position::RXNEIE);
        [[maybe_unused]] constexpr uint32_t IDLEIE = (0x01U << Position::IDLEIE);
        [[maybe_unused]] constexpr uint32_t TE     = (0x01U << Position::TE);
        [[maybe_unused]] constexpr uint32_t RE     = (0x01U << Position::RE);
        [[maybe_unused]] constexpr uint32_t UE     = (0x01U << Position::UE);
      }
    }
    
    namespace CR2
    {
      namespace Position
      {
        constexpr uint32_t ADD      = 24U;
        constexpr uint32_t RTOEN    = 23U;
        constexpr uint32_t ABRMOD   = 21U;
        constexpr uint32_t ABREN    = 20U;
        constexpr uint32_t MSBFIRST = 19U;
        constexpr uint32_t DATAINV  = 18U;
        constexpr uint32_t TXINV    = 17U;
        constexpr uint32_t RXINV    = 16U;
        constexpr uint32_t SWAP     = 15U;
        constexpr uint32_t LINEN    = 14U;
        constexpr uint32_t STOP     = 12U;
        constexpr uint32_t CLKEN    = 11U;
        constexpr uint32_t CPOL     = 10U;
        constexpr uint32_t CPHA     = 9U;
        constexpr uint32_t LBCL     = 8U;
        constexpr uint32_t LBDIE    = 6U;
        constexpr uint32_t LBDL     = 5U;
        constexpr uint32_t ADDM7    = 4U;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t ADD      = (0xFFU << Position::ADD);
        [[maybe_unused]] constexpr uint32_t RTOEN    = (0x01U << Position::RTOEN);
        [[maybe_unused]] constexpr uint32_t ABRMOD   = (0x03U << Position::ABRMOD);
        [[maybe_unused]] constexpr uint32_t ABREN    = (0x01U << Position::ABREN);
        [[maybe_unused]] constexpr uint32_t MSBFIRST = (0x01U << Position::MSBFIRST);
        [[maybe_unused]] constexpr uint32_t DATAINV  = (0x01U << Position::DATAINV );
        [[maybe_unused]] constexpr uint32_t TXINV    = (0x01U << Position::TXINV);
        [[maybe_unused]] constexpr uint32_t RXINV    = (0x01U << Position::RXINV);
        [[maybe_unused]] constexpr uint32_t SWAP     = (0x01U << Position::SWAP);
        [[maybe_unused]] constexpr uint32_t LINEN    = (0x01U << Position::LINEN);
        [[maybe_unused]] constexpr uint32_t STOP     = (0x03U << Position::STOP);
        [[maybe_unused]] constexpr uint32_t CLKEN    = (0x01U << Position::CLKEN);
        [[maybe_unused]] constexpr uint32_t CPOL     = (0x01U << Position::CPOL);
        [[maybe_unused]] constexpr uint32_t CPHA     = (0x01U << Position::CPHA);
        [[maybe_unused]] constexpr uint32_t LBCL     = (0x01U << Position::LBCL);
        [[maybe_unused]] constexpr uint32_t LBDIE    = (0x01U << Position::LBDIE);
        [[maybe_unused]] constexpr uint32_t LBDL     = (0x01U << Position::LBDL);
        [[maybe_unused]] constexpr uint32_t ADDM7    = (0x01U << Position::ADDM7);
      }
    }
    
    namespace CR3
    {
      namespace Position
      {
        constexpr uint32_t TCBGTIE = 24U;
        constexpr uint32_t SCARCNT = 17U;
        constexpr uint32_t DEP     = 15U;
        constexpr uint32_t DEM     = 14U;
        constexpr uint32_t DDRE    = 13U;
        constexpr uint32_t OVRDIS  = 12U;
        constexpr uint32_t ONEBIT  = 11U;
        constexpr uint32_t CTSIE   = 10U;
        constexpr uint32_t CTSE    = 9U;
        constexpr uint32_t RTSE    = 8U;
        constexpr uint32_t DMAT    = 7U;
        constexpr uint32_t DMAR    = 6U;
        constexpr uint32_t SCEN    = 5U;
        constexpr uint32_t NACK    = 4U;
        constexpr uint32_t HDSEL   = 3U;
        constexpr uint32_t IRLP    = 2U;
        constexpr uint32_t IREN    = 1U;
        constexpr uint32_t EIE     = 0U;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t TCBGTIE = (0x01U << Position::TCBGTIE);
        [[maybe_unused]] constexpr uint32_t SCARCNT = (0x07U << Position::SCARCNT);
        [[maybe_unused]] constexpr uint32_t DEP     = (0x01U << Position::DEP);
        [[maybe_unused]] constexpr uint32_t DEM     = (0x01U << Position::DEM);
        [[maybe_unused]] constexpr uint32_t DDRE    = (0x01U << Position::DDRE);
        [[maybe_unused]] constexpr uint32_t OVRDIS  = (0x01U << Position::OVRDIS);
        [[maybe_unused]] constexpr uint32_t ONEBIT  = (0x01U << Position::ONEBIT);
        [[maybe_unused]] constexpr uint32_t CTSIE   = (0x01U << Position::CTSIE);
        [[maybe_unused]] constexpr uint32_t CTSE    = (0x01U << Position::CTSE);
        [[maybe_unused]] constexpr uint32_t RTSE    = (0x01U << Position::RTSE);
        [[maybe_unused]] constexpr uint32_t DMAT    = (0x01U << Position::DMAT);
        [[maybe_unused]] constexpr uint32_t DMAR    = (0x01U << Position::DMAR);
        [[maybe_unused]] constexpr uint32_t SCEN    = (0x01U << Position::SCEN);
        [[maybe_unused]] constexpr uint32_t NACK    = (0x01U << Position::NACK);
        [[maybe_unused]] constexpr uint32_t HDSEL   = (0x01U << Position::HDSEL);
        [[maybe_unused]] constexpr uint32_t IRLP    = (0x01U << Position::IRLP);
        [[maybe_unused]] constexpr uint32_t IREN    = (0x01U << Position::IREN);
        [[maybe_unused]] constexpr uint32_t EIE     = (0x01U << Position::EIE);
      }
    }
    
    namespace BRR
    {
      namespace Position
      {
        constexpr uint32_t BRR = 0U;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t BRR = (0xFFFFU << Position::BRR);
      }
    }
    
    namespace GTPR
    {
      namespace Position
      {
        constexpr uint32_t GT  =  8U;
        constexpr uint32_t PSC = 0U;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t GT  = (0xFFU << Position::GT);
        [[maybe_unused]] constexpr uint32_t PSC = (0xFFU << Position::PSC);
      }
    }
    
    namespace RTOR
    {
      namespace Position
      {
        constexpr uint32_t BLEN = 24U;
        constexpr uint32_t RTO  = 0U;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t BLEN = (0xFFU << Position::BLEN);
        [[maybe_unused]] constexpr uint32_t RTO  = (0xFFFFFFU << Position::RTO);
      }
    }
    
    namespace RQR
    {
      namespace Position
      {
        constexpr uint32_t TXFRQ = 4U;
        constexpr uint32_t RXFRQ = 3U;
        constexpr uint32_t MMRQ  = 2U;
        constexpr uint32_t SBKRQ = 1U;
        constexpr uint32_t ABRRQ = 0U;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t TXFRQ = (0x01U << Position::TXFRQ);
        [[maybe_unused]] constexpr uint32_t RXFRQ = (0x01U << Position::RXFRQ);
        [[maybe_unused]] constexpr uint32_t MMRQ  = (0x01U << Position::MMRQ);
        [[maybe_unused]] constexpr uint32_t SBKRQ = (0x01U << Position::SBKRQ);
        [[maybe_unused]] constexpr uint32_t ABRRQ = (0x01U << Position::ABRRQ);
      }
    }
    
    namespace ISR
    {
      namespace Position
      {
        constexpr uint32_t TCBGT = 25U;
        constexpr uint32_t TEACK = 21U;
        constexpr uint32_t RWU   = 19U;
        constexpr uint32_t SBKF  = 18U;
        constexpr uint32_t CMF   = 17U;
        constexpr uint32_t BUSY  = 16U;
        constexpr uint32_t ABRF  = 15U;
        constexpr uint32_t ABRE  = 14U;
        constexpr uint32_t EOBF  = 12U;
        constexpr uint32_t RTOF  = 11U;
        constexpr uint32_t CTS   = 10U;
        constexpr uint32_t CTSIF = 9U;
        constexpr uint32_t LBDF  = 8U;
        constexpr uint32_t TXE   = 7U;
        constexpr uint32_t TC    = 6U;
        constexpr uint32_t RXNE  = 5U;
        constexpr uint32_t IDLE  = 4U;
        constexpr uint32_t ORE   = 3U;
        constexpr uint32_t NF    = 2U;
        constexpr uint32_t FE    = 1U;
        constexpr uint32_t PE    = 0U;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t TCBGT = (0x01U << Position::TCBGT);
        [[maybe_unused]] constexpr uint32_t TEACK = (0x01U << Position::TEACK);
        [[maybe_unused]] constexpr uint32_t RWU   = (0x01U << Position::RWU);
        [[maybe_unused]] constexpr uint32_t SBKF  = (0x01U << Position::SBKF);
        [[maybe_unused]] constexpr uint32_t CMF   = (0x01U << Position::CMF);
        [[maybe_unused]] constexpr uint32_t BUSY  = (0x01U << Position::BUSY);
        [[maybe_unused]] constexpr uint32_t ABRF  = (0x01U << Position::ABRF);
        [[maybe_unused]] constexpr uint32_t ABRE  = (0x01U << Position::ABRE);
        [[maybe_unused]] constexpr uint32_t EOBF  = (0x01U << Position::EOBF);
        [[maybe_unused]] constexpr uint32_t RTOF  = (0x01U << Position::RTOF);
        [[maybe_unused]] constexpr uint32_t CTS   = (0x01U << Position::CTS);
        [[maybe_unused]] constexpr uint32_t CTSIF = (0x01U << Position::CTSIF);
        [[maybe_unused]] constexpr uint32_t LBDF  = (0x01U << Position::LBDF);
        [[maybe_unused]] constexpr uint32_t TXE   = (0x01U << Position::TXE);
        [[maybe_unused]] constexpr uint32_t TC    = (0x01U << Position::TC);
        [[maybe_unused]] constexpr uint32_t RXNE  = (0x01U << Position::RXNE);
        [[maybe_unused]] constexpr uint32_t IDLE  = (0x01U << Position::IDLE);
        [[maybe_unused]] constexpr uint32_t ORE   = (0x01U << Position::ORE);
        [[maybe_unused]] constexpr uint32_t NF    = (0x01U << Position::NF);
        [[maybe_unused]] constexpr uint32_t FE    = (0x01U << Position::FE);
        [[maybe_unused]] constexpr uint32_t PE    = (0x01U << Position::PE);
      }
    }
    
    namespace ICR
    {
      namespace Position
      {
        constexpr uint32_t CMCF    = 17U;
        constexpr uint32_t EOBCF   = 12U;
        constexpr uint32_t RTOCF   = 11U;
        constexpr uint32_t CTSCF   = 9U;
        constexpr uint32_t LBDCF   = 8U;
        constexpr uint32_t TCBGTCF = 7U;
        constexpr uint32_t TCCF    = 6U;
        constexpr uint32_t IDLECF  = 4U;
        constexpr uint32_t ORECF   = 3U;
        constexpr uint32_t NCF     = 2U;
        constexpr uint32_t FECF    = 1U;
        constexpr uint32_t PECF    = 0U;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t CMCF    = (0x01U << Position::CMCF);
        [[maybe_unused]] constexpr uint32_t EOBCF   = (0x01U << Position::EOBCF);
        [[maybe_unused]] constexpr uint32_t RTOCF   = (0x01U << Position::RTOCF);
        [[maybe_unused]] constexpr uint32_t CTSCF   = (0x01U << Position::CTSCF);
        [[maybe_unused]] constexpr uint32_t LBDCF   = (0x01U << Position::LBDCF);
        [[maybe_unused]] constexpr uint32_t TCBGTCF = (0x01U << Position::TCBGTCF);
        [[maybe_unused]] constexpr uint32_t TCCF    = (0x01U << Position::TCCF);
        [[maybe_unused]] constexpr uint32_t IDLECF  = (0x01U << Position::IDLECF);
        [[maybe_unused]] constexpr uint32_t ORECF   = (0x01U << Position::ORECF);
        [[maybe_unused]] constexpr uint32_t NCF     = (0x01U << Position::NCF);
        [[maybe_unused]] constexpr uint32_t FECF    = (0x01U << Position::FECF);
        [[maybe_unused]] constexpr uint32_t PECF    = (0x01U << Position::PECF);
      }
    }
    
    namespace RDR
    {
      namespace Position
      {
        constexpr uint32_t RDR = 0U;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t RDR = (0x1FFU << Position::RDR);
      }
    }
    
    namespace TDR
    {
      namespace Position
      {
        constexpr uint32_t TDR = 0U;
      }
      
      namespace Mask 
      {
        [[maybe_unused]] constexpr uint32_t TDR = (0x1FFU << Position::TDR);
      }
    }
  }
  
  struct USARTRegisters {
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t CR3;
    volatile uint32_t BRR;
    volatile uint32_t GTPR;
    volatile uint32_t RTOR;
    volatile uint32_t RQR;
    volatile uint32_t ISR;
    volatile uint32_t ICR;
    volatile uint32_t RDR;
    volatile uint32_t TDR;
  };
  
  static_assert(0x00 == offsetof(USARTRegisters, CR1));
  static_assert(0x04 == offsetof(USARTRegisters, CR2));
  static_assert(0x08 == offsetof(USARTRegisters, CR3));
  static_assert(0x0C == offsetof(USARTRegisters, BRR));
  static_assert(0x10 == offsetof(USARTRegisters, GTPR));
  static_assert(0x14 == offsetof(USARTRegisters, RTOR));
  static_assert(0x18 == offsetof(USARTRegisters, RQR));
  static_assert(0x1C == offsetof(USARTRegisters, ISR));
  static_assert(0x20 == offsetof(USARTRegisters, ICR));
  static_assert(0x24 == offsetof(USARTRegisters, RDR));
  static_assert(0x28 == offsetof(USARTRegisters, TDR));
}
