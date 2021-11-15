#include "mem/mem.h"
#include "define/width.h"

namespace mem {

static uint8_t kRam[MEM_SIZE];

void MemRead(IN uint16_t ram_addr, OUT uint8_t &ram_data) {
  if (ram_addr < TOTAL_RAM_SIZE) {
    ram_data = kRam[ram_addr & RAM_MASK];
    return;
  }
}

void MemWrite(IN uint16_t ram_addr, IN uint8_t ram_data) {
  if (ram_addr < TOTAL_RAM_SIZE) {
    kRam[ram_addr & RAM_MASK] = ram_data;
    return;
  }
}

MemData GetData(IN Imme opnd) {
  return (MemData){opnd.data, (uint16_t)0xFFFF, 0, sizeof(opnd.data)};
}

MemData GetData(IN ZPAddr opnd) {
  uint8_t data;
  MemRead((uint16_t)opnd.addr, data);
  return (MemData){data, (uint16_t)opnd.addr, 1, sizeof(opnd.addr)};
}

MemData GetData(IN RelAddr opnd) {
  return (MemData){0, (uint16_t)(opnd.addr), 0, sizeof(opnd.addr)};
}

} // namespace mem
