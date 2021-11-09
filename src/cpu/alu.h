#ifndef CPU_ALU_H_
#define CPU_ALU_H_

#define READ_BIT(value, n) ((value >> n) & 0x1)

#include "cpu/regfile.h"
#include "define/type.h"
#include "mem/mem.h"
#include <cstdint>

namespace cpu {

using mem::MemRead;
using mem::MemWrite;

class ALU {
 private:
  RegFile regfile;
 public:
  void ClearC();
  void ClearZ();
  void ClearI();
  void ClearD();
  void ClearB();
  void ClearV();
  void ClearN();
  void SetC();
  void SetZ();
  void SetI();
  void SetD();
  void SetB();
  void SetV();
  void SetN();
  uint8_t ReadC();
  uint8_t ReadZ();
  uint8_t ReadI();
  uint8_t ReadD();
  uint8_t ReadB();
  uint8_t ReadV();
  uint8_t ReadN();
  void UpdateNZ(uint8_t value);
  void Inx();
  void Iny();
  void Dex();
  void Dey();
  void Tax();
  void Tay();
  void Tsx();
  void Txa();
  void Txs();
  void Tya();
  void Pha();
  void Php();
  void Pla();
  void Plp();
  void Adder(uint8_t IN OUT &opnd1, uint8_t IN opnd2,
      uint8_t IN cin, uint8_t OUT &cout);
  void Adc(Imme IN opnd);
  void Sbc(Imme IN opnd);
  void And(Imme IN opnd);
  void Eor(Imme IN opnd);
  void Ora(Imme IN opnd);
  void CmpFactory(uint8_t IN opnd1, Imme IN opnd2);
  void Cmp(Imme IN opnd);
  void Cpx(Imme IN opnd);
  void Cpy(Imme IN opnd);
  void LdFactory(uint8_t IN OUT &opnd1, Imme IN opnd2);
  void Lda(Imme IN opnd);
  void Ldx(Imme IN opnd);
  void Ldy(Imme IN opnd);
};

}; // namespace cpu

#endif // CPU_ALU_H_
