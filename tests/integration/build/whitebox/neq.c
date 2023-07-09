/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688935200405501517
#define ORNG_1688935200405501517

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
	int64_t* _2_t1;
	int64_t* _3_y;
	int64_t _2_t5;
	int64_t _2_t6;
	uint8_t _2_t4;
	int64_t _2_t2;
	int64_t _2_$retval;
	double _2_t10;
	uint8_t _2_t7;
	int64_t _2_t8;
	int64_t _2_t9;
BB0:
	_3_x = 3;
	_2_t1 = &_3_x;
	_3_y = _2_t1;
	_2_t5 = *_2_t1;
	_2_t6 = 5;
	_2_t4 = _2_t5 != _2_t6;
	if (!_2_t4) {
		goto BB16;
	} else {
		goto BB5;
	}
BB5:
	_2_t2 = 33;
	goto BB8;
BB8:
	_2_$retval = _2_t2;
	return _2_$retval;
BB16:
	_2_t8 = 4;
	_2_t9 = *_3_y;
	_2_t7 = _2_t8 > _2_t9;
	if (!_2_t7) {
		goto BB15;
	} else {
		goto BB12;
	}
BB12:
	_2_t10 = 3.0e+00;
	_2_t7 = _2_t9 >= _2_t10;
	if (!_2_t7) {
		goto BB15;
	} else {
		goto BB5;
	}
BB15:
	_2_t2 = 10;
	goto BB8;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
