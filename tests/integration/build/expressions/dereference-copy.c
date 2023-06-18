/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687131003
#define ORNG_1687131003

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _300_main();

/* Function definitions */
int64_t _300_main() {
	int64_t _301_x;
	int64_t* _301_y;
	int64_t _300_t2;
	int64_t _300_$retval;
BB0:
	_301_x = 4;
	_301_y = &_301_x;
	_300_t2 = 28;
	*&_301_x = _300_t2;
	_300_$retval = *_301_y;
	return _300_$retval;
}


int main()
{
  printf("%ld",_300_main());
  return 0;
}

#endif
