#include "gpio.h"

GPIO::GPIO(Port port, Pin pin)
: port_m{port}
, pin_m{pin}
{}
  
void GPIO::SetMode(Mode mode)
{}

void GPIO::SetSpeed(Speed speed)
{}

void GPIO::SetAlternateFunction(AlternateFunction af)
{}

void GPIO::SetOutputState(State state)
{}

GPIO::State GPIO::GetInputState()
{
  return State::High;
}