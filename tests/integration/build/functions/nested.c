/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686463458
#define ORNG_1686463458

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();
typedef int64_t(*function1)(int64_t);
typedef int64_t(*function2)(int64_t, int64_t);

/* Function forward definitions */
int64_t _23_main();
int64_t _25_fib(int64_t n);
int64_t _28_add(int64_t x,int64_t y);

/* Function definitions */
int64_t _23_main() {
	function1 _23_t0;
	int64_t _23_t2;
	int64_t _23_t1;
	int64_t _23_t3;
	int64_t _23_$retval;
BB0:
	_23_t0 = _25_fib;
	_23_t2 = 10;
	_23_t1 = _23_t0(_23_t2);
	_23_t3 = 10;
	_23_$retval = _23_t1 - _23_t3;
	return _23_$retval;
}

int64_t _25_fib(int64_t n) {
	int64_t _25_t3;
	uint8_t _25_t1;
	int64_t _25_t0;
	int64_t _25_$retval;
	function2 _25_t9;
	function1 _25_t11;
	int64_t _25_t14;
	int64_t _25_t15;
	int64_t _25_t12;
	function1 _25_t16;
	int64_t _25_t19;
	int64_t _25_t20;
	int64_t _25_t17;
	int64_t _25_t6;
	uint8_t _25_t4;
BB1:
	_25_t3 = 0;
	_25_t1 = n == _25_t3;
	if (!_25_t1) {
		goto BB16;
	} else {
		goto BB2;
	}
BB2:
	_25_t0 = n;
	goto BB7;
BB7:
	_25_$retval = _25_t0;
	return _25_$retval;
BB16:
	_25_t6 = 1;
	_25_t4 = n == _25_t6;
	if (!_25_t4) {
		goto BB15;
	} else {
		goto BB9;
	}
BB9:
	_25_t0 = 1;
	goto BB7;
BB15:
	_25_t9 = _28_add;
	_25_t11 = _25_fib;
	_25_t14 = 1;
	_25_t15 = n - _25_t14;
	_25_t12 = _25_t11(_25_t15);
	_25_t16 = _25_fib;
	_25_t19 = 2;
	_25_t20 = n - _25_t19;
	_25_t17 = _25_t16(_25_t20);
	_25_t0 = _25_t9(_25_t12, _25_t17);
	goto BB7;
}

int64_t _28_add(int64_t x,int64_t y) {
	int64_t _28_$retval;
BB0:
	_28_$retval = x + y;
	return _28_$retval;
}


int main()
{
  printf("%ld",_23_main());
  return 0;
}

#endif
