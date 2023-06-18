/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687128100
#define ORNG_1687128100

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _2_main();
int64_t _3_return53(int64_t x);

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t0;
	int64_t _2_$retval;
BB0:
	_2_t1 = 53;
	_2_t0 = _3_return53(_2_t1);
	_2_$retval = _2_t0;
	return _2_$retval;
}

int64_t _3_return53(int64_t x) {
	int64_t _3_$retval;
BB0:
	_3_$retval = x;
	return _3_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
