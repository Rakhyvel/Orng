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
	int64_t _31_t1;
	int64_t _33_x;
	int64_t _31_t3;
	uint8_t _31_t4;
	uint8_t _31_t2;
	int64_t _31_t5;
	int64_t _31_t6;
	int64_t _31_t7;
	int64_t _31_t0;
	int64_t _31_t8;
	int64_t _31_t9;
	int64_t _0;
BB0: // 1
	_31_t1 = 0;
	_33_x = _31_t1;
	goto BB1;
BB1: // 2
	_31_t3 = 10;
	_31_t4 = _33_x < _31_t3;
	if (!_31_t4) {
		goto BB7;
	} else {
		goto BB2;
	}
BB2: // 1
	_31_t2 = 1;
	goto BB3;
BB3: // 2
	if (!_31_t2) {
		goto BB5;
	} else {
		goto BB4;
	}
BB4: // 1
	_31_t5 = 1;
	_31_t6 = _33_x + _31_t5;
	_33_x = _31_t6;
	_31_t7 = 0;
	_31_t0 = _31_t7;
	_31_t8 = 1;
	_31_t9 = _33_x + _31_t8;
	_33_x = _31_t9;
	goto BB1;
BB5: // 1
	_31_t0 = _33_x;
	goto BB6;
BB6: // 1
	retval = _31_t0;
	goto end;
BB7: // 1
	_31_t2 = 0;
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
