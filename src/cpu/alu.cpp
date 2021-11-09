#include "cpu/alu.h"

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

void ALU::UpdateNZ(uint8_t value) {
  if (!value) SetZ();
  else ClearZ();
  if (value & 0x80) SetN();
  else ClearN();
}

void ALU::Inx() {
  regfile.x_reg++;
  UpdateNZ(regfile.x_reg);
}

void ALU::Iny() {
  regfile.y_reg++;
  UpdateNZ(regfile.y_reg);
}

void ALU::Dex() {
  regfile.x_reg--;
  UpdateNZ(regfile.x_reg);
}

void ALU::Dey() {
  regfile.y_reg--;
  UpdateNZ(regfile.y_reg);
}

void ALU::Tax() {
  regfile.x_reg = regfile.a_reg;
  UpdateNZ(regfile.x_reg);
}

void ALU::Tay() {
  regfile.y_reg = regfile.a_reg;
  UpdateNZ(regfile.y_reg);
}

void ALU::Txa() {
  regfile.a_reg = regfile.x_reg;
  UpdateNZ(regfile.a_reg);
}

void ALU::Tya() {
  regfile.a_reg = regfile.y_reg;
  UpdateNZ(regfile.a_reg);
}

void ALU::Tsx() {
  regfile.x_reg = regfile.sp_reg;
  UpdateNZ(regfile.x_reg);
}

void ALU::Txs() {
  regfile.sp_reg = regfile.x_reg;
}

void ALU::Pha() {
  mem.write(regfile.sp_reg--, regfile.a_reg);
}

void ALU::Php() {
  mem.write(regfile.sp_reg--, regfile.p_reg);
}

void ALU::Pla() {
  mem.read(++regfile.sp_reg, regfile.a_reg);
}

void ALU::Plp() {
  mem.read(++regfile.sp_reg, regfile.p_reg);
}

void ALU::Adder(uint8_t IN OUT &opnd1, uint8_t IN opnd2,
    uint8_t IN cin, uint8_t OUT &cout) {
  uint16_t sum = opnd1 + opnd2 + cin;
  cout = READ_BIT(sum, 8);
  opnd1 = sum & 0xFF;
}

void ALU::Adc(Imme IN opnd) {
  regfile.pc_reg += 2;
  uint8_t cout = 0;
  Adder(regfile.a_reg, opnd.data, ReadC(), cout);
  if (cout) SetC();
  else ClearC();
  UpdateNZ(regfile.a_reg);
}

void ALU::Sbc(Imme IN opnd) {
  regfile.pc_reg += 2;
  uint8_t cout = 0;
  Adder(regfile.a_reg, -opnd.data, -ReadC(), cout);
  if (cout) SetC();
  else ClearC();
  UpdateNZ(regfile.a_reg);
}

void ALU::And(Imme IN opnd) {
  regfile.pc_reg += 2;
  regfile.a_reg &= opnd.data;
  UpdateNZ(regfile.a_reg);
}

void ALU::Eor(Imme IN opnd) {
  regfile.pc_reg += 2;
  regfile.a_reg ^= opnd.data;
  UpdateNZ(regfile.a_reg);
}

void ALU::Ora(Imme IN opnd) {
  regfile.pc_reg += 2;
  regfile.a_reg |= opnd.data;
  UpdateNZ(regfile.a_reg);
}

void ALU::CmpFactory(uint8_t IN opnd1, Imme IN opnd2) {
  regfile.pc_reg += 2;
  uint8_t cout = 0;
  uint8_t tmp = opnd1;
  Adder(tmp, -opnd2.data, 0, cout);
  if (cout) SetC();
  else ClearC();
  UpdateNZ(tmp);
}

void ALU::Cmp(Imme IN opnd) {
  CmpFactory(regfile.a_reg, opnd);
}

void ALU::Cpx(Imme IN opnd) {
  CmpFactory(regfile.x_reg, opnd);
}

void ALU::Cpy(Imme IN opnd) {
  CmpFactory(regfile.y_reg, opnd);
}

void ALU::LdFactory(uint8_t IN OUT &opnd1, Imme IN opnd2) {
  regfile.pc_reg += 2;
  opnd1 = opnd2.data;
  UpdateNZ(regfile.a_reg);
}

void ALU::Lda(Imme IN opnd) {
  LdFactory(regfile.a_reg, opnd);
}

void ALU::Ldx(Imme opnd) {
  LdFactory(regfile.x_reg, opnd);
}

void ALU::Ldy(Imme opnd) {
  LdFactory(regfile.y_reg, opnd);
}

} // namespace cpu
