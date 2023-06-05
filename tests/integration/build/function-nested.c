/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685933745
#define ORNG_1685933745

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _238_main();
int64_t _240_fib(int64_t _240_n);
int64_t _243_add(int64_t _243_x, int64_t _243_y);

int64_t _238_main() {
	int64_t (*_238_t0)(int64_t _240_n);
	int64_t _238_t2;
	int64_t _238_t1;
	int64_t _238_t3;
	int64_t _238_$retval;
BB0:
	_238_t0 = _240_fib;
	_238_t2 = 10;
	_238_t1 = _238_t0(_238_t2);
	_238_t3 = 10;
	_238_$retval = _238_t1 - _238_t3;
	return _238_$retval;
}

int64_t _240_fib(int64_t _240_n) {
	int64_t _240_t3;
	uint8_t _240_t1;
	int64_t _240_t0;
	int64_t _240_$retval;
	int64_t (*_240_t9)(int64_t _243_x, int64_t _243_y);
	int64_t (*_240_t11)(int64_t _240_n);
	int64_t _240_t14;
	int64_t _240_t15;
	int64_t _240_t12;
	int64_t (*_240_t16)(int64_t _240_n);
	int64_t _240_t19;
	int64_t _240_t20;
	int64_t _240_t17;
	int64_t _240_t6;
	uint8_t _240_t4;
BB1:
	_240_t3 = 0;
	_240_t1 = _240_n == _240_t3;
	if (!_240_t1) {
		goto BB16;
	} else {
		goto BB2;
	}
BB2:
	_240_t0 = _240_n;
	goto BB7;
BB7:
	_240_$retval = _240_t0;
	return _240_$retval;
BB16:
	_240_t6 = 1;
	_240_t4 = _240_n == _240_t6;
	if (!_240_t4) {
		goto BB15;
	} else {
		goto BB9;
	}
BB9:
	_240_t0 = 1;
	goto BB7;
BB15:
	_240_t9 = _243_add;
	_240_t11 = _240_fib;
	_240_t14 = 1;
	_240_t15 = _240_n - _240_t14;
	_240_t12 = _240_t11(_240_t15);
	_240_t16 = _240_fib;
	_240_t19 = 2;
	_240_t20 = _240_n - _240_t19;
	_240_t17 = _240_t16(_240_t20);
	_240_t0 = _240_t9(_240_t12, _240_t17);
	goto BB7;
}

int64_t _243_add(int64_t _243_x, int64_t _243_y) {
	int64_t _243_$retval;
BB0:
	_243_$retval = _243_x + _243_y;
	return _243_$retval;
}


int main()
{
  printf("%ld",_238_main());
  return 0;
}

#endif
