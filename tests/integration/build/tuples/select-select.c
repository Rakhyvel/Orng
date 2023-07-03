/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687313475067567065
#define ORNG_1687313475067567065

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

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t2;
	int64_t _2_t3;
	struct1 _2_t1;
	int64_t _2_t5;
	int64_t _2_t6;
	struct1 _2_t4;
	struct2 _3_x;
	struct1 _2_t7;
	int64_t _2_t8;
	struct1 _2_t9;
	int64_t _2_t10;
	int64_t _2_$retval;
BB0:
	_2_t2 = 1;
	_2_t3 = 2;
	_2_t1 = (struct1) {_2_t2, _2_t3};
	_2_t5 = 3;
	_2_t6 = 4;
	_2_t4 = (struct1) {_2_t5, _2_t6};
	_3_x = (struct2) {_2_t1, _2_t4};
	_2_t8 = 77;
	(&((&_3_x)->_0))->_0 = _2_t8;
	_2_t9 = *&((&_3_x)->_0);
	_2_t10 = *&((&((&_3_x)->_0))->_0);
	_2_$retval = _2_t10;
	return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
