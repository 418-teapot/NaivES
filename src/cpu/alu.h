#ifndef CPU_ALU_H_
#define CPU_ALU_H_

#include "cpu/regfile.h"
#include "define/type.h"
#include "mem/mem.h"
#include <cstdint>

namespace cpu {

class ALU {
 private:
  RegFile regfile;
  Mem mem;
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
  uint8_t ReadC();
  uint8_t ReadZ();
  uint8_t ReadI();
  uint8_t ReadD();
  uint8_t ReadB();
  uint8_t ReadV();
  uint8_t ReadN();
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
  void Pha();
  void Php();
  void Pla();
  void Plp();
};

}; // namespace cpu

#endif // CPU_ALU_H
