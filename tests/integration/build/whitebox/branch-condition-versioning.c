/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687131003
#define ORNG_1687131003

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _65_main();

/* Function definitions */
int64_t _65_main() {
	uint8_t _66_found;
	int64_t _67_n;
	int64_t _65_t4;
	uint8_t _65_t3;
	int64_t _65_t9;
	uint8_t _65_t8;
	int64_t _65_t11;
	int64_t _65_t13;
	int64_t _65_$retval;
BB0:
	_66_found = 0;
	_67_n = 0;
	goto BB1;
BB1:
	_65_t4 = 10;
	_65_t3 = _67_n < _65_t4;
	if (!_65_t3) {
		goto BB26;
	} else {
		goto BB2;
	}
BB2:
	if (!_66_found) {
		goto BB7;
	} else {
		goto BB5;
	}
BB5:
	_67_n = 100;
	goto BB7;
BB7:
	_65_t9 = 6;
	_65_t8 = _67_n == _65_t9;
	if (!_65_t8) {
		goto BB13;
	} else {
		goto BB8;
	}
BB8:
	_66_found = 1;
	goto BB13;
BB13:
	_65_t11 = 1;
	_67_n = _67_n + _65_t11;
	goto BB1;
BB26:
	if (!_66_found) {
		goto BB24;
	} else {
		goto BB20;
	}
BB20:
	_65_t13 = 15;
	goto BB23;
BB23:
	_65_$retval = _65_t13;
	return _65_$retval;
BB24:
	_65_t13 = 4;
	goto BB23;
}


int main()
{
  printf("%ld",_65_main());
  return 0;
}

#endif
