#include "define/type.h"
#include "define/width.h"
#include "mem/mem.h"
#include <cstdint>

namespace mem {

static uint8_t kRam[RAM_SIZE];

void MemRead(uint16_t IN ram_addr, uint8_t OUT &ram_data) {
  ram_data = kRam[ram_addr];
}

void MemWrite(uint16_t IN ram_addr, uint8_t IN ram_data) {
  kRam[ram_addr] = ram_data;
}

} // namespace mem
