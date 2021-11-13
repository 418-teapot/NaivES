#include "cpu/alu.h"
#include "define/addr.h"

namespace cpu {

void ALU::ClearC() {
  regfile.p_reg &= 0xFE;
}

void ALU::ClearZ() {
  regfile.p_reg &= 0xFD;
}

void ALU::ClearI() {
  regfile.p_reg &= 0xFB;
}

void ALU::ClearD() {
  regfile.p_reg &= 0xF7;
}

void ALU::ClearB() {
  regfile.p_reg &= 0xEF;
}

void ALU::ClearV() {
  regfile.p_reg &= 0xBF;
}

void ALU::ClearN() {
  regfile.p_reg &= 0x7F;
}

void ALU::SetC() {
  regfile.p_reg |= 0x01;
}

void ALU::SetZ() {
  regfile.p_reg |= 0x02;
}

void ALU::SetI() {
  regfile.p_reg |= 0x04;
}

void ALU::SetD() {
  regfile.p_reg |= 0x08;
}

void ALU::SetB() {
  regfile.p_reg |= 0x10;
}

void ALU::SetV() {
  regfile.p_reg |= 0x40;
}

void ALU::SetN() {
  regfile.p_reg |= 0x80;
}

uint8_t ALU::ReadC() {
  return READ_BIT(regfile.p_reg, 0);
}

uint8_t ALU::ReadZ() {
  return READ_BIT(regfile.p_reg, 1);
}

uint8_t ALU::ReadI() {
  return READ_BIT(regfile.p_reg, 2);
}

uint8_t ALU::ReadD() {
  return READ_BIT(regfile.p_reg, 3);
}

uint8_t ALU::ReadB() {
  return READ_BIT(regfile.p_reg, 4);
}

uint8_t ALU::ReadV() {
  return READ_BIT(regfile.p_reg, 6);
}

uint8_t ALU::ReadN() {
  return READ_BIT(regfile.p_reg, 7);
}

void ALU::PushStack(IN uint8_t data) {
  MemWrite(regfile.sp_reg--, data);
}

void ALU::PopStack(OUT uint8_t &data) {
  MemRead(++regfile.sp_reg, data);
}

void ALU::Adder(IN OUT uint8_t &opnd1, IN uint8_t opnd2,
    IN uint8_t cin, OUT uint8_t &cout) {
  uint16_t sum = opnd1 + opnd2 + cin;
  cout = READ_BIT(sum, 8);
  opnd1 = sum & 0xFF;
}

void ALU::Adc(IN MemData opnd) {
  regfile.pc_reg += (uint8_t)opnd.byte + 1;
  uint8_t cout = 0;
  Adder(regfile.a_reg, opnd.data, ReadC(), cout);
  UPDATE_C(cout);
  UPDATE_NZ(regfile.a_reg);
}

void ALU::Inc(IN MemData opnd) {
  regfile.pc_reg += (uint8_t)opnd.byte + 1;
  uint8_t data = opnd.data;
  uint8_t cout = 0;
  Adder(data, (uint8_t)1, (uint8_t)0, cout);
  UPDATE_NZ(data);
  MemWrite(opnd.addr, data);
}

void ALU::Inx() {
  regfile.pc_reg++;
  regfile.x_reg++;
  UPDATE_NZ(regfile.x_reg);
}

void ALU::Iny() {
  regfile.pc_reg++;
  regfile.y_reg++;
  UPDATE_NZ(regfile.y_reg);
}

void ALU::Sbc(IN MemData opnd) {
  regfile.pc_reg += (uint8_t)opnd.byte + 1;
  uint8_t cout = 0;
  Adder(regfile.a_reg, -opnd.data, -ReadC(), cout);
  UPDATE_C(cout);
  UPDATE_NZ(regfile.a_reg);
}

void ALU::Dec(IN MemData opnd) {
  regfile.pc_reg += (uint8_t)opnd.byte + 1;
  uint8_t data = opnd.data;
  uint8_t cout = 0;
  Adder(data, (uint8_t)-1, (uint8_t)0, cout);
  UPDATE_NZ(data);
  MemWrite(opnd.addr, data);
}

void ALU::Dex() {
  regfile.pc_reg++;
  regfile.x_reg--;
  UPDATE_NZ(regfile.x_reg);
}

void ALU::Dey() {
  regfile.pc_reg++;
  regfile.y_reg--;
  UPDATE_NZ(regfile.y_reg);
}

void ALU::And(IN MemData opnd) {
  regfile.pc_reg += (uint8_t)opnd.byte + 1;
  regfile.a_reg &= opnd.data;
  UPDATE_NZ(regfile.a_reg);
}

void ALU::Eor(IN MemData opnd) {
  regfile.pc_reg += (uint8_t)opnd.byte + 1;
  regfile.a_reg ^= opnd.data;
  UPDATE_NZ(regfile.a_reg);
}

void ALU::Ora(IN MemData opnd) {
  regfile.pc_reg += (uint8_t)opnd.byte + 1;
  regfile.a_reg |= opnd.data;
  UPDATE_NZ(regfile.a_reg);
}

void ALU::Bit(IN MemData opnd) {
  regfile.pc_reg += (uint8_t)opnd.byte + 1;
  uint8_t tmp = opnd.data;
  UPDATE_N(READ_BIT(tmp, 7));
  UPDATE_V(READ_BIT(tmp, 6));
  UPDATE_Z(!(tmp & regfile.a_reg));
}

void ALU::Asl() {
  regfile.pc_reg++;
  uint16_t tmp = (uint16_t)regfile.a_reg << 1;
  regfile.a_reg = tmp & 0xFF;
  UPDATE_NZ(regfile.a_reg);
  UPDATE_C(READ_BIT(tmp, 8));
}

void ALU::Asl(IN MemData opnd) {
  regfile.pc_reg += (uint8_t)opnd.byte + 1;
  uint16_t tmp = (uint16_t)opnd.data << 1;
  uint8_t data = tmp & 0xFF;
  MemWrite(opnd.addr, data);
  UPDATE_NZ(data);
  UPDATE_C(READ_BIT(tmp, 8));
}

void ALU::Lsr() {
  regfile.pc_reg++;
  UPDATE_C(READ_BIT(regfile.a_reg, 0));
  regfile.a_reg >>= 1;
  UPDATE_NZ(regfile.a_reg);
}

void ALU::Lsr(IN MemData opnd) {
  regfile.pc_reg += (uint8_t)opnd.byte + 1;
  UPDATE_C(READ_BIT(opnd.data, 0));
  uint8_t tmp = opnd.data >> 1;
  MemWrite(opnd.addr, tmp);
  UPDATE_NZ(tmp);
}

void ALU::Rol() {
  regfile.pc_reg++;
  uint16_t tmp = ((uint16_t)regfile.a_reg << 1) + ReadC();
  UPDATE_C(READ_BIT(tmp, 8));
  regfile.a_reg = tmp & 0xFF;
  UPDATE_NZ(regfile.a_reg);
}

void ALU::Rol(IN MemData opnd) {
  regfile.pc_reg += (uint8_t)opnd.byte + 1;
  uint16_t tmp = ((uint16_t)opnd.data << 1) + ReadC();
  UPDATE_C(READ_BIT(tmp, 8));
  uint8_t data = tmp & 0xFF;
  MemWrite(opnd.addr, data);
  UPDATE_NZ(data);
}

void ALU::Ror() {
  regfile.pc_reg++;
  uint8_t tmp = (regfile.a_reg >> 1) + (ReadC() << 7);
  UPDATE_C(READ_BIT(regfile.a_reg, 0));
  regfile.a_reg = tmp;
  UPDATE_NZ(regfile.a_reg);
}

void ALU::Ror(IN MemData opnd) {
  regfile.pc_reg += (uint8_t)opnd.byte + 1;
  uint8_t tmp = (opnd.data >> 1) + (ReadC() << 7);
  UPDATE_C(READ_BIT(opnd.data, 0));
  MemWrite(opnd.addr, tmp);
  UPDATE_NZ(tmp);
}

void ALU::Bcc(IN MemData opnd) {
  regfile.pc_reg += (uint8_t)opnd.byte + 1;
  if (ReadC() == 0) regfile.pc_reg += (uint8_t)opnd.addr;
}

void ALU::Bcs(IN MemData opnd) {
  regfile.pc_reg += (uint8_t)opnd.byte + 1;
  if (ReadC() == 1) regfile.pc_reg += (uint8_t)opnd.addr;
}

void ALU::Beq(IN MemData opnd) {
  regfile.pc_reg += (uint8_t)opnd.byte + 1;
  if (ReadZ() == 1) regfile.pc_reg += (uint8_t)opnd.addr;
}

void ALU::Bmi(IN MemData opnd) {
  regfile.pc_reg += (uint8_t)opnd.byte + 1;
  if (ReadN() == 1) regfile.pc_reg += (uint8_t)opnd.addr;
}

void ALU::Bne(IN MemData opnd) {
  regfile.pc_reg += (uint8_t)opnd.byte + 1;
  if (ReadZ() == 0) regfile.pc_reg += (uint8_t)opnd.addr;
}

void ALU::Bpl(IN MemData opnd) {
  regfile.pc_reg += (uint8_t)opnd.byte + 1;
  if (ReadN() == 0) regfile.pc_reg += (uint8_t)opnd.addr;
}

void ALU::Bvc(IN MemData opnd) {
  regfile.pc_reg += (uint8_t)opnd.byte + 1;
  if (ReadV() == 0) regfile.pc_reg += (uint8_t)opnd.addr;
}

void ALU::Bvs(IN MemData opnd) {
  regfile.pc_reg += (uint8_t)opnd.byte + 1;
  if (ReadV() == 1) regfile.pc_reg += (uint8_t)opnd.addr;
}

void ALU::Brk() {
  regfile.pc_reg++;
  PushStack((regfile.pc_reg >> 8) & 0xFF);
  PushStack(regfile.pc_reg & 0xFF);
  PushStack(regfile.p_reg);
  SetI();
  uint8_t pc_low = 0;
  uint8_t pc_high = 0;
  MemRead(IRQ_VECTOR, pc_low);
  MemRead(IRQ_VECTOR + 1, pc_high);
  regfile.pc_reg = (uint16_t)pc_high << 8 | (uint16_t)pc_low;
}

void ALU::Jmp(IN MemData opnd) {
  regfile.pc_reg = opnd.addr;
}

void ALU::Jsr(IN MemData opnd) {
  PushStack((regfile.pc_reg + 2) >> 8);
  PushStack((regfile.pc_reg + 2) & 0xFFFF);
  regfile.pc_reg = opnd.addr;
}

void ALU::Rti() {
  PopStack(regfile.p_reg);
  uint8_t pc_high = 0;
  uint8_t pc_low = 0;
  PopStack(pc_low);
  PopStack(pc_high);
  regfile.pc_reg = ((uint16_t)pc_high << 8) + (uint16_t)pc_low;
}

void ALU::Rts() {
  uint8_t pc_high = 0;
  uint8_t pc_low = 0;
  PopStack(pc_low);
  PopStack(pc_high);
  regfile.pc_reg = ((uint16_t)pc_high << 8) + (uint16_t)pc_low;
  regfile.pc_reg++;
}

void ALU::CmpFactory(IN uint8_t opnd1, IN MemData opnd2) {
  regfile.pc_reg += (uint8_t)opnd2.byte + 1;
  uint8_t cout = 0;
  uint8_t tmp = opnd1;
  Adder(tmp, -opnd2.data, 0, cout);
  UPDATE_C(cout);
  UPDATE_NZ(tmp);
}

void ALU::Cmp(IN MemData opnd) {
  CmpFactory(regfile.a_reg, opnd);
}

void ALU::Cpx(IN MemData opnd) {
  CmpFactory(regfile.x_reg, opnd);
}

void ALU::Cpy(IN MemData opnd) {
  CmpFactory(regfile.y_reg, opnd);
}

void ALU::LdFactory(IN OUT uint8_t &opnd1, IN MemData opnd2) {
  regfile.pc_reg += (uint8_t)opnd2.byte + 1;
  opnd1 = opnd2.data;
  UPDATE_NZ(regfile.a_reg);
}

void ALU::Lda(IN MemData opnd) {
  LdFactory(regfile.a_reg, opnd);
}

void ALU::Ldx(IN MemData opnd) {
  LdFactory(regfile.x_reg, opnd);
}

void ALU::Ldy(IN MemData opnd) {
  LdFactory(regfile.y_reg, opnd);
}

void ALU::Tax() {
  regfile.pc_reg++;
  regfile.x_reg = regfile.a_reg;
  UPDATE_NZ(regfile.x_reg);
}

void ALU::Tay() {
  regfile.pc_reg++;
  regfile.y_reg = regfile.a_reg;
  UPDATE_NZ(regfile.y_reg);
}

void ALU::Txa() {
  regfile.pc_reg++;
  regfile.a_reg = regfile.x_reg;
  UPDATE_NZ(regfile.a_reg);
}

void ALU::Tya() {
  regfile.pc_reg++;
  regfile.a_reg = regfile.y_reg;
  UPDATE_NZ(regfile.a_reg);
}

void ALU::Tsx() {
  regfile.pc_reg++;
  regfile.x_reg = regfile.sp_reg;
  UPDATE_NZ(regfile.x_reg);
}

void ALU::Txs() {
  regfile.pc_reg++;
  regfile.sp_reg = regfile.x_reg;
}

void ALU::Pha() {
  regfile.pc_reg++;
  PushStack(regfile.a_reg);
}

void ALU::Php() {
  regfile.pc_reg++;
  PushStack(regfile.p_reg);
}

void ALU::Pla() {
  regfile.pc_reg++;
  PopStack(regfile.a_reg);
  UPDATE_NZ(regfile.a_reg);
}

void ALU::Plp() {
  regfile.pc_reg++;
  PopStack(regfile.p_reg);
}

} // namespace cpu
