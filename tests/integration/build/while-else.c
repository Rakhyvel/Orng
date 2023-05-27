/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685229737
#define ORNG_1685229737

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _4_x;
	int64_t _2_t3;
	int64_t _2_t4;
	uint8_t _2_t2;
	int64_t _2_t5;
	int64_t _2_t6;
	int64_t _2_t7;
	int64_t _2_t0;
	int64_t _2_t9;
	int64_t _2_t10;
	int64_t _2_t11;
	int64_t _2_$retval;
BB0: // 1
// Versions: 8
	_4_x = 0;
	goto BB1;
BB1: // 2
// Versions: 1
	_2_t3 = _4_x;
// Versions: 1
	_2_t4 = 10;
// Versions: 5
	_2_t2 = _2_t3 < _2_t4;
	if (!_2_t2) {
		goto BB7;
	} else {
		goto BB2;
	}
BB2: // 1
// Versions: 5
	_2_t2 = 1;
	goto BB3;
BB3: // 2
	if (!_2_t2) {
		goto BB5;
	} else {
		goto BB4;
	}
BB4: // 1
// Versions: 1
	_2_t5 = _4_x;
// Versions: 1
	_2_t6 = 1;
// Versions: 1
	_2_t7 = _2_t5 + _2_t6;
// Versions: 2
	_2_t0 = 0;
// Versions: 1
	_2_t9 = _2_t7;
// Versions: 1
	_2_t10 = 1;
// Versions: 1
	_2_t11 = _2_t9 + _2_t10;
// Versions: 8
	_4_x = _2_t11;
	goto BB1;
BB5: // 1
// Versions: 2
	_2_t0 = _4_x;
// Versions: 1
	_2_$retval = _2_t0;
	goto end;
BB7: // 1
// Versions: 5
	_2_t2 = 0;
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
