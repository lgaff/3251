#include <stdio.h>

#include "file.h"
#include "diassemble.h"
#include "opcodes.h"

int disassemble (FILE * rom) {
   int pc = 0x8000;
   unsigned char opcode = 0;
   instruction_t *instruction;
   int rom_length = file_length (rom);
   unsigned char operand1 = 0;
   unsigned char operand2 = 0;

   if (rom_length <= 0) {
      printf ("ERROR: Invalid rom, zero-length: %d\n", rom_length);
      return -1;
   }

   while (pc < rom_length + 0x8000) {
      printf ("$%04x> ", pc);
      pc++;
      instruction = (instruction_t *)NULL;
      opcode = getc(rom);
      instruction = get_instruction (opcode);

      if (instruction == (instruction_t *)NULL) {
         printf ("ERROR: unknown instruction found at %04x: %02x\n", pc, opcode);
         return -1;
      } else {
         switch (instruction->address_mode) {
            case INVALID:
               break;
            case ACCUMULATOR:
               printf ("%02x\t: %s", instruction->opcode, instruction->mnemonic);
               break; // Null operand1
            case IMMEDIATE:
               operand1 = getc(rom);
               pc++;
               printf ("%02x %02x\t: %s #$%02x", instruction->opcode, operand1, instruction->mnemonic, operand1);
               break; // #$imm
         case IMPLIED:
               printf ("%02x\t: %s", instruction->opcode, instruction->mnemonic);
            break; // Null operand1
         case RELATIVE:
            operand1 = getc(rom);
            pc++;
            printf ("%02x %02x\t: %s $%04x", opcode, operand1, instruction->mnemonic, pc + (signed char)operand1);
            break; // $xx
         case ABSOLUTE:
            operand1 = getc (rom);
            operand2 = getc (rom);
            pc+=2;
            printf ("%02x %02x %02x\t: %s $%02x%02x", opcode, operand1, operand2, instruction->mnemonic, operand2, operand1);
            pc += 2;
            break; // $xxxx
         case ZERO_PAGE:
            operand1 = getc (rom);
            pc++;
            printf ("%02x %02x\t: %s $%02x", opcode, operand1, instruction->mnemonic, operand1);
            break; // $xx
         case INDIRECT:
            operand1 = getc (rom);
            operand2 = getc (rom);
            pc += 2;
            printf ("%02x %02x %02x\t: %s $%02x%02x", opcode, operand1, operand2, instruction->mnemonic, operand2, operand1);
            break; // $xxxx
         case ABSOLUTE_X:
            operand1 = getc (rom);
            operand2 = getc (rom);
            pc += 2;
            printf ("%02x %02x %02x\t: %s $%02x%02x,X", opcode, operand1, operand2, instruction->mnemonic, operand2, operand1);
            break; // $xxxx,X
         case ABSOLUTE_Y:
            operand1 = getc (rom);
            operand2 = getc (rom);
            pc += 2;
            printf ("%02x %02x %02x\t: %s $%02x%02x,X", opcode, operand1, operand2, instruction->mnemonic, operand2, operand1);
            break; // $xxxx,Y
         case ZERO_PAGE_X:
            operand1 = getc (rom);
            pc++;
            printf ("%02x %02x\t: %s $%02x,X", opcode, operand1, instruction->mnemonic, operand1);
            break; // $xx,X
         case ZERO_PAGE_Y:
            operand1 = getc (rom);
            pc++;
            printf ("%02x %02x\t: %s $%02x,Y", opcode, operand1, instruction->mnemonic, operand1);
            break; // $xx,Y (used for LDX instruction)
         case INDEX_INDIRECT:
            operand1 = getc (rom);
            pc++;
            printf ("%02x %02x\t: %s ($%02x,X)", opcode, operand1, instruction->mnemonic, operand1);
            break; // ($xx,X)
         case INDIRECT_INDEX:
            operand1 = getc (rom);
            pc++;
            printf ("%02x %02x\t: %s ($%02x),Y", opcode, operand1, instruction->mnemonic, operand1);
            break; // ($xx),Y
         default:
            printf ("\nERROR: Unknown address mode encountered for instruction at %04x\n", pc);
            return -1;
            break;
         }
         printf ("\n");
      }
   }
   return 0;
}
