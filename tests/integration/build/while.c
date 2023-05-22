/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684721444
#define ORNG_1684721444

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	// Bookkeeping
	int retval;
	int64_t _0;
	int64_t _133_x;
	int64_t _2;
	int64_t _134_i;
	uint8_t _3;
	int64_t _4;
	uint8_t _5;
	int64_t _6;
	int64_t _7;
	int64_t _8;
BB0:;
	_0 = 0;
	_133_x = _0;
	_2 = 0;
	_134_i = _2;
	goto BB1;
BB1:;
	_4 = 10;
	_5 = _134_i <= _4;
	if (!_5) {
		goto BB7;
	} else {
		goto BB2;
	}
BB2:;
	_3 = 1;
	goto BB3;
BB3:;
	if (!_3) {
		goto BB5;
	} else {
		goto BB4;
	}
BB4:;
	_6 = _133_x + _134_i;
	_133_x = _6;
_133_x;
	_7 = 1;
	_8 = _134_i + _7;
	_134_i = _8;
	goto BB1;
BB5:;
	goto BB6;
BB6:;
	retval = _133_x;
	goto end;
BB7:;
	_3 = 0;
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
