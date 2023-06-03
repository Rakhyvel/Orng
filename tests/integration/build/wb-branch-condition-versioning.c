/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685775392
#define ORNG_1685775392

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	uint8_t _116_found;
	int64_t _117_n;
	int64_t _115_t5;
	uint8_t _115_t3;
	int64_t _115_t12;
	uint8_t _115_t10;
	int64_t _115_t15;
	int64_t _115_t17;
	int64_t _115_$retval;
BB0:
	_116_found = 0;
	_117_n = 0;
	goto BB1;
BB1:
	_115_t5 = 10;
	_115_t3 = _117_n < _115_t5;
	if (!_115_t3) {
		goto BB19;
	} else {
		goto BB2;
	}
BB2:
	if (!_116_found) {
		goto BB6;
	} else {
		goto BB5;
	}
BB5:
	_117_n = 100;
	goto BB6;
BB6:
	_115_t12 = 6;
	_115_t10 = _117_n == _115_t12;
	if (!_115_t10) {
		goto BB10;
	} else {
		goto BB7;
	}
BB7:
	_116_found = 1;
	goto BB10;
BB10:
	_115_t15 = 1;
	_117_n = _117_n + _115_t15;
	goto BB1;
BB19:
	if (!_116_found) {
		goto BB18;
	} else {
		goto BB16;
	}
BB16:
	_115_t17 = 15;
	goto BB17;
BB17:
	_115_$retval = _115_t17;
	return _115_$retval;
BB18:
	_115_t17 = 4;
	goto BB17;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
