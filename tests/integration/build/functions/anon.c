/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686278317
#define ORNG_1686278317

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();
typedef int64_t(*function1)(int64_t);
typedef int64_t(*function2)(function1, int64_t);

/* Function forward definitions */
int64_t _197_main();
int64_t _199_$anon0(int64_t x);
int64_t _200_apply(function1 f,int64_t x);

/* Function definitions */
int64_t _197_main() {
	function1 _197_t0;
	function2 _197_t1;
	int64_t _197_t4;
	int64_t _197_$retval;
BB0:
	_197_t0 = _199_$anon0;
	_197_t1 = _200_apply;
	_197_t4 = 43;
	_197_$retval = _197_t1(_197_t0, _197_t4);
	return _197_$retval;
}

int64_t _199_$anon0(int64_t x) {
	int64_t _199_$retval;
BB0:
	_199_$retval = x;
	return _199_$retval;
}

int64_t _200_apply(function1 f,int64_t x) {
	int64_t _200_$retval;
BB0:
	_200_$retval = f(x);
	return _200_$retval;
}


int main()
{
  printf("%ld",_197_main());
  return 0;
}

#endif
