/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687131173
#define ORNG_1687131173

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
int64_t _363_main();

/* Function definitions */
int64_t _363_main() {
	int64_t _363_t2;
	int64_t _363_t3;
	int64_t _363_t4;
	struct1 _363_t1;
	int64_t _363_t6;
	int64_t _363_t7;
	int64_t _363_t8;
	struct1 _363_t5;
	int64_t _363_t10;
	int64_t _363_t11;
	int64_t _363_t12;
	struct1 _363_t9;
	struct2 _364_x;
	int64_t _363_t13;
	struct1 _363_t14;
	int64_t _363_t15;
	int64_t _363_t16;
	struct1 _363_t17;
	int64_t _363_t18;
	int64_t _363_t19;
	int64_t _363_t20;
	int64_t _363_t21;
	int64_t _363_t22;
	struct1 _363_t23;
	int64_t _363_t24;
	int64_t _363_t25;
	int64_t _363_$retval;
BB0:
	_363_t2 = 1;
	_363_t3 = 2;
	_363_t4 = 3;
	_363_t1 = (struct1) {_363_t2, _363_t3, _363_t4};
	_363_t6 = 4;
	_363_t7 = 5;
	_363_t8 = 68;
	_363_t5 = (struct1) {_363_t6, _363_t7, _363_t8};
	_363_t10 = 7;
	_363_t11 = 8;
	_363_t12 = 9;
	_363_t9 = (struct1) {_363_t10, _363_t11, _363_t12};
	_364_x = (struct2) {_363_t1, _363_t5, _363_t9};
	_363_t13 = 1;
	_363_t15 = 2;
	_363_t16 = 1;
	_363_t17 = ((struct1*)(&_364_x))[_363_t16];
	_363_t18 = 2;
	_363_t19 = ((int64_t*)(&_363_t17))[_363_t18];
	_363_t20 = 1;
	_363_t21 = _363_t19 + _363_t20;
(((int64_t*)((((struct1*)(&_364_x))+_363_t13)))[_363_t15]) = _363_t21;
	_363_t22 = 1;
	_363_t23 = ((struct1*)(&_364_x))[_363_t22];
	_363_t24 = 2;
	_363_t25 = ((int64_t*)(&_363_t23))[_363_t24];
	_363_$retval = _363_t25;
	return _363_$retval;
}


int main()
{
  printf("%ld",_363_main());
  return 0;
}

#endif
