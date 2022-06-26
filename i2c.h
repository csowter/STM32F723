#ifndef i2c_h
#define i2c_h
#include <cstdint>

class I2C
{
public:
  enum class I2CPort
  {
    I2C1,
    I2C2,
    I2C3
  };
  
  I2C(I2CPort i2cInstance);
  void ConfigureTiming(uint32_t clockPrescaler, uint32_t setupTime, 
            uint32_t holdTime, uint32_t highPeriod, uint32_t lowPeriod);
  void SetEnabled(bool enabled);
  
  void Write(uint32_t address, bool isAddress7Bit, const uint8_t *data, uint32_t length);
  void Read(uint32_t address, bool isAddress7Bit, uint8_t *rxBuffer, uint32_t length);
  
private:
  I2CPort instance_m;  
};

#endif
