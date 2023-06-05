/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685933745
#define ORNG_1685933745

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _2_main();

int64_t _2_main() {
	int64_t _2_t1;
	int64_t* _2_t4;
	int64_t _2_t5;
	int64_t _2_t6;
	uint8_t _2_t3;
	uint8_t _2_t7;
	uint8_t _2_t9;
	uint8_t _2_t11;
	int64_t _2_t12;
	int64_t _2_$retval;
BB0:
	_2_t1 = 0;
	_2_t4 = &_2_t1;
	_2_t5 = *_2_t4;
	_2_t6 = 1;
	_2_t3 = _2_t5 == _2_t6;
	if (!_2_t3) {
		goto BB9;
	} else {
		goto BB1;
	}
BB1:
	_2_t3 = 1;
	goto BB2;
BB2:
	_2_t7 = !_2_t3;
	_2_t9 = !_2_t7;
	_2_t11 = !_2_t9;
	if (!_2_t11) {
		goto BB7;
	} else {
		goto BB3;
	}
BB3:
	_2_t12 = 31;
	goto BB6;
BB6:
	_2_$retval = _2_t12;
	return _2_$retval;
BB7:
	_2_t12 = 10;
	goto BB6;
BB9:
	_2_t3 = 0;
	goto BB2;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
