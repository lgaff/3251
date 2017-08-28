CC=gcc

override CFLAGS+=-Wall -Werror -xc
OBJECTS=opcodes.o file.o disassemble.o main.o debug.o

all: 3251

3251: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(OBJECTS): %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm *.o
