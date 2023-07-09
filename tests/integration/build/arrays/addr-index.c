/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688936179663270760
#define ORNG_1688936179663270760

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
	int64_t _2;
	int64_t _3;
} struct0;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t2;
	int64_t _2_t3;
	int64_t _2_t4;
	struct0 _3_x;
	int64_t _2_t5;
	int64_t* _2_t7;
	int64_t _2_t8;
	int64_t _2_t9;
	int64_t _2_t10;
	int64_t _2_$retval;
BB0:
	_2_t1 = 1;
	_2_t2 = 2;
	_2_t3 = 3;
	_2_t4 = 4;
	_3_x = (struct0) {_2_t1, _2_t2, _2_t3, _2_t4};
	_2_t5 = 0;
	_2_t7 = (((int64_t*)(&_3_x))+_2_t5);
	_2_t8 = 63;
	**&_2_t7 = _2_t8;
	_2_t9 = 0;
	_2_t10 = *(((int64_t*)(&_3_x))+_2_t9);
	_2_$retval = _2_t10;
	return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
