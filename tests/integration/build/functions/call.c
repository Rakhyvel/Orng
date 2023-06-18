/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687128100
#define ORNG_1687128100

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _12_main();
int64_t _13_add(int64_t x,int64_t y);

/* Function definitions */
int64_t _12_main() {
	int64_t _12_t1;
	int64_t _12_t2;
	int64_t _12_t0;
	int64_t _12_$retval;
BB0:
	_12_t1 = 40;
	_12_t2 = 3;
	_12_t0 = _13_add(_12_t1, _12_t2);
	_12_$retval = _12_t0;
	return _12_$retval;
}

int64_t _13_add(int64_t x,int64_t y) {
	int64_t _13_$retval;
BB0:
	_13_$retval = x + y;
	return _13_$retval;
}


int main()
{
  printf("%ld",_12_main());
  return 0;
}

#endif
