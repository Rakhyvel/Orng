/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686104538
#define ORNG_1686104538

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _261_main();
int64_t _263_fib(int64_t n);
int64_t _266_add(int64_t x,int64_t y);

int64_t _261_main() {
	int64_t (*_261_t0)(int64_t n);
	int64_t _261_t2;
	int64_t _261_t1;
	int64_t _261_t3;
	int64_t _261_$retval;
BB0:
	_261_t0 = _263_fib;
	_261_t2 = 10;
	_261_t1 = _261_t0(_261_t2);
	_261_t3 = 10;
	_261_$retval = _261_t1 - _261_t3;
	return _261_$retval;
}

int64_t _263_fib(int64_t n) {
	int64_t _263_t3;
	uint8_t _263_t1;
	int64_t _263_t0;
	int64_t _263_$retval;
	int64_t (*_263_t9)(int64_t, int64_t);
	int64_t (*_263_t11)(int64_t n);
	int64_t _263_t14;
	int64_t _263_t15;
	int64_t _263_t12;
	int64_t (*_263_t16)(int64_t n);
	int64_t _263_t19;
	int64_t _263_t20;
	int64_t _263_t17;
	int64_t _263_t6;
	uint8_t _263_t4;
BB1:
	_263_t3 = 0;
	_263_t1 = n == _263_t3;
	if (!_263_t1) {
		goto BB16;
	} else {
		goto BB2;
	}
BB2:
	_263_t0 = n;
	goto BB7;
BB7:
	_263_$retval = _263_t0;
	return _263_$retval;
BB16:
	_263_t6 = 1;
	_263_t4 = n == _263_t6;
	if (!_263_t4) {
		goto BB15;
	} else {
		goto BB9;
	}
BB9:
	_263_t0 = 1;
	goto BB7;
BB15:
	_263_t9 = _266_add;
	_263_t11 = _263_fib;
	_263_t14 = 1;
	_263_t15 = n - _263_t14;
	_263_t12 = _263_t11(_263_t15);
	_263_t16 = _263_fib;
	_263_t19 = 2;
	_263_t20 = n - _263_t19;
	_263_t17 = _263_t16(_263_t20);
	_263_t0 = _263_t9(_263_t12, _263_t17);
	goto BB7;
}

int64_t _266_add(int64_t x,int64_t y) {
	int64_t _266_$retval;
BB0:
	_266_$retval = x + y;
	return _266_$retval;
}


int main()
{
  printf("%ld",_261_main());
  return 0;
}

#endif
