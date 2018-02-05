#include <stdio.h>
#include <errno.h>

#include "file.h"

int open_rom (char * fname, FILE **buf) {
  int flen = 0;

  *buf = fopen (fname, "rb");

  if (*buf == NULL) {
    printf ("ERROR: Could not open rom file %s: %d\n", fname, errno);
    return 0;
  }
  fseek (*buf, 0, SEEK_END);
  flen = ftell(*buf);
  fseek (*buf, 0, SEEK_SET);

  return flen;
}

int file_length (FILE * stream) {
   int flen = 0;
   fseek (stream, 0, SEEK_END);
   flen = ftell(stream);
   fseek (stream, 0, SEEK_SET);
   return flen;
}


