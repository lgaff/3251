#include "opcodes.h"
#include "file.h"
#include "diassemble.h"
#include "types.h"
#include "debug.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char * argv []) {
   printf ("Constructing opcode table for 6502\n");
   construct_opcode_table (REV_6502);
   char *input_filename = NULL;
   char do_ops = 0;
   unsigned int org = 0;
   int flen = 0;

   char c;
   while ((c = getopt(argc, argv, "i:dabps:")) != -1) {
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
         case 'a': // Print addresses for disassembly
            DEBUG ("do_ops |= %d", DO_FMTADD);
            do_ops |= DO_FMTADD;
            break;
         case 'b': // Print bytes for disassembly
            do_ops |= DO_FMTBYT;
            break;
         case 'p': // pretty-print dissasmbly (implies -a -b)
            do_ops |= DO_FMTADD | DO_FMTBYT;
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
      disassemble (input_fh, org, do_ops);

   return 0;

}

