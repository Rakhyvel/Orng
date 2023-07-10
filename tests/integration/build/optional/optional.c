/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688952446611436190
#define ORNG_1688952446611436190

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	uint64_t tag;
	union {
		int64_t _1;
	};
} struct0;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t3;
	struct0 _3_x;
	int64_t _2_$retval;
BB0:
	_2_t3 = 113;
	_3_x = (struct0) {.tag=1, ._1=_2_t3};
	_2_$retval = (&_3_x)->_1;
	return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
