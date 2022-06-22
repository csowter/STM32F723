#ifndef i2c_h
#define i2c_h


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
  
private:
  I2CPort instance_m;  
};

#endif
