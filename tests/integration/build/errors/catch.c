/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1691899681449729182
#define ORNG_1691899681449729182

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include<stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */
typedef struct {
	uint64_t tag;
	union {
		uint32_t _0;
		int64_t _1;
	};
} struct0;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	uint32_t _2_t0;
	struct0 _3_x;
	uint8_t _2_t3;
	int64_t _2_t2;
	int64_t _2_$retval;
BB0:
	_2_t0 = 100;
	_3_x = (struct0) {.tag=0, ._0=_2_t0};
	_2_t3 = _3_x.tag;
	if (_2_t3) {
		goto BB1;
	} else {
		goto BB4;
	}
BB4:
	_2_t2 = 118;
	goto BB3;
BB3:
	_2_$retval = _2_t2;
	return _2_$retval;
BB1:
	_2_t2 = (&_3_x)->_1;
	goto BB3;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
