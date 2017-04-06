CC=gcc

CFLAGS=-Wall -Werror -xc
OBJECTS=opcodes.o file.o disassemble.o main.o

all: 3251d

3251d: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(OBJECTS): %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm *.o
