#include "opcodes.h"

#include <stdlib.h>
#include <stdio.h>


instruction_t _opcode_table[] = {
   { "ADC",  0x69,  IMMEDIATE,       2,  0,  0,  REV_6502 },
   { "ADC",  0x65,  ZERO_PAGE,       3,  0,  0,  REV_6502 },
   { "ADC",  0x75,  ZERO_PAGE_X,     4,  0,  0,  REV_6502 },
   { "ADC",  0x6D,  ABSOLUTE,        4,  0,  0,  REV_6502 },
   { "ADC",  0x7D,  ABSOLUTE_X,      4,  0,  0,  REV_6502 },
   { "ADC",  0x79,  ABSOLUTE_Y,      4,  0,  0,  REV_6502 },
   { "ADC",  0x61,  INDEX_INDIRECT,  6,  0,  0,  REV_6502 },
   { "ADC",  0x71,  INDIRECT_INDEX,  5,  0,  0,  REV_6502 },

   { "AND",  0x29,  IMMEDIATE,       2,  0,  0,  REV_6502 },
   { "AND",  0x25,  ZERO_PAGE,       3,  0,  0,  REV_6502 },
   { "AND",  0x35,  ZERO_PAGE_X,     4,  0,  0,  REV_6502 },
   { "AND",  0x2D,  ABSOLUTE,        4,  0,  0,  REV_6502 },
   { "AND",  0x3D,  ABSOLUTE_X,      4,  0,  0,  REV_6502 },
   { "AND",  0x39,  ABSOLUTE_Y,      4,  0,  0,  REV_6502 },
   { "AND",  0x21,  IMMEDIATE,       6,  0,  0,  REV_6502 },
   { "AND",  0x31,  IMMEDIATE,       5,  0,  0,  REV_6502 },

   { "ASL",  0x0A,  ACCUMULATOR,     2,  0,  0,  REV_6502 },
   { "ASL",  0x06,  ZERO_PAGE,       5,  0,  0,  REV_6502 },
   { "ASL",  0x16,  ZERO_PAGE_X,     6,  0,  0,  REV_6502 },
   { "ASL",  0x0E,  ABSOLUTE,        6,  0,  0,  REV_6502 },
   { "ASL",  0x1E,  ABSOLUTE_X,      7,  0,  0,  REV_6502 },

   { "BIT",  0x24,  ZERO_PAGE,       3,  0,  0,  REV_6502 },
   { "BIT",  0x2C,  ABSOLUTE,        4,  0,  0,  REV_6502 },

   { "BPL",  0x10,  RELATIVE,        2,  0,  0,  REV_6502 },
   { "BMI",  0x30,  RELATIVE,        2,  0,  0,  REV_6502 },
   { "BVC",  0x50,  RELATIVE,        2,  0,  0,  REV_6502 },
   { "BVS",  0x70,  RELATIVE,        2,  0,  0,  REV_6502 },
   { "BCC",  0x90,  RELATIVE,        2,  0,  0,  REV_6502 },
   { "BCS",  0xB0,  RELATIVE,        2,  0,  0,  REV_6502 },
   { "BNE",  0xD0,  RELATIVE,        2,  0,  0,  REV_6502 },
   { "BEQ",  0xF0,  RELATIVE,        2,  0,  0,  REV_6502 },

   { "BRK",  0x00,  IMPLIED,         7,  0,  0,  REV_6502 },

   { "CMP",  0xC9,  IMMEDIATE,       2,  0,  0,  REV_6502 },
   { "CMP",  0xC5,  ZERO_PAGE,       3,  0,  0,  REV_6502 },
   { "CMP",  0xD5,  ZERO_PAGE_X,     4,  0,  0,  REV_6502 },
   { "CMP",  0xCD,  ABSOLUTE,        4,  0,  0,  REV_6502 },
   { "CMP",  0xDD,  ABSOLUTE_X,      4,  0,  0,  REV_6502 },
   { "CMP",  0xD9,  ABSOLUTE_Y,      4,  0,  0,  REV_6502 },
   { "CMP",  0xC1,  INDEX_INDIRECT,  6,  0,  0,  REV_6502 },
   { "CMP",  0xD1,  INDIRECT_INDEX,  5,  0,  0,  REV_6502 },

   { "CPX",  0xE0,  IMMEDIATE,       2,  0,  0,  REV_6502 },
   { "CPX",  0xE4,  ZERO_PAGE,       2,  0,  0,  REV_6502 },
   { "CPX",  0xEC,  ABSOLUTE,        4,  0,  0,  REV_6502 },

   { "CPY",  0xC0,  IMMEDIATE,       2,  0,  0,  REV_6502 },
   { "CPY",  0xC4,  ZERO_PAGE,       2,  0,  0,  REV_6502 },
   { "CPY",  0xCC,  ABSOLUTE,        4,  0,  0,  REV_6502 },

   { "DEC",  0xC6,  ZERO_PAGE,       5,  0,  0,  REV_6502 },
   { "DEC",  0xD6,  ZERO_PAGE_X,     6,  0,  0,  REV_6502 },
   { "DEC",  0xCE,  ABSOLUTE,        6,  0,  0,  REV_6502 },
   { "DEC",  0xDE,  ABSOLUTE_X,      7,  0,  0,  REV_6502 },

   { "EOR",  0x49,  IMMEDIATE,       2,  0,  0,  REV_6502 },
   { "EOR",  0x45,  ZERO_PAGE,       3,  0,  0,  REV_6502 },
   { "EOR",  0x55,  ZERO_PAGE_X,     4,  0,  0,  REV_6502 },
   { "EOR",  0x4D,  ABSOLUTE,        4,  0,  0,  REV_6502 },
   { "EOR",  0x5D,  ABSOLUTE_X,      4,  0,  0,  REV_6502 },
   { "EOR",  0x59,  ABSOLUTE_Y,      4,  0,  0,  REV_6502 },
   { "EOR",  0x41,  INDEX_INDIRECT,  6,  0,  0,  REV_6502 },
   { "EOR",  0x51,  INDIRECT_INDEX,  5,  0,  0,  REV_6502 },

   { "CLC",  0x18,  IMPLIED,         2,  0,  0,  REV_6502 },
   { "SEC",  0x38,  IMPLIED,         2,  0,  0,  REV_6502 },
   { "CLI",  0x58,  IMPLIED,         2,  0,  0,  REV_6502 },
   { "SEI",  0x78,  IMPLIED,         2,  0,  0,  REV_6502 },
   { "CLV",  0xB8,  IMPLIED,         2,  0,  0,  REV_6502 },
   { "CLD",  0xD8,  IMPLIED,         2,  0,  0,  REV_6502 },
   { "SED",  0xF8,  IMPLIED,         2,  0,  0,  REV_6502 },

   { "INC",  0xE6,  ZERO_PAGE,       5,  0,  0,  REV_6502 },
   { "INC",  0xF6,  ZERO_PAGE_X,     6,  0,  0,  REV_6502 },
   { "INC",  0xEE,  ABSOLUTE,        6,  0,  0,  REV_6502 },
   { "INC",  0xFE,  ABSOLUTE_X,      7,  0,  0,  REV_6502 },

   { "JMP",  0x4C,  ABSOLUTE,        3,  0,  0,  REV_6502 },
   { "JMP",  0x6C,  INDIRECT,        5,  0,  0,  REV_6502 },

   { "JSR",  0x20,  ABSOLUTE,        6,  0,  0,  REV_6502 },

   { "LDA",  0xA9,  IMMEDIATE,       2,  0,  0,  REV_6502 },
   { "LDA",  0xA5,  ZERO_PAGE,       2,  0,  0,  REV_6502 },
   { "LDA",  0xB5,  ZERO_PAGE_X,     2,  0,  0,  REV_6502 },
   { "LDA",  0xAD,  ABSOLUTE,        2,  0,  0,  REV_6502 },
   { "LDA",  0xBD,  ABSOLUTE_X,      2,  0,  0,  REV_6502 },
   { "LDA",  0xB9,  ABSOLUTE_Y,      2,  0,  0,  REV_6502 },
   { "LDA",  0xA1,  INDEX_INDIRECT,  2,  0,  0,  REV_6502 },
   { "LDA",  0xB1,  INDIRECT_INDEX,  2,  0,  0,  REV_6502 },

   { "LDX",  0xA2,  IMMEDIATE,       2,  0,  0,  REV_6502 },
   { "LDX",  0xA6,  ZERO_PAGE,       3,  0,  0,  REV_6502 },
   { "LDX",  0xB6,  ZERO_PAGE_Y,     4,  0,  0,  REV_6502 },
   { "LDX",  0xAE,  ABSOLUTE,        4,  0,  0,  REV_6502 },
   { "LDX",  0xBE,  ABSOLUTE_Y,      4,  0,  0,  REV_6502 },

   { "LDY",  0xA0,  IMMEDIATE,       2,  0,  0,  REV_6502 },
   { "LDY",  0xA4,  ZERO_PAGE,       3,  0,  0,  REV_6502 },
   { "LDY",  0xB4,  ZERO_PAGE_X,     4,  0,  0,  REV_6502 },
   { "LDY",  0xAC,  ABSOLUTE,        4,  0,  0,  REV_6502 },
   { "LDY",  0xBC,  ABSOLUTE_X,      4,  0,  0,  REV_6502 },

   { "LSR",  0x4A,  ACCUMULATOR,     2,  0,  0,  REV_6502 },
   { "LSR",  0x46,  ZERO_PAGE,       5,  0,  0,  REV_6502 },
   { "LSR",  0x56,  ZERO_PAGE_X,     6,  0,  0,  REV_6502 },
   { "LSR",  0x4E,  ABSOLUTE,        6,  0,  0,  REV_6502 },
   { "LSR",  0x5E,  ABSOLUTE_X,      7,  0,  0,  REV_6502 },

   { "NOP",  0xEA,  IMPLIED,         2,  0,  0,  REV_6502 },

   { "ORA",  0x09,  IMMEDIATE,       2,  0,  0,  REV_6502 },
   { "ORA",  0x05,  ZERO_PAGE,       3,  0,  0,  REV_6502 },
   { "ORA",  0x15,  ZERO_PAGE_X,     4,  0,  0,  REV_6502 },
   { "ORA",  0x0D,  ABSOLUTE,        0,  4,  0,  REV_6502 },
   { "ORA",  0x1D,  ABSOLUTE_X,      4,  0,  0,  REV_6502 },
   { "ORA",  0x19,  ABSOLUTE_Y,      4,  0,  0,  REV_6502 },
   { "ORA",  0x01,  INDEX_INDIRECT,  6,  0,  0,  REV_6502 },
   { "ORA",  0x11,  INDIRECT_INDEX,  5,  0,  0,  REV_6502 },

   { "TAX",  0xAA,  IMPLIED,         2,  0,  0,  REV_6502 },
   { "TXA",  0x8A,  IMPLIED,         2,  0,  0,  REV_6502 },
   { "DEX",  0xCA,  IMPLIED,         2,  0,  0,  REV_6502 },
   { "INX",  0xE8,  IMPLIED,         2,  0,  0,  REV_6502 },
   { "TAY",  0xA8,  IMPLIED,         2,  0,  0,  REV_6502 },
   { "TYA",  0x98,  IMPLIED,         2,  0,  0,  REV_6502 },
   { "DEY",  0x88,  IMPLIED,         2,  0,  0,  REV_6502 },
   { "INY",  0xC8,  IMPLIED,         2,  0,  0,  REV_6502 },

   { "ROL",  0x2A,  ACCUMULATOR,     2,  0,  0,  REV_6502 },
   { "ROL",  0x26,  ZERO_PAGE,       5,  0,  0,  REV_6502 },
   { "ROL",  0x36,  ZERO_PAGE_X,     6,  0,  0,  REV_6502 },
   { "ROL",  0x2E,  ABSOLUTE,        6,  0,  0,  REV_6502 },
   { "ROL",  0x3E,  ABSOLUTE_X,      7,  0,  0,  REV_6502 },

   { "ROR",  0x6A,  ACCUMULATOR,     2,  0,  0,  REV_6502 },
   { "ROR",  0x66,  ZERO_PAGE,       5,  0,  0,  REV_6502 },
   { "ROR",  0x76,  ZERO_PAGE_X,     6,  0,  0,  REV_6502 },
   { "ROR",  0x6E,  ABSOLUTE,        6,  0,  0,  REV_6502 },
   { "ROR",  0x7E,  ABSOLUTE_X,      7,  0,  0,  REV_6502 },

   { "RTI",  0x40,  IMPLIED,         6,  0,  0,  REV_6502 },
   { "RTS",  0x60,  IMPLIED,         6,  0,  0,  REV_6502 },

   { "SBC",  0xE9,  IMMEDIATE,       2,  0,  0,  REV_6502 },
   { "SBC",  0xE5,  ZERO_PAGE,       3,  0,  0,  REV_6502 },
   { "SBC",  0xF5,  ZERO_PAGE_X,     4,  0,  0,  REV_6502 },
   { "SBC",  0xED,  ABSOLUTE,        4,  0,  0,  REV_6502 },
   { "SBC",  0xFD,  ABSOLUTE_X,      4,  0,  0,  REV_6502 },
   { "SBC",  0xF9,  ABSOLUTE_Y,      4,  0,  0,  REV_6502 },
   { "SBC",  0xE1,  INDEX_INDIRECT,  6,  0,  0,  REV_6502 },
   { "SBC",  0xF1,  INDIRECT_INDEX,  5,  0,  0,  REV_6502 },

   { "STA",  0x85,  ZERO_PAGE,       3,  0,  0,  REV_6502 },
   { "STA",  0x95,  ZERO_PAGE_X,     4,  0,  0,  REV_6502 },
   { "STA",  0x8D,  ABSOLUTE,        4,  0,  0,  REV_6502 },
   { "STA",  0x9D,  ABSOLUTE_X,      5,  0,  0,  REV_6502 },
   { "STA",  0x99,  ABSOLUTE_Y,      5,  0,  0,  REV_6502 },
   { "STA",  0x81,  INDEX_INDIRECT,  6,  0,  0,  REV_6502 },
   { "STA",  0x91,  INDIRECT_INDEX,  6,  0,  0,  REV_6502 },

   { "TXS",  0x9A,  IMPLIED,         2,  0,  0,  REV_6502 },
   { "TSX",  0xBA,  IMPLIED,         2,  0,  0,  REV_6502 },
   { "PHA",  0x48,  IMPLIED,         3,  0,  0,  REV_6502 },
   { "PLA",  0x68,  IMPLIED,         4,  0,  0,  REV_6502 },
   { "PHP",  0x08,  IMPLIED,         3,  0,  0,  REV_6502 },
   { "PLP",  0x28,  IMPLIED,         4,  0,  0,  REV_6502 },

   { "STX",  0x86,  ZERO_PAGE,       3,  0,  0,  REV_6502 },
   { "STX",  0x96,  ZERO_PAGE_Y,     4,  0,  0,  REV_6502 },
   { "STX",  0x8E,  ABSOLUTE,        4,  0,  0,  REV_6502 },

   { "STY",  0x84,  ZERO_PAGE,       3,  0,  0,  REV_6502 },
   { "STY",  0x94,  ZERO_PAGE_Y,     4,  0,  0,  REV_6502 },
   { "STY",  0x8C,  ABSOLUTE,        4,  0,  0,  REV_6502 }
};

