/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684712155
#define ORNG_1684712155

#include <math.h>
#include <stdio.h>

/* Function Definitions */
int test_main();

int test_main() {
	// Bookkeeping
	int retval;
	int _0;
	int _84_found;
	int _1;
	int _2;
	int _85_n;
	int _3;
	int _4;
	int _5;
	int _6;
	int _7;
	int _8;
	int _9;
	int _10;
	int _11;
	int _12;
	int _13;
	int _14;
	int _15;
	int _16;
	int _17;
BB0:;
	_0 = 0;
	_84_found = _0;
	_2 = 0;
	_85_n = _2;
	goto BB1;
BB1:;
	_4 = 10;
	_5 = _85_n < _4;
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
	if (!_84_found) {
		goto BB13;
	} else {
		goto BB5;
	}
BB5:;
	_7 = 10;
	_85_n = _7;
	_6 = _85_n;
	goto BB6;
BB6:;
	_10 = 6;
	_11 = _85_n == _10;
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
	_84_found = _12;
	_8 = _84_found;
	goto BB10;
BB10:;
	_1 = _8;
	_13 = 1;
	_14 = _85_n + _13;
	_85_n = _14;
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
	if (!_84_found) {
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
