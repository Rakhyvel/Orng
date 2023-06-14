/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686709170
#define ORNG_1686709170

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t* _3_y;
	int64_t _2_t6;
	int64_t _2_t7;
	uint8_t _2_t8;
	int64_t _2_t3;
	int64_t _2_$retval;
	int64_t _2_t10;
	int64_t _2_t12;
	uint8_t _2_t9;
	double _2_t13;
BB0:
	_2_t1 = 3;
	_3_y = &_2_t1;
	_2_t6 = *_3_y;
	_2_t7 = 5;
	_2_t8 = _2_t6 != _2_t7;
	if (!_2_t8) {
		goto BB9;
	} else {
		goto BB3;
	}
BB3:
	_2_t3 = 33;
	goto BB6;
BB6:
	_2_$retval = _2_t3;
	return _2_$retval;
BB9:
	_2_t10 = 4;
	_2_t12 = *_3_y;
	_2_t9 = _2_t10 > _2_t12;
	if (!_2_t9) {
		goto BB13;
	} else {
		goto BB10;
	}
BB10:
	_2_t13 = 3.0e+00;
	_2_t9 = _2_t12 >= _2_t13;
	if (!_2_t9) {
		goto BB13;
	} else {
		goto BB3;
	}
BB13:
	_2_t3 = 10;
	goto BB6;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
