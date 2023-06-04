/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685922416
#define ORNG_1685922416

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _130_main();

int64_t _130_main() {
	int64_t _131_x;
	int64_t _130_t4;
	uint8_t _130_t2;
	int64_t _130_t8;
	int64_t _130_t9;
	int64_t _130_t10;
	uint8_t _130_t6;
	int64_t _130_t15;
	int64_t _130_t12;
	int64_t _130_$retval;
BB0:
	_131_x = 17;
	goto BB1;
BB1:
	_130_t4 = 36;
	_130_t2 = _131_x < _130_t4;
	if (!_130_t2) {
		goto BB17;
	} else {
		goto BB2;
	}
BB2:
	_130_t8 = 2;
	_130_t9 = _131_x % _130_t8;
	_130_t10 = 0;
	_130_t6 = _130_t9 == _130_t10;
	if (!_130_t6) {
		goto BB13;
	} else {
		goto BB8;
	}
BB8:
	_130_t15 = 9;
	_131_x = _131_x + _130_t15;
	goto BB1;
BB13:
	_130_t12 = 1;
	_131_x = _131_x + _130_t12;
	goto BB8;
BB17:
	_130_$retval = _131_x;
	return _130_$retval;
}


int main()
{
  printf("%ld",_130_main());
  return 0;
}

#endif
