/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686513839
#define ORNG_1686513839

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();
typedef int64_t(*function1)(int64_t);
typedef int64_t(*function2)(int64_t, int64_t);

/* Function forward definitions */
int64_t _218_main();
int64_t _220_fib(int64_t n);
int64_t _223_add(int64_t x,int64_t y);

/* Function definitions */
int64_t _218_main() {
	function1 _218_t0;
	int64_t _218_t2;
	int64_t _218_t1;
	int64_t _218_t3;
	int64_t _218_$retval;
BB0:
	_218_t0 = _220_fib;
	_218_t2 = 10;
	_218_t1 = _218_t0(_218_t2);
	_218_t3 = 10;
	_218_$retval = _218_t1 - _218_t3;
	return _218_$retval;
}

int64_t _220_fib(int64_t n) {
	int64_t _220_t3;
	uint8_t _220_t1;
	int64_t _220_t0;
	int64_t _220_$retval;
	function2 _220_t9;
	function1 _220_t11;
	int64_t _220_t14;
	int64_t _220_t15;
	int64_t _220_t12;
	function1 _220_t16;
	int64_t _220_t19;
	int64_t _220_t20;
	int64_t _220_t17;
	int64_t _220_t6;
	uint8_t _220_t4;
BB1:
	_220_t3 = 0;
	_220_t1 = n == _220_t3;
	if (!_220_t1) {
		goto BB16;
	} else {
		goto BB2;
	}
BB2:
	_220_t0 = n;
	goto BB7;
BB7:
	_220_$retval = _220_t0;
	return _220_$retval;
BB16:
	_220_t6 = 1;
	_220_t4 = n == _220_t6;
	if (!_220_t4) {
		goto BB15;
	} else {
		goto BB9;
	}
BB9:
	_220_t0 = 1;
	goto BB7;
BB15:
	_220_t9 = _223_add;
	_220_t11 = _220_fib;
	_220_t14 = 1;
	_220_t15 = n - _220_t14;
	_220_t12 = _220_t11(_220_t15);
	_220_t16 = _220_fib;
	_220_t19 = 2;
	_220_t20 = n - _220_t19;
	_220_t17 = _220_t16(_220_t20);
	_220_t0 = _220_t9(_220_t12, _220_t17);
	goto BB7;
}

int64_t _223_add(int64_t x,int64_t y) {
	int64_t _223_$retval;
BB0:
	_223_$retval = x + y;
	return _223_$retval;
}


int main()
{
  printf("%ld",_218_main());
  return 0;
}

#endif
