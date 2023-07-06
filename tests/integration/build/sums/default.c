/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688415979032867065
#define ORNG_1688415979032867065

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

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t0;
	struct0 _3_x;
	int64_t _2_t2;
	int64_t _2_$retval;
BB0:
	_2_t0 = 102;
	_3_x = (struct0) {.tag=0, ._0=_2_t0};
	_2_t2 = *&((&_3_x)->_0);
	_2_$retval = _2_t2;
	return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
