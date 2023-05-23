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
	uint8_t _1;
	int64_t _2;
	int64_t _3;
	uint8_t _4;
	int64_t _13;
	uint8_t _5;
	int64_t _6;
	int64_t _7;
	uint8_t _8;
	int64_t _14;
	uint8_t _9;
	int64_t _10;
	int64_t _11;
	uint8_t _12;
	int64_t _15;
	int64_t _16;
BB0:;
	goto BB1;
BB1:;
	_2 = 0;
	_3 = 1;
	_4 = _2 == _3;
	if (!_4) {
		goto BB21;
	} else {
		goto BB2;
	}
BB2:;
	_1 = 1;
	goto BB3;
BB3:;
	if (!_1) {
		goto BB7;
	} else {
		goto BB4;
	}
BB4:;
	goto BB5;
BB5:;
	_13 = 5;
	_0 = _13;
	goto BB6;
BB6:;
	retval = _0;
	goto end;
BB7:;
	_6 = 0;
	_7 = 1;
	_8 = _6 == _7;
	if (!_8) {
		goto BB20;
	} else {
		goto BB8;
	}
BB8:;
	_5 = 1;
	goto BB9;
BB9:;
	if (!_5) {
		goto BB12;
	} else {
		goto BB10;
	}
BB10:;
	goto BB11;
BB11:;
	_14 = 10;
	_0 = _14;
	goto BB6;
BB12:;
	_10 = 0;
	_11 = 1;
	_12 = _10 == _11;
	if (!_12) {
		goto BB19;
	} else {
		goto BB13;
	}
BB13:;
	_9 = 1;
	goto BB14;
BB14:;
	if (!_9) {
		goto BB17;
	} else {
		goto BB15;
	}
BB15:;
	goto BB16;
BB16:;
	_15 = 25;
	_0 = _15;
	goto BB6;
BB17:;
	goto BB18;
BB18:;
	_16 = 10;
	_0 = _16;
	goto BB6;
BB19:;
	_9 = 0;
	goto BB14;
BB20:;
	_5 = 0;
	goto BB9;
BB21:;
	_1 = 0;
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
