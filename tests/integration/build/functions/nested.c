/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688936431193167826
#define ORNG_1688936431193167826

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();
int64_t _4_fib(int64_t _4_n);
int64_t _7_add(int64_t _7_x,int64_t _7_y);

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t0;
	int64_t _2_t2;
	int64_t _2_$retval;
BB0:
	_2_t1 = 10;
    $lines[$line_idx++] = "    let n = fib(10) - 10";
	_2_t0 = _4_fib(_2_t1);
	_2_t2 = 10;
	_2_$retval = _2_t0 - _2_t2;
	return _2_$retval;
}

int64_t _4_fib(int64_t _4_n) {
	int64_t _4_t2;
	uint8_t _4_t1;
	int64_t _4_t0;
	int64_t _4_$retval;
	int64_t _4_t8;
	int64_t _4_t9;
	int64_t _4_t7;
	int64_t _4_t11;
	int64_t _4_t12;
	int64_t _4_t10;
	int64_t _4_t6;
	int64_t _4_t4;
	uint8_t _4_t3;
BB1:
	_4_t2 = 0;
	_4_t1 = _4_n == _4_t2;
	if (_4_t1) {
		goto BB2;
	} else {
		goto BB16;
	}
BB16:
	_4_t4 = 1;
	_4_t3 = _4_n == _4_t4;
	if (_4_t3) {
		goto BB9;
	} else {
		goto BB15;
	}
BB15:
	_4_t8 = 1;
	_4_t9 = _4_n - _4_t8;
    $lines[$line_idx++] = "        | else   => add(fib(n - 1), fib(n - 2))";
	_4_t7 = _4_fib(_4_t9);
	_4_t11 = 2;
	_4_t12 = _4_n - _4_t11;
    $lines[$line_idx++] = "        | else   => add(fib(n - 1), fib(n - 2))";
	_4_t10 = _4_fib(_4_t12);
    $lines[$line_idx++] = "        | else   => add(fib(n - 1), fib(n - 2))";
	_4_t6 = _7_add(_4_t7, _4_t10);
	_4_t0 = _4_t6;
	goto BB7;
BB7:
	_4_$retval = _4_t0;
	return _4_$retval;
BB9:
	_4_t0 = 1;
	goto BB7;
BB2:
	_4_t0 = _4_n;
	goto BB7;
}

int64_t _7_add(int64_t _7_x,int64_t _7_y) {
	int64_t _7_$retval;
BB0:
	_7_$retval = _7_x + _7_y;
	return _7_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
