/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688935556913081224
#define ORNG_1688935556913081224

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
} struct0;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t2;
	struct0 _3_x;
	struct0* _2_t3;
	int64_t _2_t5;
	struct0* _2_t6;
	int64_t _2_t8;
	int64_t _2_$retval;
BB0:
	_2_t1 = 1;
	_2_t2 = 2;
	_3_x = (struct0) {_2_t1, _2_t2};
	_2_t3 = &_3_x;
	_2_t5 = 76;
	(_2_t3)->_0 = _2_t5;
	_2_t6 = &_3_x;
	_2_t8 = *&((_2_t6)->_0);
	_2_$retval = _2_t8;
	return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
