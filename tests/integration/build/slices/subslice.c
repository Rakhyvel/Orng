/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688089601589312928
#define ORNG_1688089601589312928

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
	int64_t _2;
	int64_t _3;
	int64_t _4;
	int64_t _5;
} struct1;
typedef struct {
	int64_t* _0;
	int64_t _1;
} struct3;

/* Function forward definitions */
int64_t _423_main();
int64_t _425_sum_up(struct3 _425_xs);

/* Function definitions */
int64_t _423_main() {
	int64_t _423_t1;
	int64_t _423_t2;
	int64_t _423_t3;
	int64_t _423_t4;
	int64_t _423_t5;
	int64_t _423_t6;
	struct1 _424_x;
	int64_t _423_t8;
	int64_t _423_t9;
	int64_t* _423_t10;
	int64_t _423_t11;
	struct3 _424_y;
	int64_t _423_t12;
	int64_t _423_t14;
	int64_t* _423_t15;
	int64_t* _423_t16;
	struct3 _424_z;
	int64_t _423_t18;
	int64_t _423_t19;
	int64_t _423_t20;
	int64_t _423_$retval;
BB0:
	_423_t1 = 1;
	_423_t2 = 15;
	_423_t3 = 24;
	_423_t4 = 4;
	_423_t5 = 35;
	_423_t6 = 6;
	_424_x = (struct1) {_423_t1, _423_t2, _423_t3, _423_t4, _423_t5, _423_t6};
	_423_t8 = 0;
	_423_t9 = *(((int64_t*)(&_424_x))+_423_t8);
	_423_t10 = (((int64_t*)(&_424_x))+_423_t8);
	_423_t11 = 6;
	_424_y = (struct3) {_423_t10, _423_t11};
	_423_t12 = 1;
	_423_t14 = 4;
	_423_t15 = *&((&_424_y)->_0);
	_423_t16 = _423_t15 + _423_t12;
	_424_z = (struct3) {_423_t16, _423_t14};
	_423_t18 = 2;
	_423_t19 = 10;
	*(((int64_t*)((&_424_z)->_0))+_423_t18) = _423_t19;
	_423_t20 = _425_sum_up(_424_z);
	_423_$retval = _423_t20;
	return _423_$retval;
}

int64_t _425_sum_up(struct3 _425_xs) {
	int64_t _426_sum;
	int64_t _427_i;
	int64_t _425_t4;
	uint8_t _425_t3;
	int64_t _425_t5;
	int64_t _425_t7;
	int64_t _425_$retval;
BB0:
	_426_sum = 0;
	_427_i = 0;
	goto BB1;
BB1:
	_425_t4 = *&((&_425_xs)->_1);
	_425_t3 = _427_i < _425_t4;
	if (!_425_t3) {
		goto BB10;
	} else {
		goto BB2;
	}
BB2:
	_425_t5 = *(((int64_t*)((&_425_xs)->_0))+_427_i);
	_426_sum = _426_sum + _425_t5;
	_425_t7 = 1;
	_427_i = _427_i + _425_t7;
	goto BB1;
BB10:
	_425_$retval = _426_sum;
	return _425_$retval;
}


int main()
{
  printf("%ld",_423_main());
  return 0;
}

#endif
