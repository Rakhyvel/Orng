/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688790635825238382
#define ORNG_1688790635825238382

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	uint64_t tag;
	union {
		int64_t _0;
		uint8_t _1;
	};
} struct0;
typedef struct {
	uint64_t tag;
	union {
		struct0 _0;
	};
} struct1;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t0;
	struct0 _2_t1;
	struct1 _3_x;
	struct0 _2_t3;
	int64_t _2_t4;
	struct0 _2_t5;
	int64_t _2_t6;
	int64_t _2_$retval;
BB0:
	_2_t0 = 4;
	_2_t1 = (struct0) {.tag=0, ._0=_2_t0};
	_3_x = (struct1) {.tag=0, ._0=_2_t1};
	_2_t4 = 104;
	(&((&_3_x)->_0))->_0 = _2_t4;
	_2_t5 = *&((&_3_x)->_0);
	_2_t6 = *&((&((&_3_x)->_0))->_0);
	_2_$retval = _2_t6;
	return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
