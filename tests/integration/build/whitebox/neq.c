/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686712671
#define ORNG_1686712671

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _3_x;
	int64_t* _3_y;
	int64_t _2_t4;
	int64_t _2_t5;
	uint8_t _2_t6;
	int64_t _2_t2;
	int64_t _2_$retval;
	int64_t _2_t8;
	int64_t _2_t9;
	uint8_t _2_t7;
	double _2_t10;
BB0:
	_3_x = 3;
	_3_y = &_3_x;
	_2_t4 = *_3_y;
	_2_t5 = 5;
	_2_t6 = _2_t4 != _2_t5;
	if (!_2_t6) {
		goto BB9;
	} else {
		goto BB3;
	}
BB3:
	_2_t2 = 33;
	goto BB6;
BB6:
	_2_$retval = _2_t2;
	return _2_$retval;
BB9:
	_2_t8 = 4;
	_2_t9 = *_3_y;
	_2_t7 = _2_t8 > _2_t9;
	if (!_2_t7) {
		goto BB13;
	} else {
		goto BB10;
	}
BB10:
	_2_t10 = 3.0e+00;
	_2_t7 = _2_t9 >= _2_t10;
	if (!_2_t7) {
		goto BB13;
	} else {
		goto BB3;
	}
BB13:
	_2_t2 = 10;
	goto BB6;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
