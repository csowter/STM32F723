#include "dma.h"
#include <cstdint>
#include <cstddef>
#include <array>
#include <algorithm>
#include <tuple>

namespace 
{
  namespace Registers
  {
    namespace LISR
    {
      namespace Position
      {
        constexpr uint32_t TCIF3  = 27U;
        constexpr uint32_t HTIF3  = 26U;
        constexpr uint32_t TEIF3  = 25U;
        constexpr uint32_t DMEIF3 = 24U;
        constexpr uint32_t FEIF3  = 22U;
        constexpr uint32_t TCIF2  = 21U;
        constexpr uint32_t HTIF2  = 20U;
        constexpr uint32_t TEIF2  = 19U;
        constexpr uint32_t DMEIF2 = 18U;
        constexpr uint32_t FEIF2  = 16U;
        constexpr uint32_t TCIF1  = 11U;
        constexpr uint32_t HTIF1  = 10U;
        constexpr uint32_t TEIF1  = 9U;
        constexpr uint32_t DMEIF1 = 8U;
        constexpr uint32_t FEIF1  = 6U;
        constexpr uint32_t TCIF0  = 5U;
        constexpr uint32_t HTIF0  = 4U;
        constexpr uint32_t TEIF0  = 3U;
        constexpr uint32_t DMEIF0 = 2U;
        constexpr uint32_t FEIF0  = 0U;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t TCIF3  = (0x01U << Position::TCIF3);
        [[maybe_unused]] constexpr uint32_t HTIF3  = (0x01U << Position::HTIF3);
        [[maybe_unused]] constexpr uint32_t TEIF3  = (0x01U << Position::TEIF3);
        [[maybe_unused]] constexpr uint32_t DMEIF3 = (0x01U << Position::DMEIF3);
        [[maybe_unused]] constexpr uint32_t FEIF3  = (0x01U << Position::FEIF3);
        [[maybe_unused]] constexpr uint32_t TCIF2  = (0x01U << Position::TCIF2);
        [[maybe_unused]] constexpr uint32_t HTIF2  = (0x01U << Position::HTIF2);
        [[maybe_unused]] constexpr uint32_t TEIF2  = (0x01U << Position::TEIF2);
        [[maybe_unused]] constexpr uint32_t DMEIF2 = (0x01U << Position::DMEIF2);
        [[maybe_unused]] constexpr uint32_t FEIF2  = (0x01U << Position::FEIF2);
        [[maybe_unused]] constexpr uint32_t TCIF1  = (0x01U << Position::TCIF1);
        [[maybe_unused]] constexpr uint32_t HTIF1  = (0x01U << Position::HTIF1);
        [[maybe_unused]] constexpr uint32_t TEIF1  = (0x01U << Position::TEIF1);
        [[maybe_unused]] constexpr uint32_t DMEIF1 = (0x01U << Position::DMEIF1);
        [[maybe_unused]] constexpr uint32_t FEIF1  = (0x01U << Position::FEIF1);
        [[maybe_unused]] constexpr uint32_t TCIF0  = (0x01U << Position::TCIF0);
        [[maybe_unused]] constexpr uint32_t HTIF0  = (0x01U << Position::HTIF0);
        [[maybe_unused]] constexpr uint32_t TEIF0  = (0x01U << Position::TEIF0);
        [[maybe_unused]] constexpr uint32_t DMEIF0 = (0x01U << Position::DMEIF0);
        [[maybe_unused]] constexpr uint32_t FEIF0  = (0x01U << Position::FEIF0);
      }
    }
    
