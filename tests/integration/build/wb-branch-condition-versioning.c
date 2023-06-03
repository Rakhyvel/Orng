/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685778818
#define ORNG_1685778818

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	uint8_t _129_found;
	int64_t _130_n;
	int64_t _128_t5;
	uint8_t _128_t3;
	int64_t _128_t12;
	uint8_t _128_t10;
	int64_t _128_t15;
	int64_t _128_t17;
	int64_t _128_$retval;
BB0:
	_129_found = 0;
	_130_n = 0;
	goto BB1;
BB1:
	_128_t5 = 10;
	_128_t3 = _130_n < _128_t5;
	if (!_128_t3) {
		goto BB25;
	} else {
		goto BB2;
	}
BB2:
	if (!_129_found) {
		goto BB7;
	} else {
		goto BB5;
	}
BB5:
	_130_n = 100;
	goto BB7;
BB7:
	_128_t12 = 6;
	_128_t10 = _130_n == _128_t12;
	if (!_128_t10) {
		goto BB13;
	} else {
		goto BB8;
	}
BB8:
	_129_found = 1;
	goto BB13;
BB13:
	_128_t15 = 1;
	_130_n = _130_n + _128_t15;
	goto BB1;
BB25:
	if (!_129_found) {
		goto BB23;
	} else {
		goto BB19;
	}
BB19:
	_128_t17 = 15;
	goto BB22;
BB22:
	_128_$retval = _128_t17;
	return _128_$retval;
BB23:
	_128_t17 = 4;
	goto BB22;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
