/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688935531857863145
#define ORNG_1688935531857863145

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
} struct0;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t2;
	struct0 _3_x;
	struct0* _3_y;
	int64_t _2_t5;
	int64_t _2_t7;
	int64_t _2_t9;
	int64_t _2_$retval;
BB0:
	_2_t1 = 11;
	_2_t2 = 11;
	_3_x = (struct0) {_2_t1, _2_t2};
	_3_y = &_3_x;
	_2_t5 = 50;
	(_3_y)->_0 = _2_t5;
	_2_t7 = (_3_y)->_0;
	_2_t9 = (_3_y)->_1;
	_2_$retval = _2_t7 + _2_t9;
	return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
