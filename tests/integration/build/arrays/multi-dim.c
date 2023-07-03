/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687131192578370067
#define ORNG_1687131192578370067

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
	int64_t _2;
} struct1;
typedef struct {
	struct1 _0;
	struct1 _1;
	struct1 _2;
} struct2;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t2;
	int64_t _2_t3;
	int64_t _2_t4;
	struct1 _2_t1;
	int64_t _2_t6;
	int64_t _2_t7;
	int64_t _2_t8;
	struct1 _2_t5;
	int64_t _2_t10;
	int64_t _2_t11;
	int64_t _2_t12;
	struct1 _2_t9;
	struct2 _3_x;
	int64_t _2_t13;
	struct1 _2_t14;
	int64_t _2_t15;
	int64_t _2_t16;
	struct1 _2_t17;
	int64_t _2_t18;
	int64_t _2_t19;
	int64_t _2_t20;
	int64_t _2_t21;
	int64_t _2_t22;
	struct1 _2_t23;
	int64_t _2_t24;
	int64_t _2_t25;
	int64_t _2_$retval;
BB0:
	_2_t2 = 1;
	_2_t3 = 2;
	_2_t4 = 3;
	_2_t1 = (struct1) {_2_t2, _2_t3, _2_t4};
	_2_t6 = 4;
	_2_t7 = 5;
	_2_t8 = 68;
	_2_t5 = (struct1) {_2_t6, _2_t7, _2_t8};
	_2_t10 = 7;
	_2_t11 = 8;
	_2_t12 = 9;
	_2_t9 = (struct1) {_2_t10, _2_t11, _2_t12};
	_3_x = (struct2) {_2_t1, _2_t5, _2_t9};
	_2_t13 = 1;
	_2_t14 = *(((struct1*)(&_3_x))+_2_t13);
	_2_t15 = 2;
	_2_t16 = 1;
	_2_t17 = *(((struct1*)(&_3_x))+_2_t16);
	_2_t18 = 2;
	_2_t19 = *(((int64_t*)((((struct1*)(&_3_x))+_2_t16)))+_2_t18);
	_2_t20 = 1;
	_2_t21 = _2_t19 + _2_t20;
	*(((int64_t*)((((struct1*)(&_3_x))+_2_t13)))+_2_t15) = _2_t21;
	_2_t22 = 1;
	_2_t23 = *(((struct1*)(&_3_x))+_2_t22);
	_2_t24 = 2;
	_2_t25 = *(((int64_t*)((((struct1*)(&_3_x))+_2_t22)))+_2_t24);
	_2_$retval = _2_t25;
	return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
