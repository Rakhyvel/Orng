/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686513839
#define ORNG_1686513839

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();
typedef int64_t(*function1)(int64_t, int64_t);

/* Function forward definitions */
int64_t _203_main();
int64_t _204_add(int64_t x,int64_t y);

/* Function definitions */
int64_t _203_main() {
	function1 _203_t0;
	int64_t _203_t2;
	int64_t _203_t3;
	int64_t _203_$retval;
BB0:
	_203_t0 = _204_add;
	_203_t2 = 40;
	_203_t3 = 3;
	_203_$retval = _203_t0(_203_t2, _203_t3);
	return _203_$retval;
}

int64_t _204_add(int64_t x,int64_t y) {
	int64_t _204_$retval;
BB0:
	_204_$retval = x + y;
	return _204_$retval;
}


int main()
{
  printf("%ld",_203_main());
  return 0;
}

#endif