    namespace HISR
    {
      namespace Position
      {
        constexpr uint32_t TCIF7  = 27U;
        constexpr uint32_t HTIF7  = 26U;
        constexpr uint32_t TEIF7  = 25U;
        constexpr uint32_t DMEIF7 = 24U;
        constexpr uint32_t FEIF7  = 22U;
        constexpr uint32_t TCIF6  = 21U;
        constexpr uint32_t HTIF6  = 20U;
        constexpr uint32_t TEIF6  = 19U;
        constexpr uint32_t DMEIF6 = 18U;
        constexpr uint32_t FEIF6  = 16U;
        constexpr uint32_t TCIF5  = 11U;
        constexpr uint32_t HTIF5  = 10U;
        constexpr uint32_t TEIF5  = 9U;
        constexpr uint32_t DMEIF5 = 8U;
        constexpr uint32_t FEIF5  = 6U;
        constexpr uint32_t TCIF4  = 5U;
        constexpr uint32_t HTIF4  = 4U;
        constexpr uint32_t TEIF4  = 3U;
        constexpr uint32_t DMEIF4 = 2U;
        constexpr uint32_t FEIF4  = 0U;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t TCIF7  = (0x01U << Position::TCIF7);
        [[maybe_unused]] constexpr uint32_t HTIF7  = (0x01U << Position::HTIF7);
        [[maybe_unused]] constexpr uint32_t TEIF7  = (0x01U << Position::TEIF7);
        [[maybe_unused]] constexpr uint32_t DMEIF7 = (0x01U << Position::DMEIF7);
        [[maybe_unused]] constexpr uint32_t FEIF7  = (0x01U << Position::FEIF7);
        [[maybe_unused]] constexpr uint32_t TCIF6  = (0x01U << Position::TCIF6);
        [[maybe_unused]] constexpr uint32_t HTIF6  = (0x01U << Position::HTIF6);
        [[maybe_unused]] constexpr uint32_t TEIF6  = (0x01U << Position::TEIF6);
        [[maybe_unused]] constexpr uint32_t DMEIF6 = (0x01U << Position::DMEIF6);
        [[maybe_unused]] constexpr uint32_t FEIF6  = (0x01U << Position::FEIF6);
        [[maybe_unused]] constexpr uint32_t TCIF5  = (0x01U << Position::TCIF5);
        [[maybe_unused]] constexpr uint32_t HTIF5  = (0x01U << Position::HTIF5);
        [[maybe_unused]] constexpr uint32_t TEIF5  = (0x01U << Position::TEIF5);
        [[maybe_unused]] constexpr uint32_t DMEIF5 = (0x01U << Position::DMEIF5);
        [[maybe_unused]] constexpr uint32_t FEIF5  = (0x01U << Position::FEIF5);
        [[maybe_unused]] constexpr uint32_t TCIF4  = (0x01U << Position::TCIF4);
        [[maybe_unused]] constexpr uint32_t HTIF4  = (0x01U << Position::HTIF4);
        [[maybe_unused]] constexpr uint32_t TEIF4  = (0x01U << Position::TEIF4);
        [[maybe_unused]] constexpr uint32_t DMEIF4 = (0x01U << Position::DMEIF4);
        [[maybe_unused]] constexpr uint32_t FEIF4  = (0x01U << Position::FEIF4);
      }
    }
    
