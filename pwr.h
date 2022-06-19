#ifndef pwr_h
#define pwr_h

class PWR
{
public:
  enum class VoltageScale
  {
    Scale1,
    Scale2,
    Scale3
  };

  static void EnableOverdrive();
  static void SetVoltageScale(VoltageScale voltageScale);
};

#endif
