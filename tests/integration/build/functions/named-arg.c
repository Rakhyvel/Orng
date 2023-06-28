/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686514343344522738
#define ORNG_1686514343344522738

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _250_main();
int64_t _251_div(int64_t _251_x,int64_t _251_y);

/* Function definitions */
int64_t _250_main() {
	int64_t _250_t1;
	int64_t _250_t2;
	int64_t _250_t0;
	int64_t _250_$retval;
BB0:
	_250_t1 = 510;
	_250_t2 = 10;
	_250_t0 = _251_div(_250_t1, _250_t2);
	_250_$retval = _250_t0;
	return _250_$retval;
}

int64_t _251_div(int64_t _251_x,int64_t _251_y) {
	int64_t _251_$retval;
BB0:
	_251_$retval = _251_x / _251_y;
	return _251_$retval;
}


int main()
{
  printf("%ld",_250_main());
  return 0;
}

#endif
