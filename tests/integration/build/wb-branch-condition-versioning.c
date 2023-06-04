/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685915967
#define ORNG_1685915967

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	uint8_t _162_found;
	int64_t _163_n;
	int64_t _161_t5;
	uint8_t _161_t3;
	int64_t _161_t12;
	uint8_t _161_t10;
	int64_t _161_t15;
	int64_t _161_t17;
	int64_t _161_$retval;
BB0:
	_162_found = 0;
	_163_n = 0;
	goto BB1;
BB1:
	_161_t5 = 10;
	_161_t3 = _163_n < _161_t5;
	if (!_161_t3) {
		goto BB26;
	} else {
		goto BB2;
	}
BB2:
	if (!_162_found) {
		goto BB7;
	} else {
		goto BB5;
	}
BB5:
	_163_n = 100;
	goto BB7;
BB7:
	_161_t12 = 6;
	_161_t10 = _163_n == _161_t12;
	if (!_161_t10) {
		goto BB13;
	} else {
		goto BB8;
	}
BB8:
	_162_found = 1;
	goto BB13;
BB13:
	_161_t15 = 1;
	_163_n = _163_n + _161_t15;
	goto BB1;
BB26:
	if (!_162_found) {
		goto BB24;
	} else {
		goto BB20;
	}
BB20:
	_161_t17 = 15;
	goto BB23;
BB23:
	_161_$retval = _161_t17;
	return _161_$retval;
BB24:
	_161_t17 = 4;
	goto BB23;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
