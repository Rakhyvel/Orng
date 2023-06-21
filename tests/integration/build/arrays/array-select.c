/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687313803
#define ORNG_1687313803

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
int64_t _11_main();

/* Function definitions */
int64_t _11_main() {
	int64_t _11_t2;
	int64_t _11_t3;
	struct1 _11_t1;
	int64_t _11_t5;
	int64_t _11_t6;
	struct1 _11_t4;
	int64_t _11_t8;
	int64_t _11_t9;
	struct1 _11_t7;
	struct2 _12_x;
	int64_t _11_t10;
	struct1 _11_t11;
	int64_t _11_t12;
	int64_t _11_t13;
	struct1 _11_t14;
	int64_t _11_t15;
	int64_t _11_$retval;
BB0:
	_11_t2 = 1;
	_11_t3 = 2;
	_11_t1 = (struct1) {_11_t2, _11_t3};
	_11_t5 = 3;
	_11_t6 = 4;
	_11_t4 = (struct1) {_11_t5, _11_t6};
	_11_t8 = 5;
	_11_t9 = 6;
	_11_t7 = (struct1) {_11_t8, _11_t9};
	_12_x = (struct2) {_11_t1, _11_t4, _11_t7};
	_11_t10 = 1;
	_11_t12 = 73;
	((((struct1*)(&_12_x))+_11_t10))->_0 = _11_t12;
	_11_t13 = 1;
	_11_t14 = *(((struct1*)(&_12_x))+_11_t13);
	_11_t15 = *&(((((struct1*)(&_12_x))+_11_t13))->_0);
	_11_$retval = _11_t15;
	return _11_$retval;
}


int main()
{
  printf("%ld",_11_main());
  return 0;
}

#endif
