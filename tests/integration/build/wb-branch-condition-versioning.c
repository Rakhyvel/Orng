/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685902519
#define ORNG_1685902519

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	uint8_t _137_found;
	int64_t _138_n;
	int64_t _136_t5;
	uint8_t _136_t3;
	int64_t _136_t12;
	uint8_t _136_t10;
	int64_t _136_t15;
	int64_t _136_t17;
	int64_t _136_$retval;
BB0:
	_137_found = 0;
	_138_n = 0;
	goto BB1;
BB1:
	_136_t5 = 10;
	_136_t3 = _138_n < _136_t5;
	if (!_136_t3) {
		goto BB26;
	} else {
		goto BB2;
	}
BB2:
	if (!_137_found) {
		goto BB7;
	} else {
		goto BB5;
	}
BB5:
	_138_n = 100;
	goto BB7;
BB7:
	_136_t12 = 6;
	_136_t10 = _138_n == _136_t12;
	if (!_136_t10) {
		goto BB13;
	} else {
		goto BB8;
	}
BB8:
	_137_found = 1;
	goto BB13;
BB13:
	_136_t15 = 1;
	_138_n = _138_n + _136_t15;
	goto BB1;
BB26:
	if (!_137_found) {
		goto BB24;
	} else {
		goto BB20;
	}
BB20:
	_136_t17 = 15;
	goto BB23;
BB23:
	_136_$retval = _136_t17;
	return _136_$retval;
BB24:
	_136_t17 = 4;
	goto BB23;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
