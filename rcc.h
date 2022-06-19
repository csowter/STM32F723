#ifndef rcc_h
#define rcc_h

#include <cstdint>

class RCC
{
public:
  enum class SystemClockSource
  {
    HSIOscillator,
    HSEOscillator,
    PLL
  };
  
  enum class PLLClockSource
  {
    HSIOscillator,
    HSEOscillator
  };
  
  enum class APBDivider
  {
    AHBClockDiv1,
    AHBClockDiv2,
    AHBClockDiv4,
    AHBClockDiv8,
    AHBClockDiv16
  };
  
  enum class AHBDivider
  {
    SystemClockDiv1,
    SystemClockDiv2,
    SystemClockDiv4,
    SystemClockDiv8,
    SystemClockDiv16,
    SystemClockDiv64,
    SystemClockDiv128,
    SystemClockDiv256,
    SystemClockDiv512
  };

  static void EnableHSE(bool bypass);
  static void EnablePLL();
  static bool PLLReady();
  static void SetClockSource(SystemClockSource clockSource);
  static void ConfigurePLL(uint32_t PLLQ, uint32_t PLLP, uint32_t PLLN, uint32_t PLLM, PLLClockSource clockSource);
  static void ConfigureBusDividers(APBDivider apb1Divider, APBDivider apb2Divider, AHBDivider ahbDivider);
};
#endif
