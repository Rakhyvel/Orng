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
	int64_t _2_t3;
	struct0 _3_x;
	int64_t _2_t6;
	int64_t _2_t7;
	uint8_t _2_t8;
	int64_t _2_$retval;
BB0:
	_2_t3 = 113;
	_3_x = (struct0) {.tag=1, ._1=_2_t3};
	_2_t6 = 1;
	_2_t7 = _3_x.tag;
	_2_t8 = _2_t7 != _2_t6;
	if (_2_t8) {
		goto BB1;
	} else {
		goto BB2;
	}
BB2:
	_2_$retval = (&_3_x)->_1;
	return _2_$retval;
BB1:
    $lines[$line_idx++] = "tests/integration/optional/optional.orng:6:7:\n    x.some // This acts like `.?` in Zig, tags are checked at runtime in debug mode\n       ^";
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
