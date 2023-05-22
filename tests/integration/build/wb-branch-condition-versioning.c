/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684727983
#define ORNG_1684727983

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	uint8_t _0;
	uint8_t _95_found;
	int64_t _2;
	int64_t _96_n;
	uint8_t _3;
	int64_t _4;
	uint8_t _5;
	int64_t _7;
	uint8_t _9;
	int64_t _10;
	uint8_t _11;
	uint8_t _12;
	int64_t _13;
	int64_t _14;
	int64_t _15;
	int64_t _16;
	int64_t _17;
BB0:;
	_0 = 0;
	_95_found = _0;
	_2 = 0;
	_96_n = _2;
	goto BB1;
BB1:;
	_4 = 10;
	_5 = _96_n < _4;
	if (!_5) {
		goto BB19;
	} else {
		goto BB2;
	}
BB2:;
	_3 = 1;
	goto BB3;
BB3:;
	if (!_3) {
		goto BB14;
	} else {
		goto BB4;
	}
BB4:;
	if (!_95_found) {
		goto BB13;
	} else {
		goto BB5;
	}
BB5:;
	_7 = 10;
	_96_n = _7;
_96_n;
	goto BB6;
BB6:;
	_10 = 6;
	_11 = _96_n == _10;
	if (!_11) {
		goto BB12;
	} else {
		goto BB7;
	}
BB7:;
	_9 = 1;
	goto BB8;
BB8:;
	if (!_9) {
		goto BB11;
	} else {
		goto BB9;
	}
BB9:;
	_12 = 1;
	_95_found = _12;
_95_found;
	goto BB10;
BB10:;
;
	_13 = 1;
	_14 = _96_n + _13;
	_96_n = _14;
	goto BB1;
BB11:;
	goto BB10;
BB12:;
	_9 = 0;
	goto BB8;
BB13:;
	goto BB6;
BB14:;
	goto BB15;
BB15:;
	if (!_95_found) {
		goto BB18;
	} else {
		goto BB16;
	}
BB16:;
	_16 = 15;
	_15 = _16;
	goto BB17;
BB17:;
	retval = _15;
	goto end;
BB18:;
	_17 = 4;
	_15 = _17;
	goto BB17;
BB19:;
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
