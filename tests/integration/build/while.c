/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685915967
#define ORNG_1685915967

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _216_x;
	int64_t _217_i;
	int64_t _215_t5;
	uint8_t _215_t3;
	int64_t _215_t10;
	int64_t _215_$retval;
BB0:
	_216_x = 0;
	_217_i = 0;
	goto BB1;
BB1:
	_215_t5 = 10;
	_215_t3 = _217_i <= _215_t5;
	if (!_215_t3) {
		goto BB10;
	} else {
		goto BB2;
	}
BB2:
	_216_x = _216_x + _217_i;
	_215_t10 = 1;
	_217_i = _217_i + _215_t10;
	goto BB1;
BB10:
	_215_$retval = _216_x;
	return _215_$retval;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
