/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1692935949877415949
#define ORNG_1692935949877415949

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
		int64_t _0;
	};
} struct0;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t0;
	struct0 _3_x;
	int64_t _2_t5;
	int64_t _2_t6;
	uint8_t _2_t7;
	int64_t _2_t4;
	int64_t _2_t8;
	uint8_t _2_t3;
	int64_t _2_t2;
	int64_t _2_$retval;
BB0:
	_2_t0 = 0;
	_3_x = (struct0) {.tag=0, ._0=_2_t0};
	_2_t5 = 0;
	_2_t6 = _3_x.tag;
	_2_t7 = _2_t6 != _2_t5;
	if (_2_t7) {
		goto BB1;
	} else {
		goto BB2;
	}
BB2:
	_2_t4 = (&_3_x)->_0;
	_2_t8 = 0;
	_2_t3 = _2_t4 == _2_t8;
	if (_2_t3) {
		goto BB3;
	} else {
		goto BB11;
	}
BB11:
	_2_t2 = 0;
	goto BB8;
BB8:
	_2_$retval = _2_t2;
	return _2_$retval;
BB3:
	_2_t2 = 133;
	goto BB8;
BB1:
    $lines[$line_idx++] = "tests/integration/default/default-sum.orng:4:10:\n    if x.a == 0\n          ^";
    fprintf(stderr, "panic: access of inactive sum field\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
	goto BB2;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