    namespace LIFCR
    {
      namespace Position
      {
        constexpr uint32_t CTCIF3  = 27U;
        constexpr uint32_t CHTIF3  = 26U;
        constexpr uint32_t CTEIF3  = 25U;
        constexpr uint32_t CDMEIF3 = 24U;
        constexpr uint32_t CFEIF3  = 22U;
        constexpr uint32_t CTCIF2  = 21U;
        constexpr uint32_t CHTIF2  = 20U;
        constexpr uint32_t CTEIF2  = 19U;
        constexpr uint32_t CDMEIF2 = 18U;
        constexpr uint32_t CFEIF2  = 16U;
        constexpr uint32_t CTCIF1  = 11U;
        constexpr uint32_t CHTIF1  = 10U;
        constexpr uint32_t CTEIF1  = 9U;
        constexpr uint32_t CDMEIF1 = 8U;
        constexpr uint32_t CFEIF1  = 6U;
        constexpr uint32_t CTCIF0  = 5U;
        constexpr uint32_t CHTIF0  = 4U;
        constexpr uint32_t CTEIF0  = 3U;
        constexpr uint32_t CDMEIF0 = 2U;
        constexpr uint32_t CFEIF0  = 0U;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t CTCIF3  = (0x01U << Position::CTCIF3);
        [[maybe_unused]] constexpr uint32_t CHTIF3  = (0x01U << Position::CHTIF3);
        [[maybe_unused]] constexpr uint32_t CTEIF3  = (0x01U << Position::CTEIF3);
        [[maybe_unused]] constexpr uint32_t CDMEIF3 = (0x01U << Position::CDMEIF3);
        [[maybe_unused]] constexpr uint32_t CFEIF3  = (0x01U << Position::CFEIF3);
        [[maybe_unused]] constexpr uint32_t CTCIF2  = (0x01U << Position::CTCIF2);
        [[maybe_unused]] constexpr uint32_t CHTIF2  = (0x01U << Position::CHTIF2);
        [[maybe_unused]] constexpr uint32_t CTEIF2  = (0x01U << Position::CTEIF2);
        [[maybe_unused]] constexpr uint32_t CDMEIF2 = (0x01U << Position::CDMEIF2);
        [[maybe_unused]] constexpr uint32_t CFEIF2  = (0x01U << Position::CFEIF2);
        [[maybe_unused]] constexpr uint32_t CTCIF1  = (0x01U << Position::CTCIF1);
        [[maybe_unused]] constexpr uint32_t CHTIF1  = (0x01U << Position::CHTIF1);
        [[maybe_unused]] constexpr uint32_t CTEIF1  = (0x01U << Position::CTEIF1);
        [[maybe_unused]] constexpr uint32_t CDMEIF1 = (0x01U << Position::CDMEIF1);
        [[maybe_unused]] constexpr uint32_t CFEIF1  = (0x01U << Position::CFEIF1);
        [[maybe_unused]] constexpr uint32_t CTCIF0  = (0x01U << Position::CTCIF0);
        [[maybe_unused]] constexpr uint32_t CHTIF0  = (0x01U << Position::CHTIF0);
        [[maybe_unused]] constexpr uint32_t CTEIF0  = (0x01U << Position::CTEIF0);
        [[maybe_unused]] constexpr uint32_t CDMEIF0 = (0x01U << Position::CDMEIF0);
        [[maybe_unused]] constexpr uint32_t CFEIF0  = (0x01U << Position::CFEIF0);
      }
    }
    
