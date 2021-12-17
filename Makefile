CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic -g -O2 $(shell pkg-config --cflags gmp)
LFLAGS = $(shell pkg-config --libs gmp)
OBJS = gmp_rationalize.o

all: gmp_rationalize

gmp_rationalize: $(OBJS)
	$(CC) $(LFLAGS) -o gmp_rationalize $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) gmp_rationalize $(OBJS)

scan-build: clean
	scan-build --use-cc=clang make

format:
	clang-format -i -style=file *.[ch]

.PHONY: all clean scan-build format
