#include <gmp.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// Convert a decimal number, represented as a string (e.g. "1.8"), into a fraction with a power of
// 10 as the denominator (e.g. "18/10").
// The return value is dynamically allocated and must be freed using free().
//
// input: The null-terminated string to use as input for the conversion.
//
char *fix_decimal(char *input) {
	unsigned int digits_before = 0, digits_after = 0;
	bool seen_decimal = false;
	for (unsigned int i = 0; input[i]; i++) {
		if (input[i] == '.') {
			seen_decimal = true;
		} else if (seen_decimal) {
			digits_after++;
		} else {
			digits_before++;
		}
	}

	unsigned int len = digits_before + digits_after + 2 + digits_after;
	char *result = (char *) malloc((len + 1) * sizeof(char));
	strncpy(result, input, digits_before);
	strncpy(result + digits_before, input + digits_before + 1, digits_after);
	unsigned int slash_index = digits_before + digits_after;
	result[slash_index] = '/';
	result[slash_index + 1] = '1';
	for (unsigned int i = slash_index + 2; i < len; i++) {
		result[i] = '0';
	}
	result[len] = 0;
	return result;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "usage: %s <decimal number to convert>\n", argv[0]);
		return 1;
	}

	mpq_t frac;
	mpq_init(frac);
	char *monke = fix_decimal(argv[1]);
	mpq_set_str(frac, monke, 10);
	mpq_canonicalize(frac);
	gmp_printf("%s = %Qd\n", argv[1], frac);
	mpq_clear(frac);
	free(monke);
	return 0;
}
