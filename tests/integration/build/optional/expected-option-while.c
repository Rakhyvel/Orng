/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1689043337074952400
#define ORNG_1689043337074952400

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
		int64_t _1;
	};
} struct0;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	struct0 _3_y;
	uint8_t _2_t4;
	int64_t _2_t3;
	int64_t _2_$retval;
BB1:
	_3_y = (struct0) {.tag=0};
	_2_t4 = _3_y.tag;
	if (_2_t4) {
		goto BB7;
	} else {
		goto BB10;
	}
BB10:
	_2_t3 = 116;
	goto BB9;
BB9:
	_2_$retval = _2_t3;
	return _2_$retval;
BB7:
	_2_t3 = (&_3_y)->_1;
	goto BB9;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
