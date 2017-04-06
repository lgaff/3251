#include "opcodes.h"

#include <stdio.h>

int main (void) {
   printf ("Constructing opcode table for 6502\n");
   construct_opcode_table (REV_6502);

   printf ("Printing 6502 instruction table\n");
   print_opcode_table ();

   printf ("Done listing 6502 instructions\n");

   instruction_t *instruction = get_instruction (238);
   printf ("Instruction at slot 238 is %s\n", instruction->mnemonic);
   return 0;
}

