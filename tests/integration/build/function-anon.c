/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685933745
#define ORNG_1685933745

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _172_main();
int64_t _174_$anon0(int64_t _174_x);
int64_t _175_apply(int64_t (*_175_f)(int64_t), int64_t _175_x);

int64_t _172_main() {
	int64_t (*_172_t0)(int64_t _174_x);
	int64_t (*_172_t1)(int64_t (*_175_f)(int64_t), int64_t _175_x);
	int64_t _172_t4;
	int64_t _172_$retval;
BB0:
	_172_t0 = _174_$anon0;
	_172_t1 = _175_apply;
	_172_t4 = 43;
	_172_$retval = _172_t1(_172_t0, _172_t4);
	return _172_$retval;
}

int64_t _174_$anon0(int64_t _174_x) {
	int64_t _174_$retval;
BB0:
	_174_$retval = _174_x;
	return _174_$retval;
}

int64_t _175_apply(int64_t (*_175_f)(int64_t), int64_t _175_x) {
	int64_t _175_$retval;
BB0:
	_175_$retval = _175_f(_175_x);
	return _175_$retval;
}


int main()
{
  printf("%ld",_172_main());
  return 0;
}

#endif
