/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685934718610727157
#define ORNG_1685934718610727157

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _2_main();
int64_t _3_sumDown(int64_t _3_x);

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t0;
	int64_t _2_t2;
	int64_t _2_$retval;
BB0:
	_2_t1 = 8;
	_2_t0 = _3_sumDown(_2_t1);
	_2_t2 = 2;
	_2_$retval = _2_t0 + _2_t2;
	return _2_$retval;
}

int64_t _3_sumDown(int64_t _3_x) {
	int64_t _5_i;
	int64_t _3_t2;
	uint8_t _3_t1;
	int64_t _3_t4;
	int64_t _3_$retval;
BB0:
	_5_i = _3_x;
	goto BB1;
BB1:
	_3_t2 = 0;
	_3_t1 = _5_i >= _3_t2;
	if (!_3_t1) {
		goto BB10;
	} else {
		goto BB2;
	}
BB2:
	_3_x = _3_x + _5_i;
	_3_t4 = 1;
	_5_i = _5_i - _3_t4;
	goto BB1;
BB10:
	_3_$retval = _3_x;
	return _3_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
