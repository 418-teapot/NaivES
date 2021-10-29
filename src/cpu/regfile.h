#ifndef CPU_REGFILE_H_
#define CPU_REGFILE_H_

#include <cstdint>

namespace cpu {

class RegFile {
 private:
  uint16_t pc_reg;
  uint8_t sp_reg;
  uint8_t a_reg;
  uint8_t x_reg;
  uint8_t y_reg;
  uint8_t p_reg;
  friend class ALU;
 public:
  void reset() {
    pc_reg = 0;
    sp_reg = 0;
    x_reg = 0;
    y_reg = 0;
    p_reg = 0;
  };
};

}; // namespace cpu

#endif // CPU_REGFILE_H_
