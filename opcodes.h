/** instructions.h defines the 6502 Operation code table and address modes.
 */

#ifndef _INSTRUCTIONS_H
#define _INSTRUCTIONS_H

enum address_mode {
        INVALID        = 1 << 0,
        ACCUMULATOR    = 1 << 1, // Null argument
        IMMEDIATE      = 1 << 2, // #$imm
        IMPLIED        = 1 << 3, // Null argument
        RELATIVE       = 1 << 4, // $xx
        ABSOLUTE       = 1 << 5, // $xxxx
        ZERO_PAGE      = 1 << 6, // $xx
        INDIRECT       = 1 << 7, // $xxxx
        ABSOLUTE_X     = 1 << 8, // $xxxx,X
        ABSOLUTE_Y     = 1 << 9, // $xxxx,Y
        ZERO_PAGE_X    = 1 << 10, // $xx,X
        ZERO_PAGE_Y    = 1 << 11, // $xx,Y (used for LDX instruction)
        INDEX_INDIRECT = 1 << 12, // ($xx,X)
        INDIRECT_INDEX = 1 << 13 // ($xx),Y
};

// CPU revisions supported by an opcode, including undocumented and illegal instructions
enum cpu_revision {
   REV_6502           = 1   <<   0,
   REV_65C02          = 1   <<   1,
   REV_65C816         = 1   <<   2,
   REV_UNDOCUMENTED   = 1   <<   3
};

// TODO: Consider page-crossing cycles in opcode table. Will need an extra field in the struct.
#define ADD_CYCLE_IF_PG_CROSS 1

/**
 .. :C:struct: instruction_t
    Defines an instruction supported by the processor. Can be used as a translation unit for
    converting binary opcodes into assembler mnemonics, and vice versa. Instruction timings included for
    informational purposes (eg assembler diagnostics/analysis), or implementing an emulator.

 .. :C:member:: const char* mnemonic
    A 3 character string literal containing the assembler mnemonic associated with this instruction
 .. :C:member:: const unsigned char opcode
    The byte representation of the instruction.
 ..NOTE::
   The expected use of this type is as an entry into :C:data:`instruction_table`, whose index serves the same purpose.
   The opcode is kept inside the struct as the instruction tables are dynamically generated on program load
   based on desired CPU revision and/or inclusion of undocumented opcodes, so the base instructions are kept in an unsorted
   array.

 .. :C:member: enum address_mode address_mode
    The addressing mode used for this instruction by the processor.

 .. :C:member: unsigned char cycle_count
    The number of CPU cycles required to execute this instruction.

 .. :C:member: unsigned char cycle_mod
    Some instructions have variable timings, depending on external factors such as page boundary crossings. this member declares booleans for when this should apply.

 .. :C:member: unsigned char affects_flags
    Flags which are modified by this instruction are indicated here.

 .. :C:member: unsigned char cpu_revision
    Indicates the earliest processor revision for which the instruction appears.
    Valid CPU revisions are indicated by :C:type:`cpu_revision`. This also indicates whether or not an instruction is undocumented.
*/

typedef struct INSTRUCTION {
   const char * mnemonic;
   const unsigned char opcode;
   enum address_mode address_mode;
   unsigned char cycle_count;
   unsigned char cycle_mod;
   unsigned char affects_flags;
   unsigned char cpu_revision;
} instruction_t;

#endif // _INSTRUCTIONS_H
