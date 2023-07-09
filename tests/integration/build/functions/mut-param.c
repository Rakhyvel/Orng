/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688936349848404476
#define ORNG_1688936349848404476

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();
int64_t _4_sumDown(int64_t _4_x);

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t0;
	int64_t _2_t2;
	int64_t _2_$retval;
BB0:
	_2_t1 = 8;
	_2_t0 = _4_sumDown(_2_t1);
	_2_t2 = 2;
	_2_$retval = _2_t0 + _2_t2;
	return _2_$retval;
}

int64_t _4_sumDown(int64_t _4_x) {
	int64_t _6_i;
	int64_t _4_t2;
	uint8_t _4_t1;
	int64_t _4_t4;
	int64_t _4_$retval;
BB0:
	_6_i = _4_x;
	goto BB1;
BB1:
	_4_t2 = 0;
	_4_t1 = _6_i >= _4_t2;
	if (!_4_t1) {
		goto BB10;
	} else {
		goto BB2;
	}
BB2:
	_4_x = _4_x + _6_i;
	_4_t4 = 1;
	_6_i = _6_i - _4_t4;
	goto BB1;
BB10:
	_4_$retval = _4_x;
	return _4_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
