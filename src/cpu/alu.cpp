#include "cpu/alu.h"

namespace cpu {

void ALU::ClearC() {
  regfile.p_reg &= 0xFE;
};

void ALU::ClearD() {
  regfile.p_reg &= 0xF7;
};

void ALU::ClearI() {
  regfile.p_reg &= 0xFB;
};

void ALU::ClearV() {
  regfile.p_reg &= 0xBF;
};

void ALU::SetC() {
  regfile.p_reg |= 0x01;
};

void ALU::SetD() {
  regfile.p_reg |= 0x08;
};

void ALU::SetI() {
  regfile.p_reg |= 0x04;
};

}
