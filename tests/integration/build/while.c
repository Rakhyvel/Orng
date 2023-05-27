/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685229732
#define ORNG_1685229732

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _3_x;
	int64_t _4_i;
	int64_t _2_t4;
	int64_t _2_t5;
	uint8_t _2_t3;
	int64_t _2_t6;
	int64_t _2_t7;
	int64_t _2_t8;
	int64_t _2_t9;
	int64_t _2_t10;
	int64_t _2_t11;
	int64_t _2_$retval;
BB0: // 1
// Versions: 8
	_3_x = 0;
// Versions: 8
	_4_i = 0;
	goto BB1;
BB1: // 2
// Versions: 1
	_2_t4 = _4_i;
// Versions: 1
	_2_t5 = 10;
// Versions: 5
	_2_t3 = _2_t4 <= _2_t5;
	if (!_2_t3) {
		goto BB7;
	} else {
		goto BB2;
	}
BB2: // 1
// Versions: 5
	_2_t3 = 1;
	goto BB3;
BB3: // 2
	if (!_2_t3) {
		goto BB6;
	} else {
		goto BB4;
	}
BB4: // 1
// Versions: 1
	_2_t6 = _3_x;
// Versions: 1
	_2_t7 = _4_i;
// Versions: 1
	_2_t8 = _2_t6 + _2_t7;
// Versions: 8
	_3_x = _2_t8;
// Versions: 1
	_2_t9 = _4_i;
// Versions: 1
	_2_t10 = 1;
// Versions: 1
	_2_t11 = _2_t9 + _2_t10;
// Versions: 8
	_4_i = _2_t11;
	goto BB1;
BB6: // 1
// Versions: 1
	_2_$retval = _3_x;
	goto end;
BB7: // 1
// Versions: 5
	_2_t3 = 0;
	goto BB3;
end:
	return _2_$retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
