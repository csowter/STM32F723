#include "i2c.h"
#include <cstddef>
#include <array>

namespace
{
  namespace Registers
  {
    namespace CR1
    {
      namespace Position
      {
        constexpr uint32_t PECEN    = 23UL;
        constexpr uint32_t ALERTEN  = 22UL;
        constexpr uint32_t SMBDEN   = 21UL;
        constexpr uint32_t SMBHEN   = 20UL;
        constexpr uint32_t GCEN     = 19UL;
        constexpr uint32_t NOSTRECH = 17UL;
        constexpr uint32_t SBC      = 16UL;
        constexpr uint32_t RXDMAEN  = 15UL;
        constexpr uint32_t TXDMAEN  = 14UL;
        constexpr uint32_t ANFOFF   = 12UL;
        constexpr uint32_t DNF      = 8UL;
        constexpr uint32_t ERRIE    = 7UL;
        constexpr uint32_t TCIE     = 6UL;
        constexpr uint32_t STOPIE   = 5UL;
        constexpr uint32_t NACKIE   = 4UL;
        constexpr uint32_t ADDRIE   = 3UL;
        constexpr uint32_t RXIE     = 2UL;
        constexpr uint32_t TXIE     = 1UL;
        constexpr uint32_t PE       = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t PECEN    = (0x01UL << Position::PECEN);
        [[maybe_unused]] constexpr uint32_t ALERTEN  = (0x01UL << Position::ALERTEN);
        [[maybe_unused]] constexpr uint32_t SMBDEN   = (0x01UL << Position::SMBDEN);
        [[maybe_unused]] constexpr uint32_t SMBHEN   = (0x01UL << Position::SMBHEN);
        [[maybe_unused]] constexpr uint32_t GCEN     = (0x01UL << Position::GCEN);
        [[maybe_unused]] constexpr uint32_t NOSTRECH = (0x01UL << Position::NOSTRECH);
        [[maybe_unused]] constexpr uint32_t SBC      = (0x01UL << Position::SBC);
        [[maybe_unused]] constexpr uint32_t RXDMAEN  = (0x01UL << Position::RXDMAEN);
        [[maybe_unused]] constexpr uint32_t TXDMAEN  = (0x01UL << Position::TXDMAEN);
        [[maybe_unused]] constexpr uint32_t ANFOFF   = (0x01UL << Position::ANFOFF);
        [[maybe_unused]] constexpr uint32_t DNF      = (0x0FUL << Position::DNF);
        [[maybe_unused]] constexpr uint32_t ERRIE    = (0x01UL << Position::ERRIE);
        [[maybe_unused]] constexpr uint32_t TCIE     = (0x01UL << Position::TCIE);
        [[maybe_unused]] constexpr uint32_t STOPIE   = (0x01UL << Position::STOPIE);
        [[maybe_unused]] constexpr uint32_t NACKIE   = (0x01UL << Position::NACKIE);
        [[maybe_unused]] constexpr uint32_t ADDRIE   = (0x01UL << Position::ADDRIE);
        [[maybe_unused]] constexpr uint32_t RXIE     = (0x01UL << Position::RXIE);
        [[maybe_unused]] constexpr uint32_t TXIE     = (0x01UL << Position::TXIE);
        [[maybe_unused]] constexpr uint32_t PE       = (0x01UL << Position::PE);
      }
    }
    
