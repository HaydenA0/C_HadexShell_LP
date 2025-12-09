compiler = gcc
compiler_flags = -Wall -Wextra -ggdb -I./src/lib
output = ./bin/hadex

.PHONY: all run debug compile


sources = *.c src/lib/*.c

all: $(output) run

build: $(sources)
	$(compiler) $(compiler_flags) $(sources) -o $(output)

run: $(output)
	./$(output)

debug: $(output)
	gdb ./$(output)

