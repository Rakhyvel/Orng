/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688936017378957051
#define ORNG_1688936017378957051

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _3_x;
	int64_t* _3_y;
	int64_t _2_t2;
	int64_t _2_$retval;
BB0:
	_3_x = 4;
	_3_y = &_3_x;
	_2_t2 = 28;
	**&_3_y = _2_t2;
	_2_$retval = *_3_y;
	return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