    namespace CR2
    {
      namespace Position
      {
        constexpr uint32_t PECBYTE = 26UL;
        constexpr uint32_t AUTOEND = 25UL;
        constexpr uint32_t RELOAD  = 24UL;
        constexpr uint32_t NBYTES  = 16UL;
        constexpr uint32_t NACK    = 15UL;
        constexpr uint32_t STOP    = 14UL;
        constexpr uint32_t START   = 13UL;
        constexpr uint32_t HEAD10R = 12UL;
        constexpr uint32_t ADD10   = 11UL;
        constexpr uint32_t RD_WRN  = 10UL;
        constexpr uint32_t SADD    = 0UL;
        constexpr uint32_t SADD10  = 0UL;
        constexpr uint32_t SADD7   = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t PECBYTE = (0x01UL << Position::PECBYTE);
        [[maybe_unused]] constexpr uint32_t AUTOEND = (0x01UL << Position::AUTOEND);
        [[maybe_unused]] constexpr uint32_t RELOAD  = (0x01UL << Position::RELOAD );
        [[maybe_unused]] constexpr uint32_t NBYTES  = (0xFFUL << Position::NBYTES);
        [[maybe_unused]] constexpr uint32_t NACK    = (0x01UL << Position::NACK);
        [[maybe_unused]] constexpr uint32_t STOP    = (0x01UL << Position::STOP);
        [[maybe_unused]] constexpr uint32_t START   = (0x01UL << Position::START);
        [[maybe_unused]] constexpr uint32_t HEAD10R = (0x01UL << Position::HEAD10R);
        [[maybe_unused]] constexpr uint32_t ADD10   = (0x01UL << Position::ADD10);
        [[maybe_unused]] constexpr uint32_t RD_WRN  = (0x01UL << Position::RD_WRN);
        [[maybe_unused]] constexpr uint32_t SADD    = (0x3FFUL << Position::SADD);
      }
    }
    
    namespace OAR1
    {
      namespace Position
      {
        constexpr uint32_t OA1EN     = 15UL;
        constexpr uint32_t OA1MODE   = 10UL;
        constexpr uint32_t OA1_7BIT  = 1UL;
        constexpr uint32_t OA1_10BIT = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t OA1EN     = (0x01UL << Position::OA1EN);
        [[maybe_unused]] constexpr uint32_t OA1MODE   = (0x01UL << Position::OA1MODE);
        [[maybe_unused]] constexpr uint32_t OA1_7BIT  = (0x7FUL << Position::OA1_7BIT);
        [[maybe_unused]] constexpr uint32_t OA1_10BIT = (0x3FFUL << Position::OA1_10BIT);
      }
    }
    
    namespace OAR2
    {
      namespace Position
      {
        constexpr uint32_t OA2EN  = 15UL;
        constexpr uint32_t OA2MSK = 8UL;
        constexpr uint32_t OA2    = 1UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t OA2EN  = (0x01UL << Position::OA2EN);
        [[maybe_unused]] constexpr uint32_t OA2MSK = (0x07UL << Position::OA2MSK);
        [[maybe_unused]] constexpr uint32_t OA2    = (0x7FUL << Position::OA2);
      }
    }
    
    namespace TIMINGR
    {
      namespace Position
      {
        constexpr uint32_t PRESC  = 28UL;
        constexpr uint32_t SCLDEL = 20UL;
        constexpr uint32_t SDADEL = 16UL;
        constexpr uint32_t SCLH   = 8UL;
        constexpr uint32_t SCLL   = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t PRESC  = (0x0FUL << Position::PRESC);
        [[maybe_unused]] constexpr uint32_t SCLDEL = (0x0FUL << Position::SCLDEL);
        [[maybe_unused]] constexpr uint32_t SDADEL = (0x0FUL << Position::SDADEL);
        [[maybe_unused]] constexpr uint32_t SCLH   = (0xFFUL << Position::SCLH);
        [[maybe_unused]] constexpr uint32_t SCLL   = (0xFFUL << Position::SCLL);
      }
    }
    
    namespace TIMEOUTR
    {
      namespace Position
      {
        constexpr uint32_t TEXTEN    = 31UL;
        constexpr uint32_t TIMEOUTB  = 16UL;
        constexpr uint32_t TIMEOUTEN = 15UL;
        constexpr uint32_t TIDLE     = 12UL;
        constexpr uint32_t TIMEOUTA  = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t TEXTEN    = (0x01UL << Position::TEXTEN);
        [[maybe_unused]] constexpr uint32_t TIMEOUTB  = (0xFFFUL << Position::TIMEOUTB);
        [[maybe_unused]] constexpr uint32_t TIMEOUTEN = (0x01UL << Position::TIMEOUTEN);
        [[maybe_unused]] constexpr uint32_t TIDLE     = (0x01UL << Position::TIDLE);
        [[maybe_unused]] constexpr uint32_t TIMEOUTA  = (0xFFFUL << Position::TIMEOUTA);
      }
    }
    
