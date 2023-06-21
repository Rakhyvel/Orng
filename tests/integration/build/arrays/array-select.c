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
} struct1;
typedef struct {
	struct1 _0;
	struct1 _1;
	struct1 _2;
} struct2;

/* Function forward definitions */
int64_t _375_main();

/* Function definitions */
int64_t _375_main() {
	int64_t _375_t2;
	int64_t _375_t3;
	struct1 _375_t1;
	int64_t _375_t5;
	int64_t _375_t6;
	struct1 _375_t4;
	int64_t _375_t8;
	int64_t _375_t9;
	struct1 _375_t7;
	struct2 _376_x;
	int64_t _375_t10;
	struct1 _375_t11;
	int64_t _375_t12;
	int64_t _375_t13;
	struct1 _375_t14;
	int64_t _375_t15;
	int64_t _375_$retval;
BB0:
	_375_t2 = 1;
	_375_t3 = 2;
	_375_t1 = (struct1) {_375_t2, _375_t3};
	_375_t5 = 3;
	_375_t6 = 4;
	_375_t4 = (struct1) {_375_t5, _375_t6};
	_375_t8 = 5;
	_375_t9 = 6;
	_375_t7 = (struct1) {_375_t8, _375_t9};
	_376_x = (struct2) {_375_t1, _375_t4, _375_t7};
	_375_t10 = 1;
	_375_t12 = 73;
	((((struct1*)(&_376_x))+_375_t10))->_0 = _375_t12;
	_375_t13 = 1;
	_375_t14 = *(((struct1*)(&_376_x))+_375_t13);
	_375_t15 = *&(((((struct1*)(&_376_x))+_375_t13))->_0);
	_375_$retval = _375_t15;
	return _375_$retval;
}


int main()
{
  printf("%ld",_375_main());
  return 0;
}

#endif
