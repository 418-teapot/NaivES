#include "mem/mem.h"

namespace mem {

void Mem::read(uint16_t ram_addr, uint8_t OUT &ram_data) {
  ram_data = ram[ram_addr];
}

void Mem::write(uint16_t ram_addr, uint8_t IN &ram_data) {
  ram[ram_addr] = ram_data;
}

} // namespace mem