    namespace ISR
    {
      namespace Position
      {
        constexpr uint32_t ADDCODE = 17UL;
        constexpr uint32_t DIR     = 16UL;
        constexpr uint32_t BUSY    = 15UL;
        constexpr uint32_t ALERT   = 13UL;
        constexpr uint32_t TIMEOUT = 12UL;
        constexpr uint32_t PECERR  = 11UL;
        constexpr uint32_t OVR     = 10UL;
        constexpr uint32_t ARLO    = 9UL;
        constexpr uint32_t BERR    = 8UL;
        constexpr uint32_t TCR     = 7UL;
        constexpr uint32_t TC      = 6UL;
        constexpr uint32_t STOPF   = 5UL;
        constexpr uint32_t NACKF   = 4UL;
        constexpr uint32_t ADDR    = 3UL;
        constexpr uint32_t RXNE    = 2UL;
        constexpr uint32_t TXIS    = 1UL;
        constexpr uint32_t TXE     = 0UL;
      }

      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t ADDCODE = (0x7FUL << Position::ADDCODE);
        [[maybe_unused]] constexpr uint32_t DIR     = (0x01UL << Position::DIR);
        [[maybe_unused]] constexpr uint32_t BUSY    = (0x01UL << Position::BUSY);
        [[maybe_unused]] constexpr uint32_t ALERT   = (0x01UL << Position::ALERT);
        [[maybe_unused]] constexpr uint32_t TIMEOUT = (0x01UL << Position::TIMEOUT);
        [[maybe_unused]] constexpr uint32_t PECERR  = (0x01UL << Position::PECERR);
        [[maybe_unused]] constexpr uint32_t OVR     = (0x01UL << Position::OVR);
        [[maybe_unused]] constexpr uint32_t ARLO    = (0x01UL << Position::ARLO);
        [[maybe_unused]] constexpr uint32_t BERR    = (0x01UL << Position::BERR);
        [[maybe_unused]] constexpr uint32_t TCR     = (0x01UL << Position::TCR);
        [[maybe_unused]] constexpr uint32_t TC      = (0x01UL << Position::TC);
        [[maybe_unused]] constexpr uint32_t STOPF   = (0x01UL << Position::STOPF);
        [[maybe_unused]] constexpr uint32_t NACKF   = (0x01UL << Position::NACKF);
        [[maybe_unused]] constexpr uint32_t ADDR    = (0x01UL << Position::ADDR);
        [[maybe_unused]] constexpr uint32_t RXNE    = (0x01UL << Position::RXNE);
        [[maybe_unused]] constexpr uint32_t TXIS    = (0x01UL << Position::TXIS);
        [[maybe_unused]] constexpr uint32_t TXE     = (0x01UL << Position::TXE);
      }
    }
    
