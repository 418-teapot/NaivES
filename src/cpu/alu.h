#ifndef CPU_ALU_H_
#define CPU_ALU_H_

#include "cpu/regfile.h"
#include <cstdint>

namespace cpu {

class ALU {
 private:
  RegFile regfile;
 public:
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
  void UpdateNZ(uint8_t value);
  void Inx();
  void Iny();
  void Dex();
  void Dey();
  void Tax();
  void Tay();
  void Tsx();
  void Txa();
  void Txs();
  void Tya();
};

}; // namespace cpu

#endif // CPU_ALU_H
