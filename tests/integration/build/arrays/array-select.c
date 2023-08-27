/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1691899681445729255
#define ORNG_1691899681445729255

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
	struct0 _2;
} struct1;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t2;
	int64_t _2_t3;
	struct0 _2_t1;
	int64_t _2_t5;
	int64_t _2_t6;
	struct0 _2_t4;
	int64_t _2_t8;
	int64_t _2_t9;
	struct0 _2_t7;
	struct1 _3_x;
	int64_t _2_t10;
	int64_t _2_t16;
	int64_t _2_t17;
	int64_t _2_$retval;
BB0:
	_2_t2 = 1;
	_2_t3 = 2;
	_2_t1 = (struct0) {_2_t2, _2_t3};
	_2_t5 = 3;
	_2_t6 = 4;
	_2_t4 = (struct0) {_2_t5, _2_t6};
	_2_t8 = 5;
	_2_t9 = 6;
	_2_t7 = (struct0) {_2_t8, _2_t9};
	_3_x = (struct1) {_2_t1, _2_t4, _2_t7};
	_2_t10 = 1;
	_2_t16 = 73;
	((((struct0*)(&_3_x))+_2_t10))->_0 = _2_t16;
	_2_t17 = 1;
	_2_$retval = ((((struct0*)(&_3_x))+_2_t17))->_0;
	return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
