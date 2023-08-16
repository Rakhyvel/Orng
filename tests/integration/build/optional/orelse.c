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
		int64_t _1;
	};
} struct0;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	struct0 _3_x;
	int64_t _2_t1;
	struct0 _3_y;
	uint8_t _2_t4;
	int64_t _2_t3;
	uint8_t _2_t9;
	int64_t _2_t8;
	int64_t _2_$retval;
BB0:
	_3_x = (struct0) {.tag=0};
	_2_t1 = 100;
	_3_y = (struct0) {.tag=1, ._1=_2_t1};
	_2_t4 = _3_y.tag;
	if (_2_t4) {
		goto BB1;
	} else {
		goto BB7;
	}
BB7:
	_2_t3 = -10;
	goto BB2;
BB2:
	_2_t9 = _3_x.tag;
	if (_2_t9) {
		goto BB3;
	} else {
		goto BB6;
	}
BB6:
	_2_t8 = 14;
	goto BB4;
BB4:
	_2_$retval = _2_t3 + _2_t8;
	return _2_$retval;
BB3:
	_2_t8 = (&_3_x)->_1;
	goto BB4;
BB1:
	_2_t3 = (&_3_y)->_1;
	goto BB2;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
