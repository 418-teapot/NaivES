#ifndef MEM_RAM_H_
#define MEM_RAM_H_

#include "define/type.h"
#include "define/width.h"
#include <cstdint>

namespace mem {

void MemRead(uint16_t IN ram_addr, uint8_t OUT &ram_data);
void MemWrite(uint16_t IN ram_addr, uint8_t IN ram_data);

MemData GetData(IN Imme opnd);
MemData GetData(IN ZPAddr opnd);

} // namespace mem

#endif // MEM_RAM_H_
