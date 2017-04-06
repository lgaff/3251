#include "opcodes.h"
#include "file.h"
#include "diassemble.h"
#include <stdio.h>

int main (int argc, char * argv []) {
   printf ("Constructing opcode table for 6502\n");
   construct_opcode_table (REV_6502);

   /** printf ("Printing 6502 instruction table\n"); */
   /** print_opcode_table (); */
   /**  */
   /** printf ("Done listing 6502 instructions\n"); */
   /**  */
   /** instruction_t *instruction = get_instruction (238); */
   /** printf ("Instruction at slot 238 is %s\n", instruction->mnemonic); */
   /**  */

   if (!argv[1]) {
      printf ("ERROR: specify ROM file\n");
      return -1;
   }
   printf ("Diassembling file %2\n", argv[1]);

   FILE * test = NULL;
   int flen = open_rom (argv[1], &test);
   if (!(flen > 0)) {
      printf ("ERROR: ROM file invalid");
      return -1;
   }
   printf ("rom length %d\n", flen);

   disassemble (test);

   return 0;

}

