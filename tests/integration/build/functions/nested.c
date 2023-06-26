/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687738073
#define ORNG_1687738073

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _230_main();
int64_t _232_fib(int64_t _232_n);
int64_t _235_add(int64_t _235_x,int64_t _235_y);

/* Function definitions */
int64_t _230_main() {
	int64_t _230_t1;
	int64_t _230_t0;
	int64_t _230_t2;
	int64_t _230_$retval;
BB0:
	_230_t1 = 10;
	_230_t0 = _232_fib(_230_t1);
	_230_t2 = 10;
	_230_$retval = _230_t0 - _230_t2;
	return _230_$retval;
}

int64_t _232_fib(int64_t _232_n) {
	int64_t _232_t2;
	uint8_t _232_t1;
	int64_t _232_t0;
	int64_t _232_$retval;
	int64_t _232_t8;
	int64_t _232_t9;
	int64_t _232_t7;
	int64_t _232_t11;
	int64_t _232_t12;
	int64_t _232_t10;
	int64_t _232_t6;
	int64_t _232_t4;
	uint8_t _232_t3;
BB1:
	_232_t2 = 0;
	_232_t1 = _232_n == _232_t2;
	if (!_232_t1) {
		goto BB16;
	} else {
		goto BB2;
	}
BB2:
	_232_t0 = _232_n;
	goto BB7;
BB7:
	_232_$retval = _232_t0;
	return _232_$retval;
BB16:
	_232_t4 = 1;
	_232_t3 = _232_n == _232_t4;
	if (!_232_t3) {
		goto BB15;
	} else {
		goto BB9;
	}
BB9:
	_232_t0 = 1;
	goto BB7;
BB15:
	_232_t8 = 1;
	_232_t9 = _232_n - _232_t8;
	_232_t7 = _232_fib(_232_t9);
	_232_t11 = 2;
	_232_t12 = _232_n - _232_t11;
	_232_t10 = _232_fib(_232_t12);
	_232_t6 = _235_add(_232_t7, _232_t10);
	_232_t0 = _232_t6;
	goto BB7;
}

int64_t _235_add(int64_t _235_x,int64_t _235_y) {
	int64_t _235_$retval;
BB0:
	_235_$retval = _235_x + _235_y;
	return _235_$retval;
}


int main()
{
  printf("%ld",_230_main());
  return 0;
}

#endif
