#ifndef CPU_ALU_H_
#define CPU_ALU_H_

#include "cpu/regfile.h"

namespace cpu {

class ALU {
 private:
  RegFile regfile;
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

#endif // CPU_ALU_H
