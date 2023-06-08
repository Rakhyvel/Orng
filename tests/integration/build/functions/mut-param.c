/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686109156
#define ORNG_1686109156

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _12_main();
int64_t _13_sumDown(int64_t x);

int64_t _12_main() {
	int64_t (*_12_t0)(int64_t x);
	int64_t _12_t2;
	int64_t _12_t1;
	int64_t _12_t3;
	int64_t _12_$retval;
BB0:
	_12_t0 = _13_sumDown;
	_12_t2 = 8;
	_12_t1 = _12_t0(_12_t2);
	_12_t3 = 2;
	_12_$retval = _12_t1 + _12_t3;
	return _12_$retval;
}

int64_t _13_sumDown(int64_t x) {
	int64_t _15_i;
	int64_t _13_t4;
	uint8_t _13_t2;
	int64_t _13_t9;
	int64_t _13_$retval;
BB0:
	_15_i = x;
	goto BB1;
BB1:
	_13_t4 = 0;
	_13_t2 = _15_i >= _13_t4;
	if (!_13_t2) {
		goto BB10;
	} else {
		goto BB2;
	}
BB2:
	x = x + _15_i;
	_13_t9 = 1;
	_15_i = _15_i - _13_t9;
	goto BB1;
BB10:
	_13_$retval = x;
	return _13_$retval;
}


int main()
{
  printf("%ld",_12_main());
  return 0;
}

#endif
