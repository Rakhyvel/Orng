/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687314590
#define ORNG_1687314590

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
int64_t _26_main();

/* Function definitions */
int64_t _26_main() {
	int64_t _26_t2;
	int64_t _26_t3;
	int64_t _26_t4;
	struct1 _26_t1;
	int64_t _26_t6;
	int64_t _26_t7;
	int64_t _26_t8;
	struct1 _26_t5;
	int64_t _26_t10;
	int64_t _26_t11;
	int64_t _26_t12;
	struct1 _26_t9;
	struct2 _27_x;
	int64_t _26_t13;
	struct1 _26_t14;
	int64_t _26_t15;
	int64_t _26_t16;
	struct1 _26_t17;
	int64_t _26_t18;
	int64_t _26_t19;
	int64_t _26_t20;
	int64_t _26_t21;
	int64_t _26_t22;
	struct1 _26_t23;
	int64_t _26_t24;
	int64_t _26_t25;
	int64_t _26_$retval;
BB0:
	_26_t2 = 1;
	_26_t3 = 2;
	_26_t4 = 3;
	_26_t1 = (struct1) {_26_t2, _26_t3, _26_t4};
	_26_t6 = 4;
	_26_t7 = 5;
	_26_t8 = 68;
	_26_t5 = (struct1) {_26_t6, _26_t7, _26_t8};
	_26_t10 = 7;
	_26_t11 = 8;
	_26_t12 = 9;
	_26_t9 = (struct1) {_26_t10, _26_t11, _26_t12};
	_27_x = (struct2) {_26_t1, _26_t5, _26_t9};
	_26_t13 = 1;
	_26_t14 = *(((struct1*)(&_27_x))+_26_t13);
	_26_t15 = 2;
	_26_t16 = 1;
	_26_t17 = *(((struct1*)(&_27_x))+_26_t16);
	_26_t18 = 2;
	_26_t19 = *(((int64_t*)((((struct1*)(&_27_x))+_26_t16)))+_26_t18);
	_26_t20 = 1;
	_26_t21 = _26_t19 + _26_t20;
	*(((int64_t*)((((struct1*)(&_27_x))+_26_t13)))+_26_t15) = _26_t21;
	_26_t22 = 1;
	_26_t23 = *(((struct1*)(&_27_x))+_26_t22);
	_26_t24 = 2;
	_26_t25 = *(((int64_t*)((((struct1*)(&_27_x))+_26_t22)))+_26_t24);
	_26_$retval = _26_t25;
	return _26_$retval;
}


int main()
{
  printf("%ld",_26_main());
  return 0;
}

#endif
