/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686109156
#define ORNG_1686109156

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _19_main();
int64_t _21_fib(int64_t n);
int64_t _24_add(int64_t x,int64_t y);

int64_t _19_main() {
	int64_t (*_19_t0)(int64_t n);
	int64_t _19_t2;
	int64_t _19_t1;
	int64_t _19_t3;
	int64_t _19_$retval;
BB0:
	_19_t0 = _21_fib;
	_19_t2 = 10;
	_19_t1 = _19_t0(_19_t2);
	_19_t3 = 10;
	_19_$retval = _19_t1 - _19_t3;
	return _19_$retval;
}

int64_t _21_fib(int64_t n) {
	int64_t _21_t3;
	uint8_t _21_t1;
	int64_t _21_t0;
	int64_t _21_$retval;
	int64_t (*_21_t9)(int64_t, int64_t);
	int64_t (*_21_t11)(int64_t n);
	int64_t _21_t14;
	int64_t _21_t15;
	int64_t _21_t12;
	int64_t (*_21_t16)(int64_t n);
	int64_t _21_t19;
	int64_t _21_t20;
	int64_t _21_t17;
	int64_t _21_t6;
	uint8_t _21_t4;
BB1:
	_21_t3 = 0;
	_21_t1 = n == _21_t3;
	if (!_21_t1) {
		goto BB16;
	} else {
		goto BB2;
	}
BB2:
	_21_t0 = n;
	goto BB7;
BB7:
	_21_$retval = _21_t0;
	return _21_$retval;
BB16:
	_21_t6 = 1;
	_21_t4 = n == _21_t6;
	if (!_21_t4) {
		goto BB15;
	} else {
		goto BB9;
	}
BB9:
	_21_t0 = 1;
	goto BB7;
BB15:
	_21_t9 = _24_add;
	_21_t11 = _21_fib;
	_21_t14 = 1;
	_21_t15 = n - _21_t14;
	_21_t12 = _21_t11(_21_t15);
	_21_t16 = _21_fib;
	_21_t19 = 2;
	_21_t20 = n - _21_t19;
	_21_t17 = _21_t16(_21_t20);
	_21_t0 = _21_t9(_21_t12, _21_t17);
	goto BB7;
}

int64_t _24_add(int64_t x,int64_t y) {
	int64_t _24_$retval;
BB0:
	_24_$retval = x + y;
	return _24_$retval;
}


int main()
{
  printf("%ld",_19_main());
  return 0;
}

#endif
