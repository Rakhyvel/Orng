/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685256120
#define ORNG_1685256120

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	uint8_t _123_found;
	int64_t _124_n;
	int64_t _122_t5;
	uint8_t _122_t3;
	int64_t _122_t12;
	uint8_t _122_t10;
	int64_t _122_t15;
	int64_t _122_t17;
	int64_t _122_$retval;
BB0:
	_123_found = 0;
	_124_n = 0;
	goto BB1;
BB1:
	_122_t5 = 10;
	_122_t3 = _124_n < _122_t5;
	if (!_122_t3) {
		goto BB19;
	} else {
		goto BB2;
	}
BB2:
	if (!_123_found) {
		goto BB6;
	} else {
		goto BB5;
	}
BB5:
	_124_n = 100;
	goto BB6;
BB6:
	_122_t12 = 6;
	_122_t10 = _124_n == _122_t12;
	if (!_122_t10) {
		goto BB10;
	} else {
		goto BB7;
	}
BB7:
	_123_found = 1;
	goto BB10;
BB10:
	_122_t15 = 1;
	_124_n = _124_n + _122_t15;
	goto BB1;
BB19:
	if (!_123_found) {
		goto BB18;
	} else {
		goto BB16;
	}
BB16:
	_122_t17 = 15;
	goto BB17;
BB17:
	_122_$retval = _122_t17;
	return _122_$retval;
BB18:
	_122_t17 = 4;
	goto BB17;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
