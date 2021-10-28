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
 public:
  void ClearC();
  void ClearD();
  void ClearI();
  void ClearV();
  void SetC();
  void SetD();
  void SetI();
};
}; // namespace cpu

#endif // CPU_REGFILE_H_
