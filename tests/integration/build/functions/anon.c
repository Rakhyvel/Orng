/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686537898
#define ORNG_1686537898

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();
typedef int64_t(*function1)(int64_t);
typedef int64_t(*function2)(function1, int64_t);

/* Function forward definitions */
int64_t _201_main();
int64_t _203_$anon0(int64_t x);
int64_t _204_apply(function1 f,int64_t x);

/* Function definitions */
int64_t _201_main() {
	function1 _201_t0;
	function2 _201_t1;
	int64_t _201_t4;
	int64_t _201_$retval;
BB0:
	_201_t0 = _203_$anon0;
	_201_t1 = _204_apply;
	_201_t4 = 43;
	_201_$retval = _201_t1(_201_t0, _201_t4);
	return _201_$retval;
}

int64_t _203_$anon0(int64_t x) {
	int64_t _203_$retval;
BB0:
	_203_$retval = x;
	return _203_$retval;
}

int64_t _204_apply(function1 f,int64_t x) {
	int64_t _204_$retval;
BB0:
	_204_$retval = f(x);
	return _204_$retval;
}


int main()
{
  printf("%ld",_201_main());
  return 0;
}

#endif
