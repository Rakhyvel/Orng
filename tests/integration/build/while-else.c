/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684807658
#define ORNG_1684807658

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int64_t _0;
	int64_t _1;
	int64_t _33_x;
	uint8_t _2;
	int64_t _3;
	uint8_t _4;
	int64_t _5;
	int64_t _6;
	int64_t _7;
	int64_t _8;
	int64_t _9;
BB0:;
	_1 = 0;
	_33_x = _1;
	goto BB1;
BB1:;
	_3 = 10;
	_4 = _33_x < _3;
	if (!_4) {
		goto BB7;
	} else {
		goto BB2;
	}
BB2:;
	_2 = 1;
	goto BB3;
BB3:;
	if (!_2) {
		goto BB5;
	} else {
		goto BB4;
	}
BB4:;
	_5 = 1;
	_6 = _33_x + _5;
	_33_x = _6;
	_7 = 0;
	_0 = _7;
	_8 = 1;
	_9 = _33_x + _8;
	_33_x = _9;
	goto BB1;
BB5:;
	_0 = _33_x;
	goto BB6;
BB6:;
	retval = _0;
	goto end;
BB7:;
	_2 = 0;
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
