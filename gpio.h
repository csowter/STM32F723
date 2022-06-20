#ifndef gpio_h
#define gpio_h

class GPIO
{
public:
  enum class Port {
    GPIOA,
    GPIOB,
    GPIOC,
    GPIOD,
    GPIOE,
    GPIOF,
    GPIOG,
    GPIOH,
    GPIOI
  };
  
  enum class Pin {
    Pin0,
    Pin1,
    Pin2,
    Pin3,
    Pin4,
    Pin5,
    Pin6,
    Pin7,
    Pin8,
    Pin9,
    Pin10,
    Pin11,
    Pin12,
    Pin13,
    Pin14,
    Pin15
  };
  
  enum class Mode
  {
    Input,
    Output,
    AlternateFunction,
    Analogue
  };
  
  enum class Speed
  {
    Low,
    Medium,
    High,
    VeryHigh
  };
  
  enum class AlternateFunction
  {
    AF0,
    AF1,
    AF2,
    AF3,
    AF4,
    AF5,
    AF6,
    AF7,
    AF8,
    AF9,
    AF10,
    AF11,
    AF12,
    AF13,
    AF14,
    AF15
  };
  
  enum class State
  {
    High,
    Low
  };
  
  GPIO(Port port, Pin pin);
  void SetMode(Mode mode);
  void SetSpeed(Speed speed);
  void SetAlternateFunction(AlternateFunction af);
  
  void SetOutputState(State state);
  State GetInputState();
  
private:
  const Port port_m;
  const Pin pin_m;
};

#endif
