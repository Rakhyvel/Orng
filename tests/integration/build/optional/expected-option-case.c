/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1692247368719028229
#define ORNG_1692247368719028229

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
	uint8_t _2_t6;
	int64_t _2_t5;
	int64_t _2_$retval;
BB1:
	_3_x = (struct0) {.tag=0};
	_2_t6 = _3_x.tag;
	if (_2_t6) {
		goto BB5;
	} else {
		goto BB8;
	}
BB8:
	_2_t5 = 129;
	goto BB7;
BB7:
	_2_$retval = _2_t5;
	return _2_$retval;
BB5:
	_2_t5 = (&_3_x)->_1;
	goto BB7;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
