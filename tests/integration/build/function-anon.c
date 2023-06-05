/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685928974
#define ORNG_1685928974

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _2_main();
int64_t _4_$anon0(int64_t _4_x);
int64_t _5_apply(int64_t (*_5_f)(int64_t), int64_t _5_x);

int64_t _2_main() {
	int64_t (*_2_t0)(int64_t _4_x);
	int64_t (*_2_t1)(int64_t (*_5_f)(int64_t), int64_t _5_x);
	int64_t _2_t4;
	int64_t _2_$retval;
BB0:
	_2_t0 = _4_$anon0;
	_2_t1 = _5_apply;
	_2_t4 = 43;
	_2_$retval = _2_t1(_2_t0, _2_t4);
	return _2_$retval;
}

int64_t _4_$anon0(int64_t _4_x) {
	int64_t _4_$retval;
BB0:
	_4_$retval = _4_x;
	return _4_$retval;
}

int64_t _5_apply(int64_t (*_5_f)(int64_t), int64_t _5_x) {
	int64_t _5_$retval;
BB0:
	_5_$retval = _5_f(_5_x);
	return _5_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
