/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687918146
#define ORNG_1687918146

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
int64_t _10_main();

/* Function definitions */
int64_t _10_main() {
	int64_t _10_t1;
	int64_t _10_t2;
	int64_t _10_t3;
	struct1 _11_x;
	int64_t _10_t6;
	int64_t _10_t7;
	int64_t* _10_t8;
	int64_t _10_t9;
	struct3 _10_t5;
	int64_t _10_t11;
	int64_t _10_t12;
	int64_t* _10_t13;
	int64_t _10_t14;
	struct3 _10_t10;
	int64_t _10_t16;
	int64_t _10_t17;
	int64_t* _10_t18;
	int64_t _10_t19;
	struct3 _10_t15;
	struct4 _11_y;
	int64_t _10_t21;
	struct3 _10_t22;
	struct3* _10_t23;
	int64_t _10_t24;
	struct6 _11_z;
	int64_t _10_t25;
	struct3 _10_t26;
	int64_t _10_t27;
	int64_t _10_t28;
	int64_t _10_t29;
	struct3 _10_t30;
	int64_t _10_t31;
	int64_t _10_t32;
	int64_t _10_$retval;
BB0:
	_10_t1 = 1;
	_10_t2 = 2;
	_10_t3 = 3;
	_11_x = (struct1) {_10_t1, _10_t2, _10_t3};
	_10_t6 = 0;
	_10_t7 = *(((int64_t*)(&_11_x))+_10_t6);
	_10_t8 = (((int64_t*)(&_11_x))+_10_t6);
	_10_t9 = 3;
	_10_t5 = (struct3) {_10_t8, _10_t9};
	_10_t11 = 0;
	_10_t12 = *(((int64_t*)(&_11_x))+_10_t11);
	_10_t13 = (((int64_t*)(&_11_x))+_10_t11);
	_10_t14 = 3;
	_10_t10 = (struct3) {_10_t13, _10_t14};
	_10_t16 = 0;
	_10_t17 = *(((int64_t*)(&_11_x))+_10_t16);
	_10_t18 = (((int64_t*)(&_11_x))+_10_t16);
	_10_t19 = 3;
	_10_t15 = (struct3) {_10_t18, _10_t19};
	_11_y = (struct4) {_10_t5, _10_t10, _10_t15};
	_10_t21 = 0;
	_10_t22 = *(((struct3*)(&_11_y))+_10_t21);
	_10_t23 = (((struct3*)(&_11_y))+_10_t21);
	_10_t24 = 3;
	_11_z = (struct6) {_10_t23, _10_t24};
	_10_t25 = 1;
	_10_t26 = *(((struct3*)((&_11_z)->_0))+_10_t25);
	_10_t27 = 1;
	_10_t28 = 82;
	*(((int64_t*)(((((struct3*)((&_11_z)->_0))+_10_t25))->_0))+_10_t27) = _10_t28;
	_10_t29 = 1;
	_10_t30 = *(((struct3*)((&_11_z)->_0))+_10_t29);
	_10_t31 = 1;
	_10_t32 = *(((int64_t*)(((((struct3*)((&_11_z)->_0))+_10_t29))->_0))+_10_t31);
	_10_$retval = _10_t32;
	return _10_$retval;
}


int main()
{
  printf("%ld",_10_main());
  return 0;
}

#endif
