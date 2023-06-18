/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687128100
#define ORNG_1687128100

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _6_main();
int64_t _8_$anon0(int64_t x);
int64_t _9_apply(function0 f,int64_t x);

/* Function definitions */
int64_t _6_main() {
	function0 _6_t0;
	int64_t _6_t2;
	int64_t _6_t1;
	int64_t _6_$retval;
BB0:
	_6_t0 = _8_$anon0;
	_6_t2 = 43;
	_6_t1 = _9_apply(_6_t0, _6_t2);
	_6_$retval = _6_t1;
	return _6_$retval;
}

int64_t _8_$anon0(int64_t x) {
	int64_t _8_$retval;
BB0:
	_8_$retval = x;
	return _8_$retval;
}

int64_t _9_apply(function0 f,int64_t x) {
	int64_t _9_t0;
	int64_t _9_$retval;
BB0:
	_9_t0 = f(x);
	_9_$retval = _9_t0;
	return _9_$retval;
}


int main()
{
  printf("%ld",_6_main());
  return 0;
}

#endif
