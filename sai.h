#ifndef sai_h
#define sai_h

#include <cstdint>

class SAI
{
public:
  enum class Port
  {
    SAI1,
    SAI2
  };
  
  enum class Block
  {
    A,
    B
  };
  
  enum class Mode
  {
    MasterTransmitter,
    MasterReceiver,
    SlaveTransmitter,
    SlaveReceiver
  };
  
  enum class DataSize
  {
    DS_8Bit,
    DS_10Bit,
    DS_16Bit,
    DS_20Bit,
    DS_24Bit,
    DS_32Bit
  };
  
  enum class FirstBit
  {
    MSB,
    LSB
  };
  
  enum class FrameSyncEdge
  {
    Rising,
    Falling
  };
  
  enum class FrameSyncOffset 
  {
    LastBit,
    FirstBit
  };
  
  enum class FrameSyncRole
  {
    StartOfFrame,
    StartOfFrameAndChannelSide
  };
  
  enum class SlotSize
  {
    sz_DataSize,
    sz_16Bit,
    sz_32Bit
  };
  
  SAI(Port port);
  void SetMode(Block block, Mode mode);
  void Enable(Block block);
  void Disable(Block block);
  void SetDataSize(Block block, DataSize size);
  void SetFirstBit(Block block, FirstBit bit);
  void SetFrameLength(Block block, uint16_t length);
  void SetFrameSynchronizationPolarity(Block block, FrameSyncEdge edge);
  void SetFrameSynchronizationActiveLevelLength(Block block, uint8_t clockCycleCount);
  void SetFrameSynchronizationOffset(Block block, FrameSyncOffset offset);
  void SetFrameSynchronizationSignalRole(Block block, FrameSyncRole role);
  void SetSlotConfiguration(Block block, uint8_t numberOfSlots, SlotSize slotSize);
  
private:
  Port port_m;
};

#endif
