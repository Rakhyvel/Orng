/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687128100
#define ORNG_1687128100

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _31_main();
int64_t _33_fib(int64_t n);
int64_t _36_add(int64_t x,int64_t y);

/* Function definitions */
int64_t _31_main() {
	int64_t _31_t1;
	int64_t _31_t0;
	int64_t _31_t2;
	int64_t _31_$retval;
BB0:
	_31_t1 = 10;
	_31_t0 = _33_fib(_31_t1);
	_31_t2 = 10;
	_31_$retval = _31_t0 - _31_t2;
	return _31_$retval;
}

int64_t _33_fib(int64_t n) {
	int64_t _33_t2;
	uint8_t _33_t1;
	int64_t _33_t0;
	int64_t _33_$retval;
	int64_t _33_t8;
	int64_t _33_t9;
	int64_t _33_t7;
	int64_t _33_t11;
	int64_t _33_t12;
	int64_t _33_t10;
	int64_t _33_t6;
	int64_t _33_t4;
	uint8_t _33_t3;
BB1:
	_33_t2 = 0;
	_33_t1 = n == _33_t2;
	if (!_33_t1) {
		goto BB16;
	} else {
		goto BB2;
	}
BB2:
	_33_t0 = n;
	goto BB7;
BB7:
	_33_$retval = _33_t0;
	return _33_$retval;
BB16:
	_33_t4 = 1;
	_33_t3 = n == _33_t4;
	if (!_33_t3) {
		goto BB15;
	} else {
		goto BB9;
	}
BB9:
	_33_t0 = 1;
	goto BB7;
BB15:
	_33_t8 = 1;
	_33_t9 = n - _33_t8;
	_33_t7 = _33_fib(_33_t9);
	_33_t11 = 2;
	_33_t12 = n - _33_t11;
	_33_t10 = _33_fib(_33_t12);
	_33_t6 = _36_add(_33_t7, _33_t10);
	_33_t0 = _33_t6;
	goto BB7;
}

int64_t _36_add(int64_t x,int64_t y) {
	int64_t _36_$retval;
BB0:
	_36_$retval = x + y;
	return _36_$retval;
}


int main()
{
  printf("%ld",_31_main());
  return 0;
}

#endif
