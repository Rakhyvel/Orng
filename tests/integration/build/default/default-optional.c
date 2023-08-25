/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1692936345120410938
#define ORNG_1692936345120410938

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
	uint8_t _2_t2;
	int64_t _2_t1;
	int64_t _2_$retval;
BB0:
	_3_x = (struct0) {.tag=0};
	_2_t2 = _3_x.tag;
	if (_2_t2) {
		goto BB1;
	} else {
		goto BB4;
	}
BB4:
	_2_t1 = 138;
	goto BB3;
BB3:
	_2_$retval = _2_t1;
	return _2_$retval;
BB1:
	_2_t1 = (&_3_x)->_1;
	goto BB3;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
