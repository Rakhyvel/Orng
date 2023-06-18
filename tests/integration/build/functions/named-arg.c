/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687128100
#define ORNG_1687128100

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _51_main();
int64_t _52_div(int64_t x,int64_t y);

/* Function definitions */
int64_t _51_main() {
	int64_t _51_t1;
	int64_t _51_t2;
	int64_t _51_t0;
	int64_t _51_$retval;
BB0:
	_51_t1 = 510;
	_51_t2 = 10;
	_51_t0 = _52_div(_51_t1, _51_t2);
	_51_$retval = _51_t0;
	return _51_$retval;
}

int64_t _52_div(int64_t x,int64_t y) {
	int64_t _52_$retval;
BB0:
	_52_$retval = x / y;
	return _52_$retval;
}


int main()
{
  printf("%ld",_51_main());
  return 0;
}

#endif
