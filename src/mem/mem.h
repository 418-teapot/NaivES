#ifndef MEM_MEM_H_
#define MEM_MEM_H_

#include <cstdint>
#include "define/type.h"
#include "define/width.h"

namespace mem {

void MemRead(IN uint16_t ram_addr, OUT uint8_t &ram_data);
void MemWrite(IN uint16_t ram_addr, IN uint8_t ram_data);

MemData GetData(IN Imme opnd);
MemData GetData(IN ZPAddr opnd);
MemData GetData(IN RelAddr opnd);

} // namespace mem

#endif // MEM_MEM_H_
