#ifndef DEFINE_TYPE_H_
#define DEFINE_TYPE_H_

#include <cstdint>

#define IN
#define OUT

union Imme {
  uint8_t data;
};

union ZPAddr {
  uint8_t addr;
};

union IdxZPAddr {
  uint8_t addr;
};

union AbsAddr {
  uint16_t addr;
};

union IdxAbsAddrX {
  uint16_t addr;
};

union IdxAbsAddrY {
  uint16_t addr;
};

union IndIdxAddr {
  uint8_t addr;
};

union IdxIndAddr {
  uint8_t addr;
};

#endif // DEFINE_TYPE_H_
