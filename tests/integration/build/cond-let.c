/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685229660
#define ORNG_1685229660

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _21_x;
	int64_t _20_t3;
	int64_t _20_t4;
	int64_t _20_t5;
	int64_t _20_t6;
	uint8_t _20_t2;
	int64_t _20_t0;
	int64_t _20_$retval;
	int64_t _20_t8;
	int64_t _20_t9;
	int64_t _20_t10;
	int64_t _20_t11;
	uint8_t _20_t7;
BB0: // 1
// Versions: 1
	_21_x = 4;
// Versions: 1
	_21_x = 4;
// Versions: 1
	_20_t3 = 4;
// Versions: 1
	_20_t4 = 4;
// Versions: 1
	_20_t5 = _20_t3 - _20_t4;
// Versions: 1
	_20_t6 = 1;
// Versions: 2
	_20_t2 = _20_t5 == _20_t6;
	if (!_20_t2) {
		goto BB18;
	} else {
		goto BB2;
	}
BB2: // 1
// Versions: 2
	_20_t2 = 1;
	goto BB3;
BB3: // 2
	if (!_20_t2) {
		goto BB7;
	} else {
		goto BB5;
	}
BB5: // 1
// Versions: 2
	_20_t0 = 10;
	goto BB6;
BB6: // 3
// Versions: 1
	_20_$retval = _20_t0;
	goto end;
BB7: // 1
// Versions: 1
	_20_t8 = _21_x;
// Versions: 1
	_20_t9 = 3;
// Versions: 1
	_20_t10 = _20_t8 - _20_t9;
// Versions: 1
	_20_t11 = 1;
// Versions: 2
	_20_t7 = _20_t10 == _20_t11;
	if (!_20_t7) {
		goto BB17;
	} else {
		goto BB8;
	}
BB8: // 1
// Versions: 2
	_20_t7 = 1;
	goto BB9;
BB9: // 2
	if (!_20_t7) {
		goto BB12;
	} else {
		goto BB11;
	}
BB11: // 1
// Versions: 2
	_20_t0 = 23;
	goto BB6;
BB12: // 1
// Versions: 2
	_20_t0 = 10;
	goto BB6;
BB17: // 1
// Versions: 2
	_20_t7 = 0;
	goto BB9;
BB18: // 1
// Versions: 2
	_20_t2 = 0;
	goto BB3;
end:
	return _20_$retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
