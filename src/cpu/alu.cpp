#include "cpu/alu.h"

namespace cpu {

void ALU::ClearC() {
  regfile.p_reg &= 0xFE;
};

void ALU::ClearZ() {
  regfile.p_reg &= 0xFD;
};

void ALU::ClearI() {
  regfile.p_reg &= 0xFB;
};

void ALU::ClearD() {
  regfile.p_reg &= 0xF7;
};

void ALU::ClearB() {
  regfile.p_reg &= 0xEF;
};

void ALU::ClearV() {
  regfile.p_reg &= 0xBF;
};

void ALU::ClearN() {
  regfile.p_reg &= 0x7F;
};

void ALU::SetC() {
  regfile.p_reg |= 0x01;
};

void ALU::SetZ() {
  regfile.p_reg |= 0x02;
};

void ALU::SetI() {
  regfile.p_reg |= 0x04;
};

void ALU::SetD() {
  regfile.p_reg |= 0x08;
};

void ALU::SetB() {
  regfile.p_reg |= 0x10;
};

void ALU::SetV() {
  regfile.p_reg |= 0x40;
};

void ALU::SetN() {
  regfile.p_reg |= 0x80;
};

void ALU::UpdateNZ(uint8_t value) {
  if (!value) SetZ();
  else ClearZ();
  if (value & 0x80) SetN();
  else ClearN();
};

void ALU::Inx() {
  regfile.x_reg++;
  UpdateNZ(regfile.x_reg);
};

void ALU::Iny() {
  regfile.y_reg++;
  UpdateNZ(regfile.y_reg);
};

void ALU::Dex() {
  regfile.x_reg--;
  UpdateNZ(regfile.x_reg);
};

void ALU::Dey() {
  regfile.y_reg--;
  UpdateNZ(regfile.y_reg);
};

void ALU::Tax() {
  regfile.x_reg = regfile.a_reg;
  UpdateNZ(regfile.x_reg);
};

void ALU::Tay() {
  regfile.y_reg = regfile.a_reg;
  UpdateNZ(regfile.y_reg);
};

void ALU::Txa() {
  regfile.a_reg = regfile.x_reg;
  UpdateNZ(regfile.a_reg);
};

void ALU::Tya() {
  regfile.a_reg = regfile.y_reg;
  UpdateNZ(regfile.a_reg);
};

void ALU::Tsx() {
  regfile.x_reg = regfile.sp_reg;
  UpdateNZ(regfile.x_reg);
};

void ALU::Txs() {
  regfile.sp_reg = regfile.x_reg;
};

}
