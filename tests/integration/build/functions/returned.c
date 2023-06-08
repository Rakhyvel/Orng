/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686109156
#define ORNG_1686109156

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _27_main();
int64_t _29_f();
int64_t _30_addFour(int64_t x);

int64_t _27_main() {
	int64_t (*_27_t0)();
	int64_t (*_27_t1)(int64_t);
	int64_t _27_t3;
	int64_t _27_$retval;
BB0:
	_27_t0 = _29_f;
	_27_t1 = _27_t0();
	_27_t3 = 45;
	_27_$retval = _27_t1(_27_t3);
	return _27_$retval;
}

int64_t _29_f() {
	int64_t (*_29_t0)(int64_t x);
	int64_t (*_29_$retval)(int64_t);
BB0:
	_29_t0 = _30_addFour;
	_29_$retval = _29_t0;
	return _29_$retval;
}

int64_t _30_addFour(int64_t x) {
	int64_t _30_t1;
	int64_t _30_$retval;
BB0:
	_30_t1 = 4;
	_30_$retval = x + _30_t1;
	return _30_$retval;
}


int main()
{
  printf("%ld",_27_main());
  return 0;
}

#endif