    namespace HIFCR
    {
      namespace Position
      {
        constexpr uint32_t CTCIF7  = 27U;
        constexpr uint32_t CHTIF7  = 26U;
        constexpr uint32_t CTEIF7  = 25U;
        constexpr uint32_t CDMEIF7 = 24U;
        constexpr uint32_t CFEIF7  = 22U;
        constexpr uint32_t CTCIF6  = 21U;
        constexpr uint32_t CHTIF6  = 20U;
        constexpr uint32_t CTEIF6  = 19U;
        constexpr uint32_t CDMEIF6 = 18U;
        constexpr uint32_t CFEIF6  = 16U;
        constexpr uint32_t CTCIF5  = 11U;
        constexpr uint32_t CHTIF5  = 10U;
        constexpr uint32_t CTEIF5  = 9U;
        constexpr uint32_t CDMEIF5 = 8U;
        constexpr uint32_t CFEIF5  = 6U;
        constexpr uint32_t CTCIF4  = 5U;
        constexpr uint32_t CHTIF4  = 4U;
        constexpr uint32_t CTEIF4  = 3U;
        constexpr uint32_t CDMEIF4 = 2U;
        constexpr uint32_t CFEIF4  = 0U;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t CTCIF7  = (0x01U << Position::CTCIF7);
        [[maybe_unused]] constexpr uint32_t CHTIF7  = (0x01U << Position::CHTIF7);
        [[maybe_unused]] constexpr uint32_t CTEIF7  = (0x01U << Position::CTEIF7);
        [[maybe_unused]] constexpr uint32_t CDMEIF7 = (0x01U << Position::CDMEIF7);
        [[maybe_unused]] constexpr uint32_t CFEIF7  = (0x01U << Position::CFEIF7);
        [[maybe_unused]] constexpr uint32_t CTCIF6  = (0x01U << Position::CTCIF6);
        [[maybe_unused]] constexpr uint32_t CHTIF6  = (0x01U << Position::CHTIF6);
        [[maybe_unused]] constexpr uint32_t CTEIF6  = (0x01U << Position::CTEIF6);
        [[maybe_unused]] constexpr uint32_t CDMEIF6 = (0x01U << Position::CDMEIF6);
        [[maybe_unused]] constexpr uint32_t CFEIF6  = (0x01U << Position::CFEIF6);
        [[maybe_unused]] constexpr uint32_t CTCIF5  = (0x01U << Position::CTCIF5);
        [[maybe_unused]] constexpr uint32_t CHTIF5  = (0x01U << Position::CHTIF5);
        [[maybe_unused]] constexpr uint32_t CTEIF5  = (0x01U << Position::CTEIF5);
        [[maybe_unused]] constexpr uint32_t CDMEIF5 = (0x01U << Position::CDMEIF5);
        [[maybe_unused]] constexpr uint32_t CFEIF5  = (0x01U << Position::CFEIF5);
        [[maybe_unused]] constexpr uint32_t CTCIF4  = (0x01U << Position::CTCIF4);
        [[maybe_unused]] constexpr uint32_t CHTIF4  = (0x01U << Position::CHTIF4);
        [[maybe_unused]] constexpr uint32_t CTEIF4  = (0x01U << Position::CTEIF4);
        [[maybe_unused]] constexpr uint32_t CDMEIF4 = (0x01U << Position::CDMEIF4);
        [[maybe_unused]] constexpr uint32_t CFEIF4  = (0x01U << Position::CFEIF4);
      }
    }
    
    namespace SxCR
    {
      namespace Position
      {
        constexpr uint32_t CHSEL  = 25U;
        constexpr uint32_t MBURST = 23U;
        constexpr uint32_t PBURST = 21U;
        constexpr uint32_t CT     = 19U;
        constexpr uint32_t DBM    = 18U;
        constexpr uint32_t PL     = 16U;
        constexpr uint32_t PINCOS = 15U;
        constexpr uint32_t MSIZE  = 13U;
        constexpr uint32_t PSIZE  = 11U;
        constexpr uint32_t MINC   = 10U;
        constexpr uint32_t PINC   = 9U;
        constexpr uint32_t CIRC   = 8U;
        constexpr uint32_t DIR    = 6U;
        constexpr uint32_t PFCTRL = 5U;
        constexpr uint32_t TCIE   = 4U;
        constexpr uint32_t HTIE   = 3U;
        constexpr uint32_t TEIE   = 2U;
        constexpr uint32_t DMEIE  = 1U;
        constexpr uint32_t EN     = 0U;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t CHSEL  = (0x07U << Position::CHSEL);
        [[maybe_unused]] constexpr uint32_t MBURST = (0x03U << Position::MBURST);
        [[maybe_unused]] constexpr uint32_t PBURST = (0x03U << Position::PBURST);
        [[maybe_unused]] constexpr uint32_t CT     = (0x01U << Position::CT);
        [[maybe_unused]] constexpr uint32_t DBM    = (0x01U << Position::DBM);
        [[maybe_unused]] constexpr uint32_t PL     = (0x03U << Position::PL);
        [[maybe_unused]] constexpr uint32_t PINCOS = (0x01U << Position::PINCOS);
        [[maybe_unused]] constexpr uint32_t MSIZE  = (0x03U << Position::MSIZE);
        [[maybe_unused]] constexpr uint32_t PSIZE  = (0x03U << Position::PSIZE);
        [[maybe_unused]] constexpr uint32_t MINC   = (0x01U << Position::MINC);
        [[maybe_unused]] constexpr uint32_t PINC   = (0x01U << Position::PINC);
        [[maybe_unused]] constexpr uint32_t CIRC   = (0x01U << Position::CIRC);
        [[maybe_unused]] constexpr uint32_t DIR    = (0x03U << Position::DIR);
        [[maybe_unused]] constexpr uint32_t PFCTRL = (0x01U << Position::PFCTRL);
        [[maybe_unused]] constexpr uint32_t TCIE   = (0x01U << Position::TCIE);
        [[maybe_unused]] constexpr uint32_t HTIE   = (0x01U << Position::HTIE);
        [[maybe_unused]] constexpr uint32_t TEIE   = (0x01U << Position::TEIE);
        [[maybe_unused]] constexpr uint32_t DMEIE  = (0x01U << Position::DMEIE);
        [[maybe_unused]] constexpr uint32_t EN     = (0x01U << Position::EN);
      }
    }
    
