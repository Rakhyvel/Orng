/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688146807093997542
#define ORNG_1688146807093997542

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
	int64_t* _0;
	int64_t _1;
} struct3;
typedef struct {
	struct3 _0;
	struct3 _1;
	struct3 _2;
} struct4;
typedef struct {
	struct3* _0;
	int64_t _1;
} struct6;

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t2;
	int64_t _2_t3;
	struct1 _3_x;
	int64_t _2_t6;
	int64_t _2_t7;
	int64_t* _2_t8;
	int64_t _2_t9;
	struct3 _2_t5;
	int64_t _2_t11;
	int64_t _2_t12;
	int64_t* _2_t13;
	int64_t _2_t14;
	struct3 _2_t10;
	int64_t _2_t16;
	int64_t _2_t17;
	int64_t* _2_t18;
	int64_t _2_t19;
	struct3 _2_t15;
	struct4 _3_y;
	int64_t _2_t21;
	struct3 _2_t22;
	struct3* _2_t23;
	int64_t _2_t24;
	struct6 _3_z;
	int64_t _2_t25;
	struct3 _2_t26;
	int64_t _2_t27;
	int64_t _2_t28;
	int64_t _2_t29;
	struct3 _2_t30;
	int64_t _2_t31;
	int64_t _2_t32;
	int64_t _2_$retval;
BB0:
	_2_t1 = 1;
	_2_t2 = 2;
	_2_t3 = 3;
	_3_x = (struct1) {_2_t1, _2_t2, _2_t3};
	_2_t6 = 0;
	_2_t7 = *(((int64_t*)(&_3_x))+_2_t6);
	_2_t8 = (((int64_t*)(&_3_x))+_2_t6);
	_2_t9 = 3;
	_2_t5 = (struct3) {_2_t8, _2_t9};
	_2_t11 = 0;
	_2_t12 = *(((int64_t*)(&_3_x))+_2_t11);
	_2_t13 = (((int64_t*)(&_3_x))+_2_t11);
	_2_t14 = 3;
	_2_t10 = (struct3) {_2_t13, _2_t14};
	_2_t16 = 0;
	_2_t17 = *(((int64_t*)(&_3_x))+_2_t16);
	_2_t18 = (((int64_t*)(&_3_x))+_2_t16);
	_2_t19 = 3;
	_2_t15 = (struct3) {_2_t18, _2_t19};
	_3_y = (struct4) {_2_t5, _2_t10, _2_t15};
	_2_t21 = 0;
	_2_t22 = *(((struct3*)(&_3_y))+_2_t21);
	_2_t23 = (((struct3*)(&_3_y))+_2_t21);
	_2_t24 = 3;
	_3_z = (struct6) {_2_t23, _2_t24};
	_2_t25 = 1;
	_2_t26 = *(((struct3*)((&_3_z)->_0))+_2_t25);
	_2_t27 = 1;
	_2_t28 = 82;
	*(((int64_t*)(((((struct3*)((&_3_z)->_0))+_2_t25))->_0))+_2_t27) = _2_t28;
	_2_t29 = 1;
	_2_t30 = *(((struct3*)((&_3_z)->_0))+_2_t29);
	_2_t31 = 1;
	_2_t32 = *(((int64_t*)(((((struct3*)((&_3_z)->_0))+_2_t29))->_0))+_2_t31);
	_2_$retval = _2_t32;
	return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
