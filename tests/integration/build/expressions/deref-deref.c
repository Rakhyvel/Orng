/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687312430100733968
#define ORNG_1687312430100733968

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
	int64_t* _2_t1;
	int64_t* _3_y;
	int64_t** _2_t2;
	int64_t* _2_t3;
	int64_t _2_t4;
	int64_t* _2_t5;
	int64_t _2_t6;
	int64_t _2_$retval;
BB0:
	_3_x = 75;
	_2_t1 = &_3_x;
	_3_y = _2_t1;
	_2_t2 = &_3_y;
	_2_t4 = 75;
	**_2_t2 = _2_t4;
	_2_t5 = *_2_t2;
	_2_t6 = *_2_t5;
	_2_$retval = _2_t6;
	return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
