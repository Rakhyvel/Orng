/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684898822
#define ORNG_1684898822

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int64_t _20_t1;
	int64_t _21_x;
	int64_t _20_t3;
	int64_t _20_t4;
	int64_t _20_t5;
	uint8_t _20_t6;
	uint8_t _20_t2;
	int64_t _20_t17;
	int64_t _20_t0;
	int64_t _0;
	int64_t _20_t8;
	int64_t _20_t9;
	int64_t _20_t10;
	uint8_t _20_t11;
	uint8_t _20_t7;
	int64_t _20_t18;
	int64_t _20_t13;
	int64_t _20_t14;
	int64_t _20_t15;
	uint8_t _20_t16;
	uint8_t _20_t12;
	int64_t _20_t19;
BB0: // 1
	_20_t1 = 4;
	_21_x = _20_t1;
	_20_t3 = 4;
	_20_t4 = _21_x - _20_t3;
	_20_t5 = 1;
	_20_t6 = _20_t4 == _20_t5;
	if (!_20_t6) {
		goto BB18;
	} else {
		goto BB2;
	}
BB2: // 1
	_20_t2 = 1;
	goto BB3;
BB3: // 2
	if (!_20_t2) {
		goto BB7;
	} else {
		goto BB5;
	}
BB5: // 1
	_20_t17 = 10;
	_20_t0 = _20_t17;
	goto BB6;
BB6: // 3
	retval = _20_t0;
	goto end;
BB7: // 1
	_20_t8 = 3;
	_20_t9 = _21_x - _20_t8;
	_20_t10 = 1;
	_20_t11 = _20_t9 == _20_t10;
	if (!_20_t11) {
		goto BB17;
	} else {
		goto BB8;
	}
BB8: // 1
	_20_t7 = 1;
	goto BB9;
BB9: // 2
	if (!_20_t7) {
		goto BB12;
	} else {
		goto BB11;
	}
BB11: // 1
	_20_t18 = 23;
	_20_t0 = _20_t18;
	goto BB6;
BB12: // 1
	_20_t13 = 2;
	_20_t14 = _21_x - _20_t13;
	_20_t15 = 1;
	_20_t16 = _20_t14 == _20_t15;
	if (!_20_t16) {
		goto BB16;
	} else {
		goto BB13;
	}
BB13: // 1
	_20_t12 = 1;
	goto BB15;
BB15: // 2
	_20_t19 = 10;
	_20_t0 = _20_t19;
	goto BB6;
BB16: // 1
	_20_t12 = 0;
	goto BB15;
BB17: // 1
	_20_t7 = 0;
	goto BB9;
BB18: // 1
	_20_t2 = 0;
	goto BB3;
end:
	return retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
