/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686463458
#define ORNG_1686463458

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();
typedef int64_t(*function1)(int64_t);

/* Function forward definitions */
int64_t _16_main();
int64_t _17_sumDown(int64_t x);

/* Function definitions */
int64_t _16_main() {
	function1 _16_t0;
	int64_t _16_t2;
	int64_t _16_t1;
	int64_t _16_t3;
	int64_t _16_$retval;
BB0:
	_16_t0 = _17_sumDown;
	_16_t2 = 8;
	_16_t1 = _16_t0(_16_t2);
	_16_t3 = 2;
	_16_$retval = _16_t1 + _16_t3;
	return _16_$retval;
}

int64_t _17_sumDown(int64_t x) {
	int64_t _19_i;
	int64_t _17_t4;
	uint8_t _17_t2;
	int64_t _17_t9;
	int64_t _17_$retval;
BB0:
	_19_i = x;
	goto BB1;
BB1:
	_17_t4 = 0;
	_17_t2 = _19_i >= _17_t4;
	if (!_17_t2) {
		goto BB10;
	} else {
		goto BB2;
	}
BB2:
	x = x + _19_i;
	_17_t9 = 1;
	_19_i = _19_i - _17_t9;
	goto BB1;
BB10:
	_17_$retval = x;
	return _17_$retval;
}


int main()
{
  printf("%ld",_16_main());
  return 0;
}

#endif
