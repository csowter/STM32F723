#ifndef dma_h
#define dma_h

#include <cstddef>
#include <array>
#include <functional>
#include <utility>

class DMA
{
public:
  enum class DataSize
  {
    EightBit,
    SixteenBit,
    ThirtyTwoBit
  };
  
  enum class TransferType
  {
    MemoryToPeripheral,
    MemoryToMemory,
    PeripheralToMemory
  };
  
  enum class TransferFlags
  {
    HalfTransfer,
    TransferComplete,
    TransferError,
    FIFOError,
    DirectModeError
  };
  
  using TransferCallback = std::function<void(DMA::TransferFlags)>;
  
  DMA();
  
 // bool PerformTransfer(void *sourceAddress,  void *destinationAddress, 
 //                             DataSize sourceSize, DataSize destinationSize,
 //                             TransferType type, std::size_t dataCount,
 //                             TransferCallback callback){return false;}
 //                             
  
private:
  std::array<TransferCallback, 16U> transferCallbacks_m;
};

#endif
