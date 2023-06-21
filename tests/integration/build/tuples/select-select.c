/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687313476
#define ORNG_1687313476

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
} struct2;

/* Function forward definitions */
int64_t _14_main();

/* Function definitions */
int64_t _14_main() {
	int64_t _14_t2;
	int64_t _14_t3;
	struct1 _14_t1;
	int64_t _14_t5;
	int64_t _14_t6;
	struct1 _14_t4;
	struct2 _15_x;
	struct1 _14_t7;
	int64_t _14_t8;
	struct1 _14_t9;
	int64_t _14_t10;
	int64_t _14_$retval;
BB0:
	_14_t2 = 1;
	_14_t3 = 2;
	_14_t1 = (struct1) {_14_t2, _14_t3};
	_14_t5 = 3;
	_14_t6 = 4;
	_14_t4 = (struct1) {_14_t5, _14_t6};
	_15_x = (struct2) {_14_t1, _14_t4};
	_14_t8 = 77;
	(&((&_15_x)->_0))->_0 = _14_t8;
	_14_t9 = *&((&_15_x)->_0);
	_14_t10 = *&((&((&_15_x)->_0))->_0);
	_14_$retval = _14_t10;
	return _14_$retval;
}


int main()
{
  printf("%ld",_14_main());
  return 0;
}

#endif