    namespace SxNDTR
    {
      namespace Position
      {
        constexpr uint32_t NDT = 0U;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t NDR = (0xFFFFU << Position::NDT);
      }
    }
    
    namespace SxPAR
    {
      namespace Position
      {
        constexpr uint32_t PAR = 0U;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t PAR = (0xFFFFFFFFU << Position::PAR);
      }
    }
    
    namespace SxM0AR
    {
      namespace Position
      {
        constexpr uint32_t M0A = 0U;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t M0A = (0xFFFFFFFFU << Position::M0A);
      }
    }
    
    namespace SxM1AR
    {
      namespace Position
      {
        constexpr uint32_t M1A = 0U;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t M1A = (0xFFFFFFFFU << Position::M1A);
      }
    }
    
    namespace SxFCR
    {
      namespace Position
      {
        constexpr uint32_t FEIE  = 7U;
        constexpr uint32_t FS    = 3U;
        constexpr uint32_t DMDIS = 2U;
        constexpr uint32_t FTH   = 0U;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t FEIE  = (0x01U << Position::FEIE );
        [[maybe_unused]] constexpr uint32_t FS    = (0x07U << Position::FS);
        [[maybe_unused]] constexpr uint32_t DMDIS = (0x01U << Position::DMDIS);
        [[maybe_unused]] constexpr uint32_t FTH   = (0x03U << Position::FTH);
      }
    }
  }
  
  struct DMAStream
  {
    volatile uint32_t CR;
    volatile uint32_t NDTR;
    volatile uint32_t PAR;
    volatile uint32_t M0AR;
    volatile uint32_t M1AR;
    volatile uint32_t FCR;
  };
  
  struct DMARegisters
  {
    volatile const uint32_t LISR;
    volatile const uint32_t HISR;
    volatile uint32_t LIFCR;
    volatile uint32_t HIFCR;
    DMAStream stream[8];
  };
  
  static_assert(0x00U == offsetof(DMAStream, CR));
  static_assert(0x04U == offsetof(DMAStream, NDTR));
  static_assert(0x08U == offsetof(DMAStream, PAR));
  static_assert(0x0CU == offsetof(DMAStream, M0AR));
  static_assert(0x10U == offsetof(DMAStream, M1AR));
  static_assert(0x14U == offsetof(DMAStream, FCR));
  
  static_assert(0x00U == offsetof(DMARegisters, LISR));
  static_assert(0x04U == offsetof(DMARegisters, HISR));
  static_assert(0x08U == offsetof(DMARegisters, LIFCR));
  static_assert(0x0CU == offsetof(DMARegisters, HIFCR));
  
