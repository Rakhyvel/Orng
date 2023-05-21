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
	int _1;
	int _13_x;
	int _2;
	int _3;
	int _4;
	int _5;
	int _6;
	int _17;
	int _7;
	int _8;
	int _9;
	int _10;
	int _11;
	int _18;
	int _12;
	int _13;
	int _14;
	int _15;
	int _16;
	int _19;
BB0:;
	_1 = 4;
	_13_x = _1;
	goto BB1;
BB1:;
	_3 = 4;
	_4 = _13_x - _3;
	_5 = 1;
	_6 = _4 == _5;
	if (!_6) {
		goto BB18;
	} else {
		goto BB2;
	}
BB2:;
	_2 = 1;
	goto BB3;
BB3:;
	if (!_2) {
		goto BB7;
	} else {
		goto BB4;
	}
BB4:;
	goto BB5;
BB5:;
	_17 = 10;
	_0 = _17;
	goto BB6;
BB6:;
	retval = _0;
	goto end;
BB7:;
	_8 = 3;
	_9 = _13_x - _8;
	_10 = 1;
	_11 = _9 == _10;
	if (!_11) {
		goto BB17;
	} else {
		goto BB8;
	}
BB8:;
	_7 = 1;
	goto BB9;
BB9:;
	if (!_7) {
		goto BB12;
	} else {
		goto BB10;
	}
BB10:;
	goto BB11;
BB11:;
	_18 = 23;
	_0 = _18;
	goto BB6;
BB12:;
	_13 = 2;
	_14 = _13_x - _13;
	_15 = 1;
	_16 = _14 == _15;
	if (!_16) {
		goto BB16;
	} else {
		goto BB13;
	}
BB13:;
	_12 = 1;
	goto BB14;
BB14:;
	goto BB15;
BB15:;
	_19 = 10;
	_0 = _19;
	goto BB6;
BB16:;
	_12 = 0;
	goto BB14;
BB17:;
	_7 = 0;
	goto BB9;
BB18:;
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
