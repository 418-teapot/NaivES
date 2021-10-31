#ifndef CPU_OPCODE_H_
#define CPU_OPCODE_H_

namespace cpu {

enum class Op1 {
  ADC = 0x60,
  SBC = 0xE0,
  AND = 0x20,
  EOR = 0x40,
  ORA = 0x00,
  CMP = 0xC0,
  LDA = 0xA0,
  STA = 0x80
};

enum class AddrMode1 {
  IMME = 0x09, // STA doesn't have this mode
  ZERO_PAGE = 0x05,
  IDX_ZERO_PAGE_X = 0x15,
  ABSOLUTE = 0x0D,
  IDX_ABS_X = 0x1D,
  IDX_ABS_Y = 0x19,
  IDX_IND = 0x01,
  IND_IDX = 0x11
};

enum class Op2 {
  ASL = 0x00,
  LSR = 0x40,
  ROL = 0x20,
  ROR = 0x60,
  INC = 0xE0,
  DEC = 0xC0
};

enum class AddrMode2 {
  ACC = 0x0A, // INC, DEC don't have this mode
  ZERO_PAGE = 0x06,
  IDX_ZERO_PAGE_X = 0x16,
  ABSOLUTE = 0x0E,
  IDX_ABSOLUTE_X = 0x1E
};

enum class OpBranch {
  BCC = 0x90,
  BCS = 0xB0,
  BEQ = 0xF0,
  BMI = 0x30,
  BNE = 0xD0,
  BPL = 0x10,
  BVC = 0x50,
  BVS = 0x70,
};

enum class OpImpl {
  INX = 0xE8,
  INY = 0xC8,
  DEX = 0xCA,
  DEY = 0x88,
  BRK = 0x00,
  RTI = 0x40,
  RTS = 0x60,
  CLC = 0x18,
  CLD = 0xD8,
  CLI = 0x58,
  CLV = 0xB8,
  SEC = 0x38,
  SED = 0xF8,
  SEI = 0x78,
  TAX = 0xAA,
  TAY = 0xA8,
  TSX = 0xBA,
  TXA = 0x8A,
  TXS = 0x9A,
  TYA = 0x98,
  PHA = 0x48,
  PHP = 0x08,
  PLA = 0x68,
  PLP = 0x28,
  NOP = 0xEA
};

enum class OpXY {
  CPX = 0xE0,
  STX = 0x80,
  LDX = 0xA2,
  CPY = 0xC0,
  STY = 0x80,
  LDY = 0xA0,
};

enum class AddrModeXY {
  IMME = 0x00, // STX, STY don't have this mode
  ZERO_PAGE = 0x04,
  IDX_ZERO_PAGE = 0x14, // CPX, CPY don't support this mode
  ABSOLUTE = 0x0C,
  IDX_ABS = 0x1C // only LDX and LDY
};

enum class OpOthers {
  BIT = 0x20,
  JMP = 0x40,
  JSR = 0x20
};

enum class AddrModeOthers {
  ZERO_PAGE = 0x04, // only BIT
  ABSOLUTE = 0x0C, // JSR absolute is 0x00
  INDIRECT = 0x2C // only JMP
};

}; // namespace cpu

#endif // CPU_OPCODE_H_
