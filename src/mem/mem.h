#ifndef MEM_RAM_H_
#define MEM_RAM_H_

#include "define/type.h"
#include "define/width.h"
#include <cstdint>

namespace mem {

void MemRead(IN uint16_t ram_addr, OUT uint8_t &ram_data);
void MemWrite(IN uint16_t ram_addr, IN uint8_t ram_data);

MemData GetData(IN Imme opnd);
MemData GetData(IN ZPAddr opnd);
MemData GetData(IN RelAddr opnd);

} // namespace mem

#endif // MEM_RAM_H_
