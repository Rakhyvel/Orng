/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1693863741769701584
#define ORNG_1693863741769701584

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include<stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
	int64_t _2;
} struct0;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t2;
	int64_t _2_t3;
	struct0 _3_x;
	int64_t _2_t5;
	int64_t _2_t6;
	int64_t _2_t7;
	struct0 _2_t4;
	int64_t _2_t9;
	int64_t _2_t11;
	int64_t _2_t13;
	int64_t _2_t14;
	int64_t _2_t15;
	int64_t _2_t16;
	int64_t _2_t17;
	int64_t _2_$retval;
BB0:
	_2_t1 = 1;
	_2_t2 = 2;
	_2_t3 = 3;
	_3_x = (struct0) {_2_t1, _2_t2, _2_t3};
	_2_t5 = 60;
	_2_t6 = 23;
	_2_t7 = 200;
	_2_t4 = (struct0) {_2_t5, _2_t6, _2_t7};
	_2_t9 = (&_2_t4)->_0;
	(&_3_x)->_1 = _2_t9;
	_2_t11 = (&_2_t4)->_1;
	(&_3_x)->_2 = _2_t11;
	_2_t13 = (&_2_t4)->_2;
	(&_3_x)->_0 = _2_t13;
	_2_t14 = (&_3_x)->_0;
	_2_t15 = (&_3_x)->_1;
	_2_t16 = _2_t14 - _2_t15;
	_2_t17 = (&_3_x)->_2;
	_2_$retval = _2_t16 + _2_t17;
	return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