  static_assert(0x10U == offsetof(DMARegisters, stream[0]));
  static_assert(0x28U == offsetof(DMARegisters, stream[1]));
  static_assert(0x40U == offsetof(DMARegisters, stream[2]));
  static_assert(0x58U == offsetof(DMARegisters, stream[3]));
  static_assert(0x70U == offsetof(DMARegisters, stream[4]));
  static_assert(0x88U == offsetof(DMARegisters, stream[5]));
  static_assert(0xA0U == offsetof(DMARegisters, stream[6]));
  static_assert(0xB8U == offsetof(DMARegisters, stream[7]));
  
  constexpr uint32_t DMA1Address = 0x40026000U;
  constexpr uint32_t DMA2Address = 0x40026400U;

  const std::array<DMARegisters *, 2U> dmaInstances{{
    reinterpret_cast<DMARegisters *>(DMA1Address),
    reinterpret_cast<DMARegisters *>(DMA2Address)
  }};
  
  void EmptyCallback(DMA::TransferFlags){}
    
  enum class DMAUser
  {
    NONE,
    ADC1,
    ADC2,
    ADC3,
    AES_IN,
    AES_OUT,
    DAC1,
    DAC2,
    I2C1_RX,
    I2C1_TX,
    I2C2_RX,
    I2C2_TX,
    I2C3_RX,
    I2C3_TX,
    QUADSPI,
    SAI1_A,
    SAI1_B,
    SAI2_A,
    SAI2_B,
    SDMMC1,
    SDMMC2,
    SPI1_RX,
    SPI1_TX,
    SPI2_RX,
    SPI2_TX,
    SPI3_RX,
    SPI3_TX,
    SPI4_RX,
    SPI4_TX,
    SPI5_RX,
    SPI5_TX,
    TIM1_CH1,
    TIM1_CH2,
    TIM1_CH3,
    TIM1_CH4,
    TIM1_COM,
    TIM1_TRIG,
    TIM1_UP,
    TIM2_CH1,
    TIM2_CH2,
    TIM2_CH3,
    TIM2_CH4,
    TIM2_UP,
    TIM3_CH1,
    TIM3_CH2,
    TIM3_CH3,
    TIM3_CH4,
    TIM3_TRIG,
    TIM3_UP,
    TIM4_CH1,
    TIM4_CH2,
    TIM4_CH3,
    TIM4_UP,
    TIM5_CH1,
    TIM5_CH2,
    TIM5_CH3,
    TIM5_CH4,
    TIM5_TRIG,
    TIM5_UP,
    TIM6_UP,
    TIM7_UP,
    TIM8_CH1,
    TIM8_CH2,
    TIM8_CH3,
    TIM8_CH4,
    TIM8_COM,
    TIM8_TRIG,
    TIM8_UP,
    UART4_RX,
    UART4_TX,
    UART5_RX,
    UART5_TX,
    UART7_RX,
    UART7_TX,
    UART8_RX,
    UART8_TX,
    USART1_RX,
    USART1_TX,
    USART2_RX,
    USART2_TX,
    USART3_RX,
    USART3_TX,
    USART6_RX,
    USART6_TX
  };
  
  
  
  struct StreamElement
  {
    constexpr StreamElement(DMAUser u1, DMAUser u2, DMAUser u3)
    : users{u1, u2, u3}{}
      
    constexpr StreamElement(DMAUser u1, DMAUser u2)
    : users{u1, u2, DMAUser::NONE}{}
      
    constexpr StreamElement(DMAUser u1)
    : users{u1, DMAUser::NONE, DMAUser::NONE}{}
    
    constexpr StreamElement()
    : users{DMAUser::NONE, DMAUser::NONE, DMAUser::NONE}{}    
    
    const std::array<DMAUser, 3U> users;
  };
  
  using ChannelMap = std::array<StreamElement, 8U>;
  
