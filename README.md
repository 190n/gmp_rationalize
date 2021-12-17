# gmp_rationalize

This is a small program to convert a decimal number (like `1.8`) into a reduced fraction (like `9/5`), using GMP for handling arbitrary-precision rational numbers.

## Usage

Compile with `make`. You need clang, and GMP installed somewhere that pkg-config knows about it. Then run it with `./gmp_rationalize <number>`.

```
gmp_rationalize $ make
clang -Wall -Wextra -Werror -Wpedantic -g -O2  -c gmp_rationalize.c
clang -lgmp  -o gmp_rationalize gmp_rationalize.o
gmp_rationalize $ ./gmp_rationalize 1.5625
1.5625 = 25/16
```
