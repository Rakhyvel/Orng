/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688935579756420815
#define ORNG_1688935579756420815

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

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
	int64_t _2_t4;
	int64_t _2_$retval;
BB0:
	_2_t0 = 4;
	_2_t1 = (struct0) {.tag=0, ._0=_2_t0};
	_3_x = (struct1) {.tag=0, ._0=_2_t1};
	_2_t4 = 104;
	(&((&_3_x)->_0))->_0 = _2_t4;
	_2_$retval = (&((&_3_x)->_0))->_0;
	return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