  constexpr ChannelMap DMA1Channel0Map {{
    {DMAUser::SPI3_RX},
    {},
    {DMAUser::SPI3_RX},
    {DMAUser::SPI2_RX},
    {DMAUser::SPI2_TX},
    {DMAUser::SPI3_TX},
    {},
    {DMAUser::SPI3_TX}
  }};
  
  constexpr ChannelMap DMA1Channel1Map {{
    {DMAUser::I2C1_RX},
    {DMAUser::I2C3_RX},
    {DMAUser::TIM7_UP},
    {},
    {DMAUser::TIM7_UP},
    {DMAUser::I2C1_RX},
    {DMAUser::I2C1_TX},
    {DMAUser::I2C1_TX}
  }};
  
  constexpr ChannelMap DMA1Channel2Map {{
    {DMAUser::TIM4_CH1},
    {},
    {},
    {DMAUser::TIM4_CH2},
    {},
    {},
    {DMAUser::TIM4_UP},
    {DMAUser::TIM4_CH3}
  }};
  
  constexpr ChannelMap DMA1Channel3Map {{
    {},
    {DMAUser::TIM2_UP, DMAUser::TIM2_CH3},
    {DMAUser::I2C3_RX},
    {},
    {DMAUser::I2C3_TX},
    {DMAUser::TIM2_CH1},
    {DMAUser::TIM2_CH2, DMAUser::TIM2_CH4},
    {DMAUser::TIM2_UP, DMAUser::TIM2_CH4}
  }};
  
  constexpr ChannelMap DMA1Channel4Map {{
    {DMAUser::UART5_RX},
    {DMAUser::USART3_RX},
    {DMAUser::UART4_RX},
    {DMAUser::USART3_TX},
    {DMAUser::UART4_TX},
    {DMAUser::USART2_RX},
    {DMAUser::USART2_TX},
    {DMAUser::UART5_TX}
  }};
  
  constexpr ChannelMap DMA1Channel5Map {{
    {DMAUser::UART8_TX},
    {DMAUser::UART7_TX},
    {DMAUser::TIM3_CH4, DMAUser::TIM3_UP},
    {DMAUser::UART7_RX},
    {DMAUser::TIM3_CH1, DMAUser::TIM3_TRIG},
    {DMAUser::TIM3_CH2},
    {DMAUser::UART8_RX},
    {DMAUser::TIM3_CH3}
  }};
  
  constexpr ChannelMap DMA1Channel6Map {{
    {DMAUser::TIM5_CH3, DMAUser::TIM5_UP},
    {DMAUser::TIM5_CH4, DMAUser::TIM5_TRIG},
    {DMAUser::TIM5_CH1},
    {DMAUser::TIM5_CH4, DMAUser::TIM5_TRIG},
    {DMAUser::TIM5_CH2},
    {},
    {DMAUser::TIM5_UP},
    {}
  }};
  
  constexpr ChannelMap DMA1Channel7Map {{
    {},
    {DMAUser::TIM6_UP},
    {DMAUser::I2C2_RX}, 
    {DMAUser::I2C2_RX}, 
    {DMAUser::USART3_TX},
    {DMAUser::DAC1},
    {DMAUser::DAC2},
    {DMAUser::I2C2_TX}
  }};
  
  constexpr ChannelMap DMA2Channel0Map {{
    {DMAUser::ADC1},
    {DMAUser::SAI1_A},
    {DMAUser::TIM8_CH1, DMAUser::TIM8_CH2, DMAUser::TIM8_CH3},
    {DMAUser::SAI1_A},
    {DMAUser::ADC1},
    {DMAUser::SAI1_B},
    {DMAUser::TIM1_CH1, DMAUser::TIM1_CH2, DMAUser::TIM1_CH3},
    {DMAUser::SAI2_B}
  }};
  
