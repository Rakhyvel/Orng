/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686278317
#define ORNG_1686278317

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();
typedef int64_t(*function1)(int64_t);
typedef int64_t(*function2)(int64_t, int64_t);

/* Function forward definitions */
int64_t _214_main();
int64_t _216_fib(int64_t n);
int64_t _219_add(int64_t x,int64_t y);

/* Function definitions */
int64_t _214_main() {
	function1 _214_t0;
	int64_t _214_t2;
	int64_t _214_t1;
	int64_t _214_t3;
	int64_t _214_$retval;
BB0:
	_214_t0 = _216_fib;
	_214_t2 = 10;
	_214_t1 = _214_t0(_214_t2);
	_214_t3 = 10;
	_214_$retval = _214_t1 - _214_t3;
	return _214_$retval;
}

int64_t _216_fib(int64_t n) {
	int64_t _216_t3;
	uint8_t _216_t1;
	int64_t _216_t0;
	int64_t _216_$retval;
	function2 _216_t9;
	function1 _216_t11;
	int64_t _216_t14;
	int64_t _216_t15;
	int64_t _216_t12;
	function1 _216_t16;
	int64_t _216_t19;
	int64_t _216_t20;
	int64_t _216_t17;
	int64_t _216_t6;
	uint8_t _216_t4;
BB1:
	_216_t3 = 0;
	_216_t1 = n == _216_t3;
	if (!_216_t1) {
		goto BB16;
	} else {
		goto BB2;
	}
BB2:
	_216_t0 = n;
	goto BB7;
BB7:
	_216_$retval = _216_t0;
	return _216_$retval;
BB16:
	_216_t6 = 1;
	_216_t4 = n == _216_t6;
	if (!_216_t4) {
		goto BB15;
	} else {
		goto BB9;
	}
BB9:
	_216_t0 = 1;
	goto BB7;
BB15:
	_216_t9 = _219_add;
	_216_t11 = _216_fib;
	_216_t14 = 1;
	_216_t15 = n - _216_t14;
	_216_t12 = _216_t11(_216_t15);
	_216_t16 = _216_fib;
	_216_t19 = 2;
	_216_t20 = n - _216_t19;
	_216_t17 = _216_t16(_216_t20);
	_216_t0 = _216_t9(_216_t12, _216_t17);
	goto BB7;
}

int64_t _219_add(int64_t x,int64_t y) {
	int64_t _219_$retval;
BB0:
	_219_$retval = x + y;
	return _219_$retval;
}


int main()
{
  printf("%ld",_214_main());
  return 0;
}

#endif
