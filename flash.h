#ifndef flash_h
#define flash_h

#include <cstdint>

class Flash
{
public:
  static void EnablePrefetch();
  static void EnableARTAccelerator();
  static void SetWaitStates(uint32_t waitStates);
};

#endif
