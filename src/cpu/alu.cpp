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
  // TODO:
  // uint8_t c0 = cin;
  // uint8_t p = opnd1 ^ opnd2;
  // uint8_t g = opnd1 & opnd2;
  // uint8_t p0 = READ_BIT(p, 0);
  // uint8_t g0 = READ_BIT(g, 0);
  // uint8_t p1 = READ_BIT(p, 1);
  // uint8_t g1 = READ_BIT(g, 1);
  // uint8_t p2 = READ_BIT(p, 2);
  // uint8_t g2 = READ_BIT(g, 2);
  // uint8_t p3 = READ_BIT(p, 3);
  // uint8_t g3 = READ_BIT(g, 3);
  // uint8_t p4 = READ_BIT(p, 4);
  // uint8_t g4 = READ_BIT(g, 4);
  // uint8_t p5 = READ_BIT(p, 5);
  // uint8_t g5 = READ_BIT(g, 5);
  // uint8_t p6 = READ_BIT(p, 6);
  // uint8_t g6 = READ_BIT(g, 6);
  // uint8_t p7 = READ_BIT(p, 7);
  // uint8_t g7 = READ_BIT(g, 7);
}

void ALU::Adc(Imme oper) {
  regfile.pc_reg += 2;
  uint8_t cout = 0;
  Adder(regfile.a_reg, oper, ReadC(), cout);
  if (cout) SetC();
  else ClearC();
  UpdateNZ(regfile.a_reg);
}

} // namespace cpu
