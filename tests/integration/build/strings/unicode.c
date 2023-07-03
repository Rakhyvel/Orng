/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688344203871266608
#define ORNG_1688344203871266608

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	uint8_t* _0;
	int64_t _1;
} struct0;

/* Interned Strings */
char* string_0 = "\x48\x65\x6c\x6c\x6f\x2c\x20\x4f\x72\x6e\x67\x21\x20\xf0\x9f\x8d\x8a";

/* Function forward definitions */
struct0 _2_main();

/* Function definitions */
struct0 _2_main() {
	struct0 _2_$retval;
BB0:
	_2_$retval = (struct0) {string_0, 19};
	return _2_$retval;
}


int main()
{
  printf("%s",_2_main()._0);
  return 0;
}

#endif
