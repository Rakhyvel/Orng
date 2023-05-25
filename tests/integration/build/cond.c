/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684986347
#define ORNG_1684986347

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
	_67_t4 = 0;
	_67_t1 = 0;
	if (!_67_t1) {
		goto BB7;
	} else {
		goto BB5;
	}
BB5: // 1
	_67_t13 = 5;
	_67_t0 = 5;
	goto BB6;
BB6: // 3
	retval = _67_t0;
	goto end;
BB7: // 1
	_67_t6 = 1;
	_67_t7 = 1;
	_67_t8 = 1;
	_67_t5 = 1;
	if (!_67_t5) {
		goto BB12;
	} else {
		goto BB11;
	}
BB11: // 1
	_67_t14 = 10;
	_67_t0 = 10;
	goto BB6;
BB12: // 1
	_67_t10 = 2;
	_67_t11 = 1;
	_67_t12 = 0;
	_67_t9 = 0;
	_67_t15 = 25;
	_67_t0 = 25;
	goto BB6;
end:
	return retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
