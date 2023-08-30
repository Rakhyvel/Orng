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
	int64_t _2_t3;
	int64_t _2_t4;
	uint8_t _2_t5;
	int64_t _2_$retval;
BB0:
	_2_t0 = 104;
	_3_x = (struct0) {.tag=0, ._0=_2_t0};
	_2_t3 = 0;
	_2_t4 = _3_x.tag;
	_2_t5 = _2_t4 != _2_t3;
	if (_2_t5) {
		goto BB1;
	} else {
		goto BB2;
	}
BB2:
	_2_$retval = (&_3_x)->_0;
	return _2_$retval;
BB1:
    $lines[$line_idx++] = "tests/integration/sums/namespace.orng:6:7:\n    x.int\n       ^";
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
