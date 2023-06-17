/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686980573
#define ORNG_1686980573

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _130_main();

/* Function definitions */
int64_t _130_main() {
	int64_t _131_x;
	int64_t _130_t3;
	uint8_t _130_t2;
	int64_t _130_t6;
	int64_t _130_t7;
	int64_t _130_t8;
	uint8_t _130_t5;
	int64_t _130_t11;
	int64_t _130_t9;
	int64_t _130_$retval;
BB0:
	_131_x = 17;
	goto BB1;
BB1:
	_130_t3 = 36;
	_130_t2 = _131_x < _130_t3;
	if (!_130_t2) {
		goto BB17;
	} else {
		goto BB2;
	}
BB2:
	_130_t6 = 2;
	_130_t7 = _131_x % _130_t6;
	_130_t8 = 0;
	_130_t5 = _130_t7 == _130_t8;
	if (!_130_t5) {
		goto BB13;
	} else {
		goto BB8;
	}
BB8:
	_130_t11 = 9;
	_131_x = _131_x + _130_t11;
	goto BB1;
BB13:
	_130_t9 = 1;
	_131_x = _131_x + _130_t9;
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
