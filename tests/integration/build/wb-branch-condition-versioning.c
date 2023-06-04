/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685907401
#define ORNG_1685907401

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	uint8_t _145_found;
	int64_t _146_n;
	int64_t _144_t5;
	uint8_t _144_t3;
	int64_t _144_t12;
	uint8_t _144_t10;
	int64_t _144_t15;
	int64_t _144_t17;
	int64_t _144_$retval;
BB0:
	_145_found = 0;
	_146_n = 0;
	goto BB1;
BB1:
	_144_t5 = 10;
	_144_t3 = _146_n < _144_t5;
	if (!_144_t3) {
		goto BB26;
	} else {
		goto BB2;
	}
BB2:
	if (!_145_found) {
		goto BB7;
	} else {
		goto BB5;
	}
BB5:
	_146_n = 100;
	goto BB7;
BB7:
	_144_t12 = 6;
	_144_t10 = _146_n == _144_t12;
	if (!_144_t10) {
		goto BB13;
	} else {
		goto BB8;
	}
BB8:
	_145_found = 1;
	goto BB13;
BB13:
	_144_t15 = 1;
	_146_n = _146_n + _144_t15;
	goto BB1;
BB26:
	if (!_145_found) {
		goto BB24;
	} else {
		goto BB20;
	}
BB20:
	_144_t17 = 15;
	goto BB23;
BB23:
	_144_$retval = _144_t17;
	return _144_$retval;
BB24:
	_144_t17 = 4;
	goto BB23;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
