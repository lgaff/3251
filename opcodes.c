#include "opcodes.h"


instruction_t rev_6502_opcode_table[] = {
   { "ADC", 0x69, IMMEDIATE, 2, 0, 0 },
   { "ADC", 0x65, ZERO_PAGE, 3, 0, 0 },
   { "ADC", 0x75, ZERO_PAGE_X, 4, 0, 0 },
   { "ADC", 0x6D, ABSOLUTE, 4, 0, 0 },
   { "ADC", 0x7D, ABSOLUTE_X, 4, 0, 0 },
   { "ADC", 0x79, ABSOLUTE_Y, 4, 0, 0 },
   { "ADC", 0x61, INDEX_INDIRECT, 6, 0, 0 },
   { "ADC", 0x71, INDIRECT_INDEX, 5, 0, 0 },

   { "AND", 0x29, IMMEDIATE, 2, 0, 0 },
   { "AND", 0x25, ZERO_PAGE, 3, 0, 0 },
   { "AND", 0x35, ZERO_PAGE_X, 4, 0, 0 },
   { "AND", 0x2D, ABSOLUTE, 4, 0, 0 },
   { "AND", 0x3D, ABSOLUTE_X, 4, 0, 0 },
   { "AND", 0x39, ABSOLUTE_Y, 4, 0, 0 },
   { "AND", 0x21, IMMEDIATE, 6, 0, 0 },
   { "AND", 0x31, IMMEDIATE, 5, 0, 0 },

   { "ASL", 0x0A, ACCUMULATOR, 2, 0, 0 },
   { "ASL", 0x06, ZERO_PAGE, 5, 0, 0 },
   { "ASL", 0x16, ZERO_PAGE_X, 6, 0, 0 },
   { "ASL", 0x0E, ABSOLUTE, 6, 0, 0 },
   { "ASL", 0x1E, ABSOLUTE_X, 7, 0, 0 },

   { "BIT", 0x24, ZERO_PAGE, 3, 0, 0 },
   { "BIT", 0x2C, ABSOLUTE, 4, 0, 0 },
   /* TODO: Branch instructions have variable timings based on whether branch is taken or not */
   { "BPL", 0x10, RELATIVE, 2, 0, 0 },
   { "BMI", 0x30, RELATIVE, 2, 0, 0 },
   { "BVC", 0x50, RELATIVE, 2, 0, 0 },
   { "BVS", 0x70, RELATIVE, 2, 0, 0 },
   { "BCC", 0x90, RELATIVE, 2, 0, 0 },
   { "BCS", 0xB0, RELATIVE, 2, 0, 0 },
   { "BNE", 0xD0, RELATIVE, 2, 0, 0 },
   { "BEQ", 0xF0, RELATIVE, 2, 0, 0 },

   { "BRK", 0x00, IMPLIED, 7, 0, 0 },

   { "CMP", 0xC9, IMMEDIATE, 2, 0, 0 },
   { "CMP", 0xC5, ZERO_PAGE, 3, 0, 0 },
   { "CMP", 0xD5, ZERO_PAGE_X, 4, 0, 0 },
   { "CMP", 0xCD, ABSOLUTE, 4, 0, 0 },
   { "CMP", 0xDD, ABSOLUTE_X, 4, 0, 0 },
   { "CMP", 0xD9, ABSOLUTE_Y, 4, 0, 0 },
   { "CMP", 0xC1, INDEX_INDIRECT, 6, 0, 0 },
   { "CMP", 0xD1, INDIRECT_INDEX, 5, 0, 0 },

   { "CPX", 0xE0, IMMEDIATE, 2, 0, 0 },
   { "CPX", 0xE4, ZERO_PAGE, 2, 0, 0 },
   { "CPX", 0xEC, ABSOLUTE, 4, 0, 0 },

   { "CPY", 0xC0, IMMEDIATE, 2, 0, 0 },
   { "CPY", 0xC4, ZERO_PAGE, 2, 0, 0 },
   { "CPY", 0xCC, ABSOLUTE, 4, 0, 0 },

   { "DEC", 0xC6, ZERO_PAGE, 5, 0, 0 },
   { "DEC", 0xD6, ZERO_PAGE_X, 6, 0, 0 },
   { "DEC", 0xCE, ABSOLUTE, 6, 0, 0 },
   { "DEC", 0xDE, ABSOLUTE_X, 7, 0, 0 },

   { "EOR", 0x49, IMMEDIATE, 2, 0, 0 },
   { "EOR", 0x45, ZERO_PAGE, 3, 0, 0 },
   { "EOR", 0x55, ZERO_PAGE_X, 4, 0, 0 },
   { "EOR", 0x49, ABSOLUTE, 4, 0, 0 },
   { "EOR", 0x49, ABSOLUTE_X, 4, 0, 0 },
   { "EOR", 0x49, ABSOLUTE_Y, 4, 0, 0 },
   { "EOR", 0x49, INDEX_INDIRECT, 6, 0, 0 },
   { "EOR", 0x49, INDIRECT_INDEX, 5, 0, 0 },

   { "CLC", 0x18, IMPLIED, 2, 0, 0 },
   { "SEC", 0x38, IMPLIED, 2, 0, 0 },
   { "CLI", 0x58, IMPLIED, 2, 0, 0 },
   { "SEI", 0x78, IMPLIED, 2, 0, 0 },
   { "CLV", 0xB8, IMPLIED, 2, 0, 0 },
   { "CLD", 0xD8, IMPLIED, 2, 0, 0 },
   { "SED", 0xF8, IMPLIED, 2, 0, 0 },

   { "INC", 0xE6, ZERO_PAGE, 5, 0, 0 },
   { "INC", 0xF6, ZERO_PAGE_X, 6, 0, 0 },
   { "INC", 0xEE, ABSOLUTE, 6, 0, 0 },
   { "INC", 0xFE, ABSOLUTE_X, 7, 0, 0 },

   { "JMP", 0x4C, ABSOLUTE, 3, 0, 0 },
   { "JMP", 0x6C, INDIRECT, 5, 0, 0 },

   { "JSR", 0x20, ABSOLUTE, 6, 0, 0 },

   { "LDX", 0xA2, IMMEDIATE, 2, 0, 0 },
   { "LDX", 0xA6, ZERO_PAGE, 3, 0, 0 },
   { "LDX", 0xB6, ZERO_PAGE_Y, 4, 0, 0 },
   { "LDX", 0xAE, ABSOLUTE, 4, 0, 0 },
   { "LDX", 0xBE, ABSOLUTE_Y, 4, 0, 0 },

   { "LDY", 0xA0, IMMEDIATE, 2, 0, 0 },
   { "LDY", 0xA4, ZERO_PAGE, 3, 0, 0 },
   { "LDY", 0xB4, ZERO_PAGE_X, 4, 0, 0 },
   { "LDY", 0xAC, ABSOLUTE, 4, 0, 0 },
   { "LDY", 0xBC, ABSOLUTE_X, 4, 0, 0 },

   { "LSR", 0x4A, ACCUMULATOR, 2, 0, 0 },
   { "LSR", 0x46, ZERO_PAGE, 5, 0, 0 },
   { "LSR", 0x56, ZERO_PAGE_X, 6, 0, 0 },
   { "LSR", 0x4E, ABSOLUTE, 6, 0, 0 },
   { "LSR", 0x5E, ABSOLUTE_X, 7, 0, 0 },

   { "NOP", 0xEA, IMPLIED, 2, 0, 0 },

   { "ORA", 0x09, IMMEDIATE, 2, 0, 0 },
   { "ORA", 0x05, ZERO_PAGE, 3, 0, 0 },
   { "ORA", 0x15, ZERO_PAGE_X, 4, 0, 0 },
   { "ORA", 0x0D, ABSOLUTE, 0, 4, 0 },
   { "ORA", 0x1D, ABSOLUTE_X, 4, 0, 0 },
   { "ORA", 0x19, ABSOLUTE_Y, 4, 0, 0 },
   { "ORA", 0x01, INDEX_INDIRECT, 6, 0, 0 },
   { "ORA", 0x11, INDIRECT_INDEX, 5, 0, 0 },

   { "TAX", 0xAA, IMPLIED, 2, 0, 0 },
   { "TXA", 0x8A, IMPLIED, 2, 0, 0 },
   { "DEX", 0xCA, IMPLIED, 2, 0, 0 },
   { "INX", 0xEA, IMPLIED, 2, 0, 0 },
   { "TAY", 0xA8, IMPLIED, 2, 0, 0 },
   { "TYA", 0x98, IMPLIED, 2, 0, 0 },
   { "DEY", 0x88, IMPLIED, 2, 0, 0 },
   { "INY", 0xC8, IMPLIED, 2, 0, 0 },

   { "ROL", 0x2A, ACCUMULATOR, 2, 0, 0 },
   { "ROL", 0x26, ZERO_PAGE, 5, 0, 0 },
   { "ROL", 0x36, ZERO_PAGE_X, 6, 0, 0 },
   { "ROL", 0x2E, ABSOLUTE, 6, 0, 0 },
   { "ROL", 0x3E, ABSOLUTE_X, 7, 0, 0 },

   { "ROR", 0x6A, ACCUMULATOR, 2, 0, 0 },
   { "ROR", 0x66, ZERO_PAGE, 5, 0, 0 },
   { "ROR", 0x76, ZERO_PAGE_X, 6, 0, 0 },
   { "ROR", 0x6E, ABSOLUTE, 6, 0, 0 },
   { "ROR", 0x7E, ABSOLUTE_X, 7, 0, 0 },

   { "RTI", 0x40, IMPLIED, 6, 0, 0 },
   { "RTS", 0x60, IMPLIED, 6, 0, 0 },

   { "SBC", 0xE9, IMMEDIATE, 2, 0, 0 },
   { "SBC", 0xE5, ZERO_PAGE, 3, 0, 0 },
   { "SBC", 0xF5, ZERO_PAGE_X, 4, 0, 0 },
   { "SBC", 0xED, ABSOLUTE, 4, 0, 0 },
   { "SBC", 0xFD, ABSOLUTE_X, 4, 0, 0 },
   { "SBC", 0xF9, ABSOLUTE_Y, 4, 0, 0 },
   { "SBC", 0xE1, INDEX_INDIRECT, 6, 0, 0 },
   { "SBC", 0xF1, INDIRECT_INDEX, 5, 0, 0 },

   { "STA", 0x85, ZERO_PAGE, 3, 0, 0 },
   { "STA", 0x95, ZERO_PAGE_X, 4, 0, 0 },
   { "STA", 0x8D, ABSOLUTE, 4, 0, 0 },
   { "STA", 0x9D, ABSOLUTE_X, 5, 0, 0 },
   { "STA", 0x99, ABSOLUTE_Y, 5, 0, 0 },
   { "STA", 0x81, INDEX_INDIRECT, 6, 0, 0 },
   { "STA", 0x91, INDIRECT_INDEX, 6, 0, 0 },

   { "TXS", 0x9A, IMPLIED, 2, 0, 0 },
   { "TSX", 0xBA, IMPLIED, 2, 0, 0 },
   { "PHA", 0x48, IMPLIED, 3, 0, 0 },
   { "PLA", 0x68, IMPLIED, 4, 0, 0 },
   { "PHP", 0x08, IMPLIED, 3, 0, 0 },
   { "PLP", 0x28, IMPLIED, 4, 0, 0 },

   { "STX", 0x86, ZERO_PAGE, 3, 0, 0 },
   { "STX", 0x96, ZERO_PAGE_Y, 4, 0, 0 },
   { "STX", 0x8E, ABSOLUTE, 4, 0, 0 },

   { "STY", 0x84, ZERO_PAGE, 3, 0, 0 },
   { "STY", 0x94, ZERO_PAGE_Y, 4, 0, 0 },
   { "STY", 0x8C, ABSOLUTE, 4, 0, 0 },











