/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688946510061702193
#define ORNG_1688946510061702193

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
	int64_t _2;
} struct0;
typedef struct {
	int64_t* _0;
	int64_t _1;
} struct1;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();
int64_t _4_sum_up(struct1 _4_xs);

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t2;
	int64_t _2_t3;
	struct0 _3_x;
	int64_t _2_t5;
	int64_t* _2_t7;
	int64_t _2_t8;
	struct1 _3_y;
	int64_t _2_t9;
	int64_t _2_t10;
	int64_t _2_t11;
	int64_t* _2_t12;
	int64_t* _2_t13;
	struct1 _3_z;
	int64_t _2_t15;
	int64_t _2_$retval;
BB0:
	_2_t1 = 100;
	_2_t2 = 10;
	_2_t3 = 1;
	_3_x = (struct0) {_2_t1, _2_t2, _2_t3};
	_2_t5 = 0;
	_2_t7 = (((int64_t*)(&_3_x))+_2_t5);
	_2_t8 = 3;
	_3_y = (struct1) {_2_t7, _2_t8};
	_2_t9 = 0;
	_2_t10 = (&_3_y)->_1;
	_2_t11 = _2_t10 - _2_t9;
	_2_t12 = (&_3_y)->_0;
	_2_t13 = _2_t12 + _2_t9;
	_3_z = (struct1) {_2_t13, _2_t11};
	_2_t15 = _4_sum_up(_3_z);
	_2_$retval = _2_t15;
	return _2_$retval;
}

int64_t _4_sum_up(struct1 _4_xs) {
	int64_t _5_sum;
	int64_t _6_i;
	int64_t _4_t4;
	uint8_t _4_t3;
	int64_t _4_t5;
	int64_t _4_t7;
	int64_t _4_$retval;
BB0:
	_5_sum = 0;
	_6_i = 0;
	goto BB1;
BB1:
	_4_t4 = (&_4_xs)->_1;
	_4_t3 = _6_i < _4_t4;
	if (_4_t3) {
		goto BB2;
	} else {
		goto BB10;
	}
BB10:
	_4_$retval = _5_sum;
	return _4_$retval;
BB2:
	_4_t5 = *(((int64_t*)((&_4_xs)->_0))+_6_i);
	_5_sum = _5_sum + _4_t5;
	_4_t7 = 1;
	_6_i = _6_i + _4_t7;
	goto BB1;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
