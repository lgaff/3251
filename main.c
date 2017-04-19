#include "opcodes.h"
#include "file.h"
#include "diassemble.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

enum ops {
   DO_DISASM = 1 << 0
};

int main (int argc, char * argv []) {
   printf ("Constructing opcode table for 6502\n");
   construct_opcode_table (REV_6502);
   char *input_filename = NULL;
   char do_ops = 0;
   unsigned int org = 0;
   int flen = 0;

   char c;
   while ((c = getopt(argc, argv, "i:ds:")) != -1) {
      switch (c) {
         case 'i':
            input_filename = optarg;
            break;
         case 'd':
            do_ops |= DO_DISASM;
            break;
         case 's':
            org = atoi(optarg);
            printf ("Setting ROM offset to %d\n", org);
            break;
      }
   }


   FILE * input_fh;
   if (input_filename == NULL) {
      printf ("TODO Lindsay must implement stdin processing\n");
      return 0;
   } else {
      flen = open_rom (input_filename, &input_fh);
   }
   if (!(flen > 0)) {
      printf ("ERROR: ROM file invalid");
      return -1;
   }
   printf ("rom length %d\n", flen);

   if (do_ops & DO_DISASM)
      disassemble (input_fh, org);

   return 0;

}

