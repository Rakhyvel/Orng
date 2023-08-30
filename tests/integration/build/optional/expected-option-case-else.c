/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1692245717183776707
#define ORNG_1692245717183776707

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
	int64_t _2_t7;
	struct0 _3_x;
	int64_t _2_t10;
	int64_t _2_t11;
	uint8_t _2_t12;
	int64_t _2_$retval;
BB1:
	_2_t7 = 128;
	_3_x = (struct0) {.tag=1, ._1=_2_t7};
	_2_t10 = 1;
	_2_t11 = _3_x.tag;
	_2_t12 = _2_t11 != _2_t10;
	if (_2_t12) {
		goto BB5;
	} else {
		goto BB6;
	}
BB6:
	_2_$retval = (&_3_x)->_1;
	return _2_$retval;
BB5:
    $lines[$line_idx++] = "tests/integration/optional/expected-option-case-else.orng:7:7:\n    x.some\n       ^";
    fprintf(stderr, "panic: access of inactive sum field\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
	goto BB6;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
