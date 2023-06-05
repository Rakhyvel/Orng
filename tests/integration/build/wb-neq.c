/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685933745
#define ORNG_1685933745

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _20_main();

int64_t _20_main() {
	int64_t _20_t1;
	int64_t* _21_y;
	int64_t _20_t6;
	int64_t _20_t7;
	uint8_t _20_t8;
	int64_t _20_t3;
	int64_t _20_$retval;
	int64_t _20_t10;
	int64_t _20_t12;
	uint8_t _20_t9;
	double _20_t13;
BB0:
	_20_t1 = 3;
	_21_y = &_20_t1;
	_20_t6 = *_21_y;
	_20_t7 = 5;
	_20_t8 = _20_t6 != _20_t7;
	if (!_20_t8) {
		goto BB9;
	} else {
		goto BB3;
	}
BB3:
	_20_t3 = 33;
	goto BB6;
BB6:
	_20_$retval = _20_t3;
	return _20_$retval;
BB9:
	_20_t10 = 4;
	_20_t12 = *_21_y;
	_20_t9 = _20_t10 > _20_t12;
	if (!_20_t9) {
		goto BB13;
	} else {
		goto BB10;
	}
BB10:
	_20_t13 = 3.0e+00;
	_20_t9 = _20_t12 >= _20_t13;
	if (!_20_t9) {
		goto BB13;
	} else {
		goto BB3;
	}
BB13:
	_20_t3 = 10;
	goto BB6;
}


int main()
{
  printf("%ld",_20_main());
  return 0;
}

#endif
