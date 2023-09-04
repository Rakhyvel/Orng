/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1693863898095709744
#define ORNG_1693863898095709744

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
} struct0;
typedef struct {
	struct0 _0;
	struct0 _1;
} struct1;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t15;
	int64_t _2_t16;
	struct0 _2_t14;
	int64_t _2_t18;
	int64_t _2_t19;
	struct0 _2_t17;
	struct1 _2_t13;
	struct0 _2_t21;
	int64_t _3_x;
	int64_t _3_y;
	struct0 _2_t25;
	int64_t _3_a;
	int64_t _3_b;
	int64_t _2_t28;
	int64_t _2_t29;
	int64_t _2_$retval;
BB0:
	_2_t15 = 1;
	_2_t16 = 40;
	_2_t14 = (struct0) {_2_t15, _2_t16};
	_2_t18 = 2;
	_2_t19 = 2;
	_2_t17 = (struct0) {_2_t18, _2_t19};
	_2_t13 = (struct1) {_2_t14, _2_t17};
	_2_t21 = (&_2_t13)->_0;
	_3_x = (&((&_2_t13)->_0))->_0;
	_3_y = (&((&_2_t13)->_0))->_1;
	_2_t25 = (&_2_t13)->_1;
	_3_a = (&((&_2_t13)->_1))->_0;
	_3_b = (&((&_2_t13)->_1))->_1;
	_2_t28 = _3_x + _3_y;
	_2_t29 = _3_a + _3_b;
	_2_$retval = _2_t28 * _2_t29;
	return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
