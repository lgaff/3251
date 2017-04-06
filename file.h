#ifndef _FILE_H
#define _FILE_H

#include <stdio.h>

/** :c:function: int open_rom (char * fname, FILE * stream)
 *  open a ROM file fname and assign the handle to stream.
 *  :return: the length of the ROM file
 */
int open_rom (char *, FILE **);

/**
 * .. :c:function: int file_length (FILE * stream)
 *    Retrieve the length in bytes of stream
 *    :return int: length of the file open at stream
 */
int file_length (FILE * );
#endif // _FILE_H