  constexpr ChannelMap DMA2Channel1Map {{
    {},
    {},
    {DMAUser::ADC2},
    {DMAUser::ADC2},
    {DMAUser::SAI1_B},
    {},
    {},
    {},
  }};
  
  constexpr ChannelMap DMA2Channel2Map {{
    {DMAUser::ADC3},
    {DMAUser::ADC3},
    {},
    {DMAUser::SPI5_RX},
    {DMAUser::SPI5_TX},
    {DMAUser::AES_OUT},
    {DMAUser::AES_IN},
    {}
  }};
  
  constexpr ChannelMap DMA2Channel3Map {{
    {DMAUser::SPI1_RX}, 
    {},
    {DMAUser::SPI1_RX},
    {DMAUser::SPI1_TX},
    {DMAUser::SAI2_A},
    {DMAUser::SPI1_TX},
    {DMAUser::SAI2_B},
    {DMAUser::QUADSPI},
  }};
  
  constexpr ChannelMap DMA2Channel4Map {{
    {DMAUser::SPI4_RX},
    {DMAUser::SPI4_TX},
    {DMAUser::USART1_RX},
    {DMAUser::SDMMC1},
    {},
    {DMAUser::USART1_RX},
    {DMAUser::SDMMC1},
    {DMAUser::USART1_TX}
  }};
  
  constexpr ChannelMap DMA2Channel5Map {{
    {},
    {DMAUser::USART6_RX}, 
    {DMAUser::USART6_RX}, 
    {DMAUser::SPI4_RX},
    {DMAUser::SPI4_TX},
    {},
    {DMAUser::USART6_TX},
    {DMAUser::USART6_TX},
  }};
  
  constexpr ChannelMap DMA2Channel6Map {{
    {DMAUser::TIM1_TRIG},
    {DMAUser::TIM1_CH1},
    {DMAUser::TIM1_CH2},
    {DMAUser::TIM1_CH1},
    {DMAUser::TIM1_CH4, DMAUser::TIM1_TRIG, DMAUser::TIM1_COM},
    {DMAUser::TIM1_UP},
    {DMAUser::TIM1_CH3},
    {}
  }};
  
  constexpr ChannelMap DMA2Channel7Map {{
    {},
    {DMAUser::TIM8_UP},
    {DMAUser::TIM8_CH1},
    {DMAUser::TIM8_CH2}, 
    {DMAUser::TIM8_CH3}, 
    {DMAUser::SPI5_RX},
    {DMAUser::SPI5_TX},
    {DMAUser::TIM8_CH4, DMAUser::TIM8_TRIG, DMAUser::TIM8_COM}
  }};
  
  //TODO - sort this out, dma2 has more channels
  [[maybe_unused]] constexpr ChannelMap DMA2Channel11Map {{
    {DMAUser::SDMMC2},
    {},
    {},
    {},
    {},
    {DMAUser::SDMMC2},
    {},
    {}
  }};
    
  using RequestMap = std::array<ChannelMap, 8U>;
  constexpr RequestMap DMA1RequestMapping {{
    DMA1Channel0Map,
    DMA1Channel1Map,
    DMA1Channel2Map,
    DMA1Channel3Map,
    DMA1Channel4Map,
    DMA1Channel5Map,
    DMA1Channel6Map,
    DMA1Channel7Map
  }};
  
  constexpr RequestMap DMA2RequestMapping {{
    DMA2Channel0Map,
    DMA2Channel1Map,
    DMA2Channel2Map,
    DMA2Channel3Map,
    DMA2Channel4Map,
    DMA2Channel5Map,
    DMA2Channel6Map,
    DMA2Channel7Map
  }};
  
  [[maybe_unused]] constexpr std::array<RequestMap, 2U> DMARequestMap {{
    DMA1RequestMapping,
    DMA2RequestMapping
  }};
}

DMA::DMA()
{
  std::fill(transferCallbacks_m.begin(), transferCallbacks_m.end(), EmptyCallback);
}
