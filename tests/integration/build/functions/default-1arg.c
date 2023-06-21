/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687316164
#define ORNG_1687316164

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _201_main();
int64_t _202_return53(int64_t _202_x);

/* Function definitions */
int64_t _201_main() {
	int64_t _201_t1;
	int64_t _201_t0;
	int64_t _201_$retval;
BB0:
	_201_t1 = 53;
	_201_t0 = _202_return53(_201_t1);
	_201_$retval = _201_t0;
	return _201_$retval;
}

int64_t _202_return53(int64_t _202_x) {
	int64_t _202_$retval;
BB0:
	_202_$retval = _202_x;
	return _202_$retval;
}


int main()
{
  printf("%ld",_201_main());
  return 0;
}

#endif
