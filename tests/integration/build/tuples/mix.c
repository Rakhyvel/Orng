/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688935543933478594
#define ORNG_1688935543933478594

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
typedef struct {
	int64_t _0;
	int64_t* _1;
} struct1;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();
struct0 _4_get_array(int64_t _4_a,int64_t _4_b);

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t2;
	struct0 _2_t0;
	int64_t _3_z;
	int64_t* _2_t5;
	struct1 _3_y;
	int64_t _2_$retval;
BB0:
	_2_t1 = 15;
	_2_t2 = 16;
	_2_t0 = _4_get_array(_2_t1, _2_t2);
	_3_z = 64;
	_2_t5 = &_3_z;
	_3_y = (struct1) {_3_z, _2_t5};
	_2_$retval = (&_3_y)->_0;
	return _2_$retval;
}

struct0 _4_get_array(int64_t _4_a,int64_t _4_b) {
	struct0 _4_$retval;
BB0:
	_4_$retval = (struct0) {_4_a, _4_b, _4_a, _4_b};
	return _4_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