int opcode_table_sz () {
   return sizeof (_opcode_table) / sizeof (instruction_t);
}

instruction_t **rt_opcode_table;

instruction_t * get_instruction (unsigned char opcode) {
   return rt_opcode_table[(unsigned int)opcode];
}

void construct_opcode_table (enum cpu_revision revision) {
   rt_opcode_table = (instruction_t **)calloc (256, sizeof (instruction_t *));
   // TODO: Handle errors for calloc here.
   for (int i = 0;i < opcode_table_sz();i++) {
      instruction_t *instruction = &_opcode_table [i];
      if (instruction->cpu_revision & revision) {
         if (rt_opcode_table[instruction->opcode] != (instruction_t *)NULL) {
            printf ("Instruction collision at slot %d (%02x)\n", instruction->opcode, instruction->opcode);
            printf ("Existing instructon: %02x %s\n", \
                  rt_opcode_table[instruction->opcode]->opcode, \
                  rt_opcode_table[instruction->opcode]->mnemonic);
            printf ("Attempted to overwrite with %s\n", instruction->mnemonic);
         }
         else {
            rt_opcode_table [instruction->opcode] = instruction;
         }
      }
   }
};

void print_opcode_table () {
   for (int i = 0; i < 256; i++) {
      instruction_t *instruction = rt_opcode_table[i];
      if (instruction == NULL) {
         /** printf ("%03d: Empty instruction slot\n", i); */
         continue;
      }
      printf ("%03d: %02x %s ", i, instruction->opcode, instruction->mnemonic);
      switch (instruction->address_mode) {
         case INVALID:
            break;
         case ACCUMULATOR:
            printf ("; ACCUMULATOR\n");
            break; // Null argument
         case IMMEDIATE:
            printf ("#$imm\n");
            break; // #$imm
         case IMPLIED:
            printf ("; IMPLIED\n");
            break; // Null argument
         case RELATIVE:
            printf ("; IMPLIED\n");
            break; // $xx
         case ABSOLUTE:
            printf ("$xxxx\n");
            break; // $xxxx
         case ZERO_PAGE:
            printf ("$xx\n");
            break; // $xx
         case INDIRECT:
            printf ("$xxxx\n");
            break; // $xxxx
         case ABSOLUTE_X:
            printf ("$xxxx,X\n");
            break; // $xxxx,X
         case ABSOLUTE_Y:
            printf ("$xxxx,Y\n");
            break; // $xxxx,Y
         case ZERO_PAGE_X:
            printf ("$xx,X\n");
            break; // $xx,X
         case ZERO_PAGE_Y:
            printf ("$xx,Y\n");
            break; // $xx,Y (used for LDX instruction)
         case INDEX_INDIRECT:
            printf ("($xx,X)\n");
            break; // ($xx,X)
         case INDIRECT_INDEX:
            printf ("($xx),Y\n");
            break; // ($xx),Y
         default:
            printf ("; Unrecognised address mode.\n");
            break;
      }
   }
}
