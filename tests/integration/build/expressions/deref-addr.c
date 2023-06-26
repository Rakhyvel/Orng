/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687738073
#define ORNG_1687738073

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _300_main();

/* Function definitions */
int64_t _300_main() {
	int64_t _301_x;
	int64_t* _300_t1;
	int64_t _300_t2;
	int64_t* _300_t3;
	int64_t _300_t4;
	int64_t _300_$retval;
BB0:
	_301_x = 5;
	_300_t1 = &_301_x;
	_300_t2 = 74;
	**&_300_t1 = _300_t2;
	_300_t3 = &_301_x;
	_300_t4 = *_300_t3;
	_300_$retval = _300_t4;
	return _300_$retval;
}


int main()
{
  printf("%ld",_300_main());
  return 0;
}

#endif
