/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686980573
#define ORNG_1686980573

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _201_main();
int64_t _203_$anon0(int64_t x);
int64_t _204_apply(function0 f,int64_t x);

/* Function definitions */
int64_t _201_main() {
	function0 _201_t0;
	int64_t _201_t2;
	int64_t _201_t1;
	int64_t _201_$retval;
BB0:
	_201_t0 = _203_$anon0;
	_201_t2 = 43;
	_201_t1 = _204_apply(_201_t0, _201_t2);
	_201_$retval = _201_t1;
	return _201_$retval;
}

int64_t _203_$anon0(int64_t x) {
	int64_t _203_$retval;
BB0:
	_203_$retval = x;
	return _203_$retval;
}

int64_t _204_apply(function0 f,int64_t x) {
	int64_t _204_t0;
	int64_t _204_$retval;
BB0:
	_204_t0 = f(x);
	_204_$retval = _204_t0;
	return _204_$retval;
}


int main()
{
  printf("%ld",_201_main());
  return 0;
}

#endif
