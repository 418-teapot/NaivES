#ifndef DEFINE_TYPE_H_
#define DEFINE_TYPE_H_

#include <cstddef>
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

union RelAddr {
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

typedef struct {
  uint8_t data;
  // When branch inst, addr is relative address, otherwise, physical address.
  uint16_t addr;
  uint32_t cycle;
  size_t byte;
} MemData;

#endif // DEFINE_TYPE_H_
