/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687052042
#define ORNG_1687052042

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
	int64_t _2;
	int64_t _3;
} struct1;

/* Function forward definitions */
int64_t _2_main();
struct1 _4_get_array(int64_t a,int64_t b);

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t2;
	struct1 _2_t0;
	struct1 _3_x;
	int64_t _2_t3;
	int64_t _2_t4;
	int64_t _2_t5;
	int64_t _2_t6;
	int64_t _2_t7;
	int64_t _2_t8;
	int64_t _2_t9;
	int64_t _2_t10;
	int64_t _2_t11;
	int64_t _2_t12;
	int64_t _2_$retval;
BB0:
	_2_t1 = 15;
	_2_t2 = 16;
	_2_t0 = _4_get_array(_2_t1, _2_t2);
	_3_x = _2_t0;
	_2_t3 = 0;
	_2_t4 = ((int64_t*)(&_3_x))[_2_t3];
	_2_t5 = 1;
	_2_t6 = ((int64_t*)(&_3_x))[_2_t5];
	_2_t7 = _2_t4 + _2_t6;
	_2_t8 = 2;
	_2_t9 = ((int64_t*)(&_3_x))[_2_t8];
	_2_t10 = _2_t7 + _2_t9;
	_2_t11 = 3;
	_2_t12 = ((int64_t*)(&_3_x))[_2_t11];
	_2_$retval = _2_t10 + _2_t12;
	return _2_$retval;
}

struct1 _4_get_array(int64_t a,int64_t b) {
	struct1 _4_$retval;
BB0:
	_4_$retval = (struct1) {a, b, a, b};
	return _4_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
