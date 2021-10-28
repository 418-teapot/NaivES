#include "cpu/regfile.h"

namespace cpu {

void RegFile::ClearC() {
  p_reg &= 0xFE;
};

void RegFile::ClearD() {
  p_reg &= 0xF7;
};

void RegFile::ClearI() {
  p_reg &= 0xFB;
};

void RegFile::ClearV() {
  p_reg &= 0xBF;
};

void RegFile::SetC() {
  p_reg |= 0x01;
};

void RegFile::SetD() {
  p_reg |= 0x08;
};

void RegFile::SetI() {
  p_reg |= 0x04;
};

};
