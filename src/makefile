compiler = gcc
compiler_flags = -Wall -Wextra -ggdb -I./lib
output = ./bin/hadex

.PHONY: all run debug compile


sources = *.c lib/*.c

all: $(output) run

$(output): $(sources)
	$(compiler) $(compiler_flags) $(sources) -o $(output)

run: $(output)
	./$(output)

debug: $(output)
	gdb ./$(output)

