/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1692937284292499669
#define ORNG_1692937284292499669

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
		double _0;
		int64_t _1;
	};
} struct0;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();
struct0 _4_a();

/* Function definitions */
int64_t _2_main() {
	struct0 _2_t1;
	uint8_t _2_t2;
	int64_t _2_t0;
	int64_t _2_$retval;
BB0:
    $lines[$line_idx++] = "tests/integration/errors/error2.orng:2:21:\nfn main() -> Int {a() catch 139}";
	_2_t1 = _4_a();
	_2_t2 = _2_t1.tag;
	if (_2_t2) {
		goto BB1;
	} else {
		goto BB4;
	}
BB4:
	_2_t0 = 139;
	goto BB3;
BB3:
	_2_$retval = _2_t0;
	return _2_$retval;
BB1:
	_2_t0 = (&_2_t1)->_1;
	goto BB3;
}

struct0 _4_a() {
	int64_t _4_t0;
	struct0 _4_$retval;
BB0:
	_4_t0 = 0;
	_4_$retval = (struct0) {.tag=1, ._1=_4_t0};
	return _4_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
