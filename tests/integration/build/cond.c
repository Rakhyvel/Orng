/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684895482
#define ORNG_1684895482

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int64_t _67_t2;
	int64_t _67_t3;
	uint8_t _67_t4;
	uint8_t _67_t1;
	int64_t _67_t13;
	int64_t _67_t0;
	int64_t _0;
	int64_t _67_t6;
	int64_t _67_t7;
	uint8_t _67_t8;
	uint8_t _67_t5;
	int64_t _67_t14;
	int64_t _67_t10;
	int64_t _67_t11;
	uint8_t _67_t12;
	uint8_t _67_t9;
	int64_t _67_t15;
BB1: // 1
	_67_t2 = 0;
	_67_t3 = 1;
	_67_t4 = _67_t2 == _67_t3;
	if (!_67_t4) {
		goto BB18;
	} else {
		goto BB2;
	}
BB2: // 1
	_67_t1 = 1;
	goto BB3;
BB3: // 2
	if (!_67_t1) {
		goto BB7;
	} else {
		goto BB5;
	}
BB5: // 1
	_67_t13 = 5;
	_67_t0 = _67_t13;
	goto BB6;
BB6: // 3
	retval = _67_t0;
	goto end;
BB7: // 1
	_67_t6 = 1;
	_67_t7 = 1;
	_67_t8 = _67_t6 == _67_t7;
	if (!_67_t8) {
		goto BB17;
	} else {
		goto BB8;
	}
BB8: // 1
	_67_t5 = 1;
	goto BB9;
BB9: // 2
	if (!_67_t5) {
		goto BB12;
	} else {
		goto BB11;
	}
BB11: // 1
	_67_t14 = 10;
	_67_t0 = _67_t14;
	goto BB6;
BB12: // 1
	_67_t10 = 2;
	_67_t11 = 1;
	_67_t12 = _67_t10 == _67_t11;
	if (!_67_t12) {
		goto BB16;
	} else {
		goto BB13;
	}
BB13: // 1
	_67_t9 = 1;
	goto BB15;
BB15: // 2
	_67_t15 = 25;
	_67_t0 = _67_t15;
	goto BB6;
BB16: // 1
	_67_t9 = 0;
	goto BB15;
BB17: // 1
	_67_t5 = 0;
	goto BB9;
BB18: // 1
	_67_t1 = 0;
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
