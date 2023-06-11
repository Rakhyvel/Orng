/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686463458
#define ORNG_1686463458

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();
typedef int64_t(*function1)(int64_t);
typedef int64_t(*function2)(function1, int64_t);

/* Function forward definitions */
int64_t _2_main();
int64_t _4_$anon0(int64_t x);
int64_t _5_apply(function1 f,int64_t x);

/* Function definitions */
int64_t _2_main() {
	function1 _2_t0;
	function2 _2_t1;
	int64_t _2_t4;
	int64_t _2_$retval;
BB0:
	_2_t0 = _4_$anon0;
	_2_t1 = _5_apply;
	_2_t4 = 43;
	_2_$retval = _2_t1(_2_t0, _2_t4);
	return _2_$retval;
}

int64_t _4_$anon0(int64_t x) {
	int64_t _4_$retval;
BB0:
	_4_$retval = x;
	return _4_$retval;
}

int64_t _5_apply(function1 f,int64_t x) {
	int64_t _5_$retval;
BB0:
	_5_$retval = f(x);
	return _5_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
