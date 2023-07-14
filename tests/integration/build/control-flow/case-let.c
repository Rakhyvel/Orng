/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688936108999027143
#define ORNG_1688936108999027143

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
	int64_t _2_t3;
	int64_t _2_t4;
	int64_t _2_t5;
	uint8_t _2_t2;
	int64_t _2_t0;
	int64_t _2_$retval;
	int64_t _2_t7;
	int64_t _2_t8;
	int64_t _2_t9;
	uint8_t _2_t6;
BB0:
	_3_x = 4;
	_2_t3 = 4;
	_2_t4 = _3_x - _2_t3;
	_2_t5 = 1;
	_2_t2 = _2_t4 == _2_t5;
	if (_2_t2) {
		goto BB2;
	} else {
		goto BB19;
	}
BB19:
	_2_t7 = 3;
	_2_t8 = _3_x - _2_t7;
	_2_t9 = 1;
	_2_t6 = _2_t8 == _2_t9;
	if (_2_t6) {
		goto BB9;
	} else {
		goto BB18;
	}
BB18:
	_2_t0 = 10;
	goto BB7;
BB7:
	_2_$retval = _2_t0;
	return _2_$retval;
BB9:
	_2_t0 = 23;
	goto BB7;
BB2:
	_2_t0 = 10;
	goto BB7;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
