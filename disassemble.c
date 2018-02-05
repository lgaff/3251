#include <stdio.h>

#include "file.h"
#include "diassemble.h"
#include "opcodes.h"
#include "types.h"
#include "debug.h"

int disassemble (FILE * rom, int org, int opts) {
   DEBUG ("ENTER disassemble (%02x, %d, %08x);", rom, org, opts);
   int pc = org;
   unsigned char opcode = 0;
   instruction_t *instruction;
   int rom_length = file_length (rom);
   unsigned char operand1 = 0;
   unsigned char operand2 = 0;

   if (rom_length <= 0) {
      printf ("ERROR: Invalid rom, zero-length: %d\n", rom_length);
      return -1;
   }

   while (pc < rom_length + org) {
      DEBUG ("LOOP ENTER %04X %02X", pc, opcode);
      if (opts & DO_FMTADD) {
         printf ("$%04X> ", pc);
      }
      pc++;
      instruction = (instruction_t *)NULL;
      opcode = getc(rom);
      DEBUG("OPCODE %02X", opcode);
      instruction = get_instruction (opcode);
      if (instruction == (instruction_t *)NULL) {
         if (opts & DO_FMTBYT)
            printf ("%02X\t: ", opcode);
         printf (".BYTE %02X\t\t ; Unknown instruction, possibly data?\n", opcode);
      } else {
         switch (instruction->address_mode) {
            case INVALID:
               printf ("\nERROR: Invalid address mode encountered for instruction at %02X\n", pc);
               return -1;
               break;
            case ACCUMULATOR:
               if (opts & DO_FMTBYT) printf ("%02X:\t", instruction->opcode);
               printf ("%s", instruction->mnemonic);
               break; // Null operand1
            case IMMEDIATE:
               operand1 = getc(rom);
               pc++;
               if (opts & DO_FMTBYT) printf ("%02X %02X:\t", instruction->opcode, operand1);
               printf ("%s #$%02X", instruction->mnemonic, operand1);
               break; // #$imm
            case IMPLIED:
               if (opts & DO_FMTBYT) printf ("%02X:\t", instruction->opcode);
               printf ("%s", instruction->mnemonic);
               break; // Null operand1
            case RELATIVE:
               operand1 = getc(rom);
               pc++;
               if (opts & DO_FMTBYT) printf ("%02X %02X:\t", instruction->opcode, operand1);
               printf ("%s $%02X", instruction->mnemonic, pc + (signed char)operand1);
               break; // $xx
         case ABSOLUTE:
            operand1 = getc (rom);
            operand2 = getc (rom);
            pc+=2;
            if (opts & DO_FMTBYT) printf ("%02X %02X %02X: ", instruction->opcode, operand1, operand2);
            printf ("%s $%02X%02X", instruction->mnemonic, operand2, operand1);
            break; // $xxxx
         case ZERO_PAGE:
            operand1 = getc (rom);
            pc++;
            if (opts & DO_FMTBYT) printf ("%02X %02X:\t", instruction->opcode, operand1);
            printf ("%s $%02X", instruction->mnemonic, operand1);
            break; // $xx
         case INDIRECT:
            operand1 = getc (rom);
            operand2 = getc (rom);
            pc += 2;
               if (opts & DO_FMTBYT) printf ("%02X %02X %02X: ", instruction->opcode, operand1, operand2);
            printf ("%s $%02X%02X", instruction->mnemonic, operand2, operand1);
            break; // $xxxx
         case ABSOLUTE_X:
            operand1 = getc (rom);
            operand2 = getc (rom);
 
            pc += 2;
            if (opts & DO_FMTBYT) printf ("%02X %02X %02X: ", instruction->opcode, operand1, operand2);
            printf ("%s $%02X%02X,X", instruction->mnemonic, operand2, operand1);
            break; // $xxxx,X
         case ABSOLUTE_Y:
            operand1 = getc (rom);
            operand2 = getc (rom);
            pc += 2;
            if (opts & DO_FMTBYT) printf ("%02X %02X %02X: ", instruction->opcode, operand1, operand2);
            printf ("%s $%02X%02X,Y", instruction->mnemonic, operand2, operand1);
            break; // $xxxx,Y
         case ZERO_PAGE_X:
            operand1 = getc (rom);
            pc++;
               if (opts & DO_FMTBYT) printf ("%02X %02X:\t", instruction->opcode, operand1);
            printf ("%s $%02X,X", instruction->mnemonic, operand1);
            break; // $xx,X
         case ZERO_PAGE_Y:
            operand1 = getc (rom);
            pc++;
               if (opts & DO_FMTBYT) printf ("%02X %02X:\t", instruction->opcode, operand1);
            printf ("%s $%02X,Y", instruction->mnemonic, operand1);
            break; // $xx,Y (used for LDX instruction)
         case INDEX_INDIRECT:
            operand1 = getc (rom);
            pc++;
               if (opts & DO_FMTBYT) printf ("%02X %02X:\t", instruction->opcode, operand1);
            printf ("%s ($%02X,X)", instruction->mnemonic, operand1);
            break; // ($xx,X)
         case INDIRECT_INDEX:
            operand1 = getc (rom);
            pc++;
               if (opts & DO_FMTBYT) printf ("%02X %02X:\t", instruction->opcode, operand1);
            printf ("%s ($%02X),Y", instruction->mnemonic, operand1);
            break; // ($xx),Y
         default:
            printf ("\nERROR: Unknown address mode encountered for instruction at %02X\n", pc);
            return -1;
            break;
         }
         if (opts & DO_FMTBYT) printf ("\t;");
         printf ("\n");

      }
   }
   return 0;
}
