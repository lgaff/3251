#ifndef _DISASSEMBLE_H
#define _DISASSEMBLE_H
#include <stdio.h>

/**
 * .. :c:function: int disassemble (char *rom)
 *    Disassemble rom and print the listing to stdout.
 *    :param char * rom: file name of a rom to be disassembled
 *    :return int: 0 for success, 1 non-zero for failure.
 * ..TODO:
 *   Eventually, disassemble should disassemble to a buffer rather than dumping to the console.
 */

int disassemble (FILE *);

#endif // _DISASSEMBLE_H
