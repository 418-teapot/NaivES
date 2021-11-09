#include "mem/mem.h"

namespace mem {

static uint8_t kRam[RAM_SIZE];

void MemRead(uint16_t IN ram_addr, uint8_t OUT &ram_data) {
  ram_data = kRam[ram_addr];
}

void MemWrite(uint16_t IN ram_addr, uint8_t IN ram_data) {
  kRam[ram_addr] = ram_data;
}

MemData GetData(IN Imme opnd) {
  return (MemData){opnd.data, (uint32_t)0, sizeof(opnd.data)};
}

MemData GetData(IN ZPAddr opnd) {
  uint8_t data;
  MemRead((uint16_t)opnd.addr, data);
  return (MemData){data, (uint32_t)1, sizeof(opnd.addr)};
}

} // namespace mem
