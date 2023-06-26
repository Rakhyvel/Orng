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
} struct2;

/* Function forward definitions */
int64_t _407_main();

/* Function definitions */
int64_t _407_main() {
	int64_t _407_t2;
	int64_t _407_t3;
	int64_t _407_t4;
	struct1 _407_t1;
	int64_t _407_t6;
	int64_t _407_t7;
	int64_t _407_t8;
	struct1 _407_t5;
	struct2 _408_x;
	struct1 _407_t9;
	int64_t _407_t10;
	int64_t _407_t11;
	struct1 _407_t12;
	int64_t _407_t13;
	int64_t _407_t14;
	int64_t _407_$retval;
BB0:
	_407_t2 = 1;
	_407_t3 = 2;
	_407_t4 = 3;
	_407_t1 = (struct1) {_407_t2, _407_t3, _407_t4};
	_407_t6 = 4;
	_407_t7 = 5;
	_407_t8 = 6;
	_407_t5 = (struct1) {_407_t6, _407_t7, _407_t8};
	_408_x = (struct2) {_407_t1, _407_t5};
	_407_t9 = *&((&_408_x)->_0);
	_407_t10 = 1;
	_407_t11 = 72;
	*(((int64_t*)(&((&_408_x)->_0)))+_407_t10) = _407_t11;
	_407_t12 = *&((&_408_x)->_0);
	_407_t13 = 1;
	_407_t14 = *(((int64_t*)(&((&_408_x)->_0)))+_407_t13);
	_407_$retval = _407_t14;
	return _407_$retval;
}


int main()
{
  printf("%ld",_407_main());
  return 0;
}

#endif
