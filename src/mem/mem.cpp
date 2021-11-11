#include "mem/mem.h"

namespace mem {

static uint8_t kRam[RAM_SIZE];

void MemRead(IN uint16_t ram_addr, OUT uint8_t &ram_data) {
  ram_data = kRam[ram_addr];
}

void MemWrite(IN uint16_t ram_addr, IN uint8_t ram_data) {
  kRam[ram_addr] = ram_data;
}

MemData GetData(IN Imme opnd) {
  return (MemData){opnd.data, (uint16_t)0xFFFF, (uint32_t)0, sizeof(opnd.data)};
}

MemData GetData(IN ZPAddr opnd) {
  uint8_t data;
  MemRead((uint16_t)opnd.addr, data);
  return (MemData){data, (uint16_t)opnd.addr, (uint32_t)1, sizeof(opnd.addr)};
}

} // namespace mem
