/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687738073
#define ORNG_1687738073

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
int64_t _394_main();

/* Function definitions */
int64_t _394_main() {
	int64_t _394_t2;
	int64_t _394_t3;
	int64_t _394_t4;
	struct1 _394_t1;
	int64_t _394_t6;
	int64_t _394_t7;
	int64_t _394_t8;
	struct1 _394_t5;
	int64_t _394_t10;
	int64_t _394_t11;
	int64_t _394_t12;
	struct1 _394_t9;
	struct2 _395_x;
	int64_t _394_t13;
	struct1 _394_t14;
	int64_t _394_t15;
	int64_t _394_t16;
	struct1 _394_t17;
	int64_t _394_t18;
	int64_t _394_t19;
	int64_t _394_t20;
	int64_t _394_t21;
	int64_t _394_t22;
	struct1 _394_t23;
	int64_t _394_t24;
	int64_t _394_t25;
	int64_t _394_$retval;
BB0:
	_394_t2 = 1;
	_394_t3 = 2;
	_394_t4 = 3;
	_394_t1 = (struct1) {_394_t2, _394_t3, _394_t4};
	_394_t6 = 4;
	_394_t7 = 5;
	_394_t8 = 68;
	_394_t5 = (struct1) {_394_t6, _394_t7, _394_t8};
	_394_t10 = 7;
	_394_t11 = 8;
	_394_t12 = 9;
	_394_t9 = (struct1) {_394_t10, _394_t11, _394_t12};
	_395_x = (struct2) {_394_t1, _394_t5, _394_t9};
	_394_t13 = 1;
	_394_t14 = *(((struct1*)(&_395_x))+_394_t13);
	_394_t15 = 2;
	_394_t16 = 1;
	_394_t17 = *(((struct1*)(&_395_x))+_394_t16);
	_394_t18 = 2;
	_394_t19 = *(((int64_t*)((((struct1*)(&_395_x))+_394_t16)))+_394_t18);
	_394_t20 = 1;
	_394_t21 = _394_t19 + _394_t20;
	*(((int64_t*)((((struct1*)(&_395_x))+_394_t13)))+_394_t15) = _394_t21;
	_394_t22 = 1;
	_394_t23 = *(((struct1*)(&_395_x))+_394_t22);
	_394_t24 = 2;
	_394_t25 = *(((int64_t*)((((struct1*)(&_395_x))+_394_t22)))+_394_t24);
	_394_$retval = _394_t25;
	return _394_$retval;
}


int main()
{
  printf("%ld",_394_main());
  return 0;
}

#endif
