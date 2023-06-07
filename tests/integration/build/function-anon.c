/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686104538
#define ORNG_1686104538

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _195_main();
int64_t _197_$anon0(int64_t x);
int64_t _198_apply(int64_t (*f)(int64_t),int64_t x);

int64_t _195_main() {
	int64_t (*_195_t0)(int64_t x);
	int64_t (*_195_t1)(int64_t(*)(int64_t), int64_t);
	int64_t _195_t4;
	int64_t _195_$retval;
BB0:
	_195_t0 = _197_$anon0;
	_195_t1 = _198_apply;
	_195_t4 = 43;
	_195_$retval = _195_t1(_195_t0, _195_t4);
	return _195_$retval;
}

int64_t _197_$anon0(int64_t x) {
	int64_t _197_$retval;
BB0:
	_197_$retval = x;
	return _197_$retval;
}

int64_t _198_apply(int64_t (*f)(int64_t),int64_t x) {
	int64_t _198_$retval;
BB0:
	_198_$retval = f(x);
	return _198_$retval;
}


int main()
{
  printf("%ld",_195_main());
  return 0;
}

#endif
