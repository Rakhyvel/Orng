/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686712671
#define ORNG_1686712671

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();
typedef int64_t(*function3)(int64_t);
typedef struct {
	int64_t _0;
	int64_t _1;
} struct6;
typedef int64_t(*function5)(int64_t, int64_t);

/* Function forward definitions */
int64_t _226_main();
int64_t _228_fib(int64_t n);
int64_t _231_add(int64_t x,int64_t y);

/* Function definitions */
int64_t _226_main() {
	int64_t _226_t1;
	int64_t _226_t0;
	int64_t _226_t2;
	int64_t _226_$retval;
BB0:
	_226_t1 = 10;
	_226_t0 = _228_fib(_226_t1);
	_226_t2 = 10;
	_226_$retval = _226_t0 - _226_t2;
	return _226_$retval;
}

int64_t _228_fib(int64_t n) {
	int64_t _228_t2;
	uint8_t _228_t1;
	int64_t _228_t0;
	int64_t _228_$retval;
	int64_t _228_t8;
	int64_t _228_t9;
	int64_t _228_t7;
	int64_t _228_t11;
	int64_t _228_t12;
	int64_t _228_t10;
	int64_t _228_t6;
	int64_t _228_t4;
	uint8_t _228_t3;
BB1:
	_228_t2 = 0;
	_228_t1 = n == _228_t2;
	if (!_228_t1) {
		goto BB16;
	} else {
		goto BB2;
	}
BB2:
	_228_t0 = n;
	goto BB7;
BB7:
	_228_$retval = _228_t0;
	return _228_$retval;
BB16:
	_228_t4 = 1;
	_228_t3 = n == _228_t4;
	if (!_228_t3) {
		goto BB15;
	} else {
		goto BB9;
	}
BB9:
	_228_t0 = 1;
	goto BB7;
BB15:
	_228_t8 = 1;
	_228_t9 = n - _228_t8;
	_228_t7 = _228_fib(_228_t9);
	_228_t11 = 2;
	_228_t12 = n - _228_t11;
	_228_t10 = _228_fib(_228_t12);
	_228_t6 = _231_add(_228_t7, _228_t10);
	_228_t0 = _228_t6;
	goto BB7;
}

int64_t _231_add(int64_t x,int64_t y) {
	int64_t _231_$retval;
BB0:
	_231_$retval = x + y;
	return _231_$retval;
}


int main()
{
  printf("%ld",_226_main());
  return 0;
}

#endif
