#ifndef usart_h
#define usart_h

#include <cstdint>

class USART
{
public:
  enum class Instance
  {
    USART1,
    USART2,
    USART3,
    UART4,
    UART5,
    USART6,
    UART7,
    UART8
  };
  
  enum class StopBits
  {
    ZeroPointFive,
    One,
    OnePointFive,
    Two
  };
  
  enum class DataBits
  {
    Seven,
    Eight,
    Nine
  };
  
  USART(Instance instance);
  void SetBaudRate(uint32_t baudRate, uint32_t peripheralClock);
  void ConfigureFrame(DataBits dataBits, StopBits stopBits);
  
  void Transmit(const uint8_t *txData, uint32_t length);
  
private:
  void EnableUSART(bool enable);
  void EnableTransmission(bool enable);

  const Instance instance_m;
};

#endif
