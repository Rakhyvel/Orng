/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688400214792780085
#define ORNG_1688400214792780085

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	uint64_t tag;
	union {
		int64_t _0;
		int64_t _2;
		uint8_t _1;
	};
} struct1;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t0;
	struct1 _2_t1;
	struct1 _3_x;
	int64_t _2_t2;
	int64_t _2_$retval;
BB0:
	_2_t0 = 101;
	_2_t1 = (struct1) {0, _2_t0};
	_3_x = _2_t1;
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
