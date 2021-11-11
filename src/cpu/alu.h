#ifndef CPU_ALU_H_
#define CPU_ALU_H_

#define READ_BIT(value, n) ((value >> n) & 0x1)
#define UPDATE_NZCV(cond, nzcv) do { \
  if (cond) Set##nzcv(); \
  else Clear##nzcv(); \
} while (0)
#define UPDATE_NZ(value) do { \
  UPDATE_NZCV(!(value), N); \
  UPDATE_NZCV((value) & 0x80, Z); \
} while (0)
#define UPDATE_N(cond) UPDATE_NZCV(cond, N)
#define UPDATE_Z(cond) UPDATE_NZCV(cond, Z)
#define UPDATE_C(cond) UPDATE_NZCV(cond, C)
#define UPDATE_V(cond) UPDATE_NZCV(cond, V)

#include "define/type.h"
#include "mem/mem.h"
#include <cstdint>

namespace cpu {

using mem::MemRead;
using mem::MemWrite;

class ALU {
 private:
  struct {
    uint16_t pc_reg;
    uint8_t sp_reg;
    uint8_t a_reg;
    uint8_t x_reg;
    uint8_t y_reg;
    uint8_t p_reg;
  } regfile;
 public:
  void reset() {
    regfile.pc_reg = 0;
    regfile.sp_reg = 0;
    regfile.a_reg = 0;
    regfile.x_reg = 0;
    regfile.y_reg = 0;
    regfile.p_reg = 0;
  }
  ALU() {
    reset();
  }
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
  void Adder(IN OUT uint8_t &opnd1, IN uint8_t opnd2,
      IN uint8_t cin, OUT uint8_t &cout);
  void Adc(IN MemData opnd);
  void Inc(IN MemData opnd);
  void Inx();
  void Iny();
  void Sbc(IN MemData opnd);
  void Dec(IN MemData opnd);
  void Dex();
  void Dey();
  void And(IN MemData opnd);
  void Eor(IN MemData opnd);
  void Ora(IN MemData opnd);
  void Bit(IN MemData opnd);
  void Asl();
  void Asl(IN MemData opnd);
  void Lsr();
  void Lsr(IN MemData opnd);
  void Rol();
  void Rol(IN MemData opnd);
  void Ror();
  void Ror(IN MemData opnd);
  void Bcc(IN MemData opnd);
  void Bcs(IN MemData opnd);
  void Beq(IN MemData opnd);
  void Bmi(IN MemData opnd);
  void Bne(IN MemData opnd);
  void Bpl(IN MemData opnd);
  void Bvc(IN MemData opnd);
  void Bvs(IN MemData opnd);
  void CmpFactory(IN uint8_t opnd1, IN MemData opnd2);
  void Cmp(IN MemData opnd);
  void Cpx(IN MemData opnd);
  void Cpy(IN MemData opnd);
  void LdFactory(IN OUT uint8_t &opnd1, IN MemData opnd2);
  void Lda(IN MemData opnd);
  void Ldx(IN MemData opnd);
  void Ldy(IN MemData opnd);
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
};

}; // namespace cpu

#endif // CPU_ALU_H_
