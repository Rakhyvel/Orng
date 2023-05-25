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
	int64_t _107_t2;
	int64_t _107_t3;
	uint8_t _107_t4;
	uint8_t _107_t1;
	int64_t _107_t13;
	int64_t _107_t0;
	int64_t _0;
	int64_t _107_t6;
	int64_t _107_t7;
	uint8_t _107_t8;
	uint8_t _107_t5;
	int64_t _107_t14;
	int64_t _107_t10;
	int64_t _107_t11;
	uint8_t _107_t12;
	uint8_t _107_t9;
	int64_t _107_t15;
	int64_t _107_t16;
BB1: // 1
	_107_t2 = 0;
	_107_t3 = 1;
	_107_t4 = 0;
	_107_t1 = 0;
	if (!_107_t1) {
		goto BB7;
	} else {
		goto BB5;
	}
BB5: // 1
	_107_t13 = 5;
	_107_t0 = 5;
	goto BB6;
BB6: // 4
	retval = _107_t0;
	goto end;
BB7: // 1
	_107_t6 = 0;
	_107_t7 = 1;
	_107_t8 = 0;
	_107_t5 = 0;
	if (!_107_t5) {
		goto BB12;
	} else {
		goto BB11;
	}
BB11: // 1
	_107_t14 = 10;
	_107_t0 = 10;
	goto BB6;
BB12: // 1
	_107_t10 = 0;
	_107_t11 = 1;
	_107_t12 = 0;
	_107_t9 = 0;
	if (!_107_t9) {
		goto BB18;
	} else {
		goto BB16;
	}
BB16: // 1
	_107_t15 = 25;
	_107_t0 = 25;
	goto BB6;
BB18: // 1
	_107_t16 = 10;
	_107_t0 = 10;
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