    namespace ICR
    {
      namespace Position
      {
        constexpr uint32_t ALERTCF  = 13UL;
        constexpr uint32_t TIMOUTCF = 12UL;
        constexpr uint32_t PECCF    = 11UL;
        constexpr uint32_t OVRCF    = 10UL;
        constexpr uint32_t ARLOCF   = 9UL;
        constexpr uint32_t BERRCF   = 8UL;
        constexpr uint32_t STOPCF   = 5UL;
        constexpr uint32_t NACKCF   = 4UL;
        constexpr uint32_t ADDRCF   = 3UL;
      }

      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t ALERTCF  = (0x01UL << Position::ALERTCF);
        [[maybe_unused]] constexpr uint32_t TIMOUTCF = (0x01UL << Position::TIMOUTCF);
        [[maybe_unused]] constexpr uint32_t PECCF    = (0x01UL << Position::PECCF);
        [[maybe_unused]] constexpr uint32_t OVRCF    = (0x01UL << Position::OVRCF);
        [[maybe_unused]] constexpr uint32_t ARLOCF   = (0x01UL << Position::ARLOCF);
        [[maybe_unused]] constexpr uint32_t BERRCF   = (0x01UL << Position::BERRCF);
        [[maybe_unused]] constexpr uint32_t STOPCF   = (0x01UL << Position::STOPCF);
        [[maybe_unused]] constexpr uint32_t NACKCF   = (0x01UL << Position::NACKCF);
        [[maybe_unused]] constexpr uint32_t ADDRCF   = (0x01UL << Position::ADDRCF);
      }
    }
    
    namespace PECR
    {
      namespace Position
      {
        constexpr uint32_t PEC = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t PEC = (0xFFUL << Position::PEC);
      }
    }
    
    namespace RXDR
    {
      namespace Position
      {
        constexpr uint32_t RXDATA = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t RXDATA = (0xFFUL << Position::RXDATA);
      }
    }
    
    namespace TXDR
    {
      namespace Position
      {
        constexpr uint32_t TXDATA = 0UL;
      }
      
      namespace Mask
      {
        [[maybe_unused]] constexpr uint32_t TXDATA = (0xFFUL << Position::TXDATA);
      }
    }
  }
  
  struct I2CRegisters
  {
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t OAR1;
    volatile uint32_t OAR2;
    volatile uint32_t TIMINGR;
    volatile uint32_t TIMEOUTR;
    volatile uint32_t ISR;
    volatile uint32_t ICR;
    const volatile uint32_t PECR;
    const volatile uint32_t RXDR;
    volatile uint32_t TXDR;    
  };
  
  static_assert(0x00UL == offsetof(I2CRegisters, CR1));
  static_assert(0x04UL == offsetof(I2CRegisters, CR2));
  static_assert(0x08UL == offsetof(I2CRegisters, OAR1));
  static_assert(0x0CUL == offsetof(I2CRegisters, OAR2));
  static_assert(0x10UL == offsetof(I2CRegisters, TIMINGR));
  static_assert(0x14UL == offsetof(I2CRegisters, TIMEOUTR));
  static_assert(0x18UL == offsetof(I2CRegisters, ISR));
  static_assert(0x1CUL == offsetof(I2CRegisters, ICR));
  static_assert(0x20UL == offsetof(I2CRegisters, PECR));
  static_assert(0x24UL == offsetof(I2CRegisters, RXDR));
  static_assert(0x28UL == offsetof(I2CRegisters, TXDR));
  
  constexpr uint32_t I2C1BaseAddress = 0x40005400UL;
  constexpr uint32_t I2C2BaseAddress = 0x40005800UL;
  constexpr uint32_t I2C3BaseAddress = 0x40005C00UL;
  
  const std::array<I2CRegisters *, 3UL> I2CPorts{
    reinterpret_cast<I2CRegisters *>( I2C1BaseAddress ), 
    reinterpret_cast<I2CRegisters *>( I2C2BaseAddress ),
    reinterpret_cast<I2CRegisters *>( I2C3BaseAddress ),
  };
  
  I2CRegisters * I2CInstance(I2C::I2CPort port)
  {
    return I2CPorts[static_cast<std::size_t>(port)];
  }
  
  std::array<I2C *, 3UL> I2CInstances{
    nullptr,
    nullptr,
    nullptr
  };
}

I2C::I2C(I2CPort i2cInstance)
: instance_m{i2cInstance}
{
  I2CInstances[static_cast<std::size_t>(instance_m)] = this;
}

