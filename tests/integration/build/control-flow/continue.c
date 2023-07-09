/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688936120427056099
#define ORNG_1688936120427056099

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _3_x;
	int64_t _4_i;
	int64_t _2_t4;
	uint8_t _2_t3;
	int64_t _2_t7;
	int64_t _2_t8;
	int64_t _2_t9;
	uint8_t _2_t6;
	int64_t _2_t12;
	int64_t _2_t10;
	int64_t _2_$retval;
BB0:
	_3_x = 0;
	_4_i = 0;
	goto BB1;
BB1:
	_2_t4 = 70;
	_2_t3 = _4_i < _2_t4;
	if (!_2_t3) {
		goto BB16;
	} else {
		goto BB2;
	}
BB2:
	_2_t7 = 2;
	_2_t8 = _4_i % _2_t7;
	_2_t9 = 0;
	_2_t6 = _2_t8 == _2_t9;
	if (!_2_t6) {
		goto BB12;
	} else {
		goto BB8;
	}
BB8:
	_2_t12 = 1;
	_4_i = _4_i + _2_t12;
	goto BB1;
BB12:
	_2_t10 = 1;
	_3_x = _3_x + _2_t10;
	goto BB8;
BB16:
	_2_$retval = _3_x;
	return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
