/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688608981541814864
#define ORNG_1688608981541814864

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();
int64_t _3_id(int64_t _3_x);

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t0;
	int64_t _2_$retval;
BB0:
	_2_t1 = 52;
	_2_t0 = _3_id(_2_t1);
	_2_$retval = _2_t0;
	return _2_$retval;
}

int64_t _3_id(int64_t _3_x) {
	int64_t _3_$retval;
BB0:
	_3_$retval = _3_x;
	return _3_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
