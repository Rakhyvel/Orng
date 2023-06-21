/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687316164
#define ORNG_1687316164

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

/* Function forward definitions */
int64_t _390_main();

/* Function definitions */
int64_t _390_main() {
	int64_t _390_t2;
	int64_t _390_t3;
	int64_t _390_t4;
	struct1 _390_t1;
	int64_t _390_t6;
	int64_t _390_t7;
	int64_t _390_t8;
	struct1 _390_t5;
	int64_t _390_t10;
	int64_t _390_t11;
	int64_t _390_t12;
	struct1 _390_t9;
	struct2 _391_x;
	int64_t _390_t13;
	struct1 _390_t14;
	int64_t _390_t15;
	int64_t _390_t16;
	struct1 _390_t17;
	int64_t _390_t18;
	int64_t _390_t19;
	int64_t _390_t20;
	int64_t _390_t21;
	int64_t _390_t22;
	struct1 _390_t23;
	int64_t _390_t24;
	int64_t _390_t25;
	int64_t _390_$retval;
BB0:
	_390_t2 = 1;
	_390_t3 = 2;
	_390_t4 = 3;
	_390_t1 = (struct1) {_390_t2, _390_t3, _390_t4};
	_390_t6 = 4;
	_390_t7 = 5;
	_390_t8 = 68;
	_390_t5 = (struct1) {_390_t6, _390_t7, _390_t8};
	_390_t10 = 7;
	_390_t11 = 8;
	_390_t12 = 9;
	_390_t9 = (struct1) {_390_t10, _390_t11, _390_t12};
	_391_x = (struct2) {_390_t1, _390_t5, _390_t9};
	_390_t13 = 1;
	_390_t14 = *(((struct1*)(&_391_x))+_390_t13);
	_390_t15 = 2;
	_390_t16 = 1;
	_390_t17 = *(((struct1*)(&_391_x))+_390_t16);
	_390_t18 = 2;
	_390_t19 = *(((int64_t*)((((struct1*)(&_391_x))+_390_t16)))+_390_t18);
	_390_t20 = 1;
	_390_t21 = _390_t19 + _390_t20;
	*(((int64_t*)((((struct1*)(&_391_x))+_390_t13)))+_390_t15) = _390_t21;
	_390_t22 = 1;
	_390_t23 = *(((struct1*)(&_391_x))+_390_t22);
	_390_t24 = 2;
	_390_t25 = *(((int64_t*)((((struct1*)(&_391_x))+_390_t22)))+_390_t24);
	_390_$retval = _390_t25;
	return _390_$retval;
}


int main()
{
  printf("%ld",_390_main());
  return 0;
}

#endif
