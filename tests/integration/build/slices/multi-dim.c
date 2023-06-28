/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687918148179071386
#define ORNG_1687918148179071386

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
int64_t _419_main();

/* Function definitions */
int64_t _419_main() {
	int64_t _419_t1;
	int64_t _419_t2;
	int64_t _419_t3;
	struct1 _420_x;
	int64_t _419_t6;
	int64_t _419_t7;
	int64_t* _419_t8;
	int64_t _419_t9;
	struct3 _419_t5;
	int64_t _419_t11;
	int64_t _419_t12;
	int64_t* _419_t13;
	int64_t _419_t14;
	struct3 _419_t10;
	int64_t _419_t16;
	int64_t _419_t17;
	int64_t* _419_t18;
	int64_t _419_t19;
	struct3 _419_t15;
	struct4 _420_y;
	int64_t _419_t21;
	struct3 _419_t22;
	struct3* _419_t23;
	int64_t _419_t24;
	struct6 _420_z;
	int64_t _419_t25;
	struct3 _419_t26;
	int64_t _419_t27;
	int64_t _419_t28;
	int64_t _419_t29;
	struct3 _419_t30;
	int64_t _419_t31;
	int64_t _419_t32;
	int64_t _419_$retval;
BB0:
	_419_t1 = 1;
	_419_t2 = 2;
	_419_t3 = 3;
	_420_x = (struct1) {_419_t1, _419_t2, _419_t3};
	_419_t6 = 0;
	_419_t7 = *(((int64_t*)(&_420_x))+_419_t6);
	_419_t8 = (((int64_t*)(&_420_x))+_419_t6);
	_419_t9 = 3;
	_419_t5 = (struct3) {_419_t8, _419_t9};
	_419_t11 = 0;
	_419_t12 = *(((int64_t*)(&_420_x))+_419_t11);
	_419_t13 = (((int64_t*)(&_420_x))+_419_t11);
	_419_t14 = 3;
	_419_t10 = (struct3) {_419_t13, _419_t14};
	_419_t16 = 0;
	_419_t17 = *(((int64_t*)(&_420_x))+_419_t16);
	_419_t18 = (((int64_t*)(&_420_x))+_419_t16);
	_419_t19 = 3;
	_419_t15 = (struct3) {_419_t18, _419_t19};
	_420_y = (struct4) {_419_t5, _419_t10, _419_t15};
	_419_t21 = 0;
	_419_t22 = *(((struct3*)(&_420_y))+_419_t21);
	_419_t23 = (((struct3*)(&_420_y))+_419_t21);
	_419_t24 = 3;
	_420_z = (struct6) {_419_t23, _419_t24};
	_419_t25 = 1;
	_419_t26 = *(((struct3*)((&_420_z)->_0))+_419_t25);
	_419_t27 = 1;
	_419_t28 = 82;
	*(((int64_t*)(((((struct3*)((&_420_z)->_0))+_419_t25))->_0))+_419_t27) = _419_t28;
	_419_t29 = 1;
	_419_t30 = *(((struct3*)((&_420_z)->_0))+_419_t29);
	_419_t31 = 1;
	_419_t32 = *(((int64_t*)(((((struct3*)((&_420_z)->_0))+_419_t29))->_0))+_419_t31);
	_419_$retval = _419_t32;
	return _419_$retval;
}


int main()
{
  printf("%ld",_419_main());
  return 0;
}

#endif
