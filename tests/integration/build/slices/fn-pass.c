/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688935735081096113
#define ORNG_1688935735081096113

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
	int64_t _2;
	int64_t _3;
} struct0;
typedef struct {
	int64_t* _0;
	int64_t _1;
} struct1;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();
int64_t _4_f(struct1 _4_x);

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t2;
	int64_t _2_t3;
	int64_t _2_t4;
	struct0 _3_x;
	int64_t _2_t6;
	int64_t* _2_t8;
	int64_t _2_t9;
	struct1 _3_y;
	int64_t _2_t10;
	int64_t _2_$retval;
BB0:
	_2_t1 = 1;
	_2_t2 = 2;
	_2_t3 = 3;
	_2_t4 = 4;
	_3_x = (struct0) {_2_t1, _2_t2, _2_t3, _2_t4};
	_2_t6 = 0;
	_2_t8 = (((int64_t*)(&_3_x))+_2_t6);
	_2_t9 = 4;
	_3_y = (struct1) {_2_t8, _2_t9};
	_2_t10 = _4_f(_3_y);
	_2_$retval = _2_t10;
	return _2_$retval;
}

int64_t _4_f(struct1 _4_x) {
	int64_t _4_t0;
	int64_t _4_t1;
	int64_t _4_t2;
	int64_t _4_$retval;
BB0:
	_4_t0 = 1;
	_4_t1 = *(((int64_t*)((&_4_x)->_0))+_4_t0);
	_4_t2 = 80;
	_4_$retval = _4_t1 + _4_t2;
	return _4_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