void I2C::ConfigureTiming(uint32_t clockPrescaler, uint32_t setupTime, 
            uint32_t holdTime, uint32_t highPeriod, uint32_t lowPeriod)
{
  const uint32_t prescaler = ((clockPrescaler << Registers::TIMINGR::Position::PRESC) & Registers::TIMINGR::Mask::PRESC);
  const uint32_t setup = ((setupTime << Registers::TIMINGR::Position::SCLDEL) & Registers::TIMINGR::Mask::SCLDEL);
  const uint32_t hold = ((holdTime << Registers::TIMINGR::Position::SDADEL) & Registers::TIMINGR::Mask::SDADEL);
  const uint32_t high = ((highPeriod << Registers::TIMINGR::Position::SCLH) & Registers::TIMINGR::Mask::SCLH);
  const uint32_t low = ((lowPeriod << Registers::TIMINGR::Position::SCLL) & Registers::TIMINGR::Mask::SCLL);
  
  const uint32_t timingValue = prescaler | setup | hold | high | low;
  
  I2CRegisters *registers = I2CInstance(instance_m);
  registers->TIMINGR = timingValue;
}

void I2C::SetEnabled(bool enabled)
{
  I2CRegisters *registers = I2CInstance(instance_m);
  
  if(true == enabled)
  {
    registers->CR1 |= Registers::CR1::Mask::PE;
  }
  else
  {
    registers->CR1 &= ~Registers::CR1::Mask::PE;
  }
}

void I2C::Write(uint32_t address, bool isAddress7Bit, const uint8_t *data, uint32_t length)
{
  I2CRegisters *registers = I2CInstance(instance_m);
  
  registers->CR2 &= ~(Registers::CR2::Mask::SADD |
                      Registers::CR2::Mask::RD_WRN |
                      Registers::CR2::Mask::NBYTES);
  registers->CR2 |= (length << Registers::CR2::Position::NBYTES) |
                    (Registers::CR2::Mask::AUTOEND);
  
  if(true == isAddress7Bit)
  {
    registers->CR2 &= ~Registers::CR2::Mask::ADD10;
    registers->CR2 |= (address << Registers::CR2::Position::SADD7);
  }
  else
  {
    registers->CR2 |= Registers::CR2::Mask::ADD10;    
    registers->CR2 |= (address << Registers::CR2::Position::SADD10);
  }
  
  registers->CR2 |= Registers::CR2::Mask::START;
  
  for(uint32_t i = 0; i < length; i++)
  {
    while(Registers::ISR::Mask::TXIS != (registers->ISR & Registers::ISR::Mask::TXIS));
    registers->TXDR = data[i];
  }
  
  while(Registers::ISR::Mask::STOPF != (registers->ISR & Registers::ISR::Mask::STOPF)); //wait for stop to send
  registers->ICR = Registers::ICR::Mask::STOPCF;
}

void I2C::Read(uint32_t address, bool isAddress7Bit, uint8_t *rxBuffer, uint32_t length)
{
  I2CRegisters *registers = I2CInstance(instance_m);
  
  registers->CR2 &= ~(Registers::CR2::Mask::SADD |
                      Registers::CR2::Mask::RD_WRN |
                      Registers::CR2::Mask::NBYTES);
  registers->CR2 |= (length << Registers::CR2::Position::NBYTES) |
                    (Registers::CR2::Mask::AUTOEND) |
                    (Registers::CR2::Mask::RD_WRN);
  
  if(true == isAddress7Bit)
  {
    registers->CR2 &= ~Registers::CR2::Mask::ADD10;
    registers->CR2 |= (address << Registers::CR2::Position::SADD7);
  }
  else
  {
    registers->CR2 |= Registers::CR2::Mask::ADD10;    
    registers->CR2 |= (address << Registers::CR2::Position::SADD10);
  }
  
  registers->CR2 |= Registers::CR2::Mask::START;
  
  for(uint32_t i = 0; i < length; i++)
  {
    while(Registers::ISR::Mask::RXNE != (registers->ISR & Registers::ISR::Mask::RXNE));
    rxBuffer[i] = static_cast<uint8_t>(registers->RXDR);
  }
}
