/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685907402
#define ORNG_1685907402

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _187_x;
	int64_t _188_i;
	int64_t _186_t5;
	uint8_t _186_t3;
	int64_t _186_t10;
	int64_t _186_$retval;
BB0:
	_187_x = 0;
	_188_i = 0;
	goto BB1;
BB1:
	_186_t5 = 10;
	_186_t3 = _188_i <= _186_t5;
	if (!_186_t3) {
		goto BB10;
	} else {
		goto BB2;
	}
BB2:
	_187_x = _187_x + _188_i;
	_186_t10 = 1;
	_188_i = _188_i + _186_t10;
	goto BB1;
BB10:
	_186_$retval = _187_x;
	return _186_$retval;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
