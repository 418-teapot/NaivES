#include "mem/mem.h"

namespace mem {

void Mem::reset() {
  for (uint8_t entry : ram) {
    entry = 0;
  };
}

void Mem::read(uint16_t ram_addr, uint8_t OUT &ram_data) {
  ram_data = ram[ram_addr];
}

void Mem::write(uint16_t ram_addr, uint8_t IN &ram_data) {
  ram[ram_addr] = ram_data;
}

} // namespace mem
