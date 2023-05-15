/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684109452
#define ORNG_1684109452

#include <math.h>
#include <stdio.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int _0;
	int _1;
	int _2;
	int _3;
	int _4;
	int _13;
	int _5;
	int _6;
	int _7;
	int _8;
	int _14;
	int _9;
	int _10;
	int _11;
	int _12;
	int _15;
BB0:;
	goto BB1;
BB1:;
	_2 = 0;
	_3 = 1;
	_4 = _2 == _3;
	if (!_4) {
		goto BB18;
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
	_6 = 1;
	_7 = 1;
	_8 = _6 == _7;
	if (!_8) {
		goto BB17;
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
	_10 = 2;
	_11 = 1;
	_12 = _10 == _11;
	if (!_12) {
		goto BB16;
	} else {
		goto BB13;
	}
BB13:;
	_9 = 1;
	goto BB14;
BB14:;
	goto BB15;
BB15:;
	_15 = 25;
	_0 = _15;
	goto BB6;
BB16:;
	_9 = 0;
	goto BB14;
BB17:;
	_5 = 0;
	goto BB9;
BB18:;
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
