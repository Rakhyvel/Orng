/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684713966
#define ORNG_1684713966

#include <math.h>
#include <stdio.h>

/* Function Definitions */
int test_main();

int test_main() {
	// Bookkeeping
	int retval;
	int _0;
	int _13_x;
	int _1;
	int _2;
	int _3;
	int _4;
	int _5;
	int _6;
	int _7;
	int _8;
	int _9;
	int _10;
	int _11;
BB0:;
	_0 = 4.50005e+00;
	_13_x = _0;
	_2 = 0.0e+00;
	_3 = _2 < _13_x;
	if (!_3) {
		goto BB7;
	} else {
		goto BB1;
	}
BB1:;
	_4 = 3.0e+00;
	_5 = _13_x <= _4;
	if (!_5) {
		goto BB7;
	} else {
		goto BB2;
	}
BB2:;
	_6 = 3.0e+00;
	_7 = _4 == _6;
	if (!_7) {
		goto BB7;
	} else {
		goto BB3;
	}
BB3:;
	_8 = 2.0e+00;
	_9 = _6 > _8;
	if (!_9) {
		goto BB7;
	} else {
		goto BB4;
	}
BB4:;
	_10 = 1.0e+00;
	_11 = _8 >= _10;
	if (!_11) {
		goto BB7;
	} else {
		goto BB5;
	}
BB5:;
	_1 = 1;
	goto BB6;
BB6:;
	retval = _1;
	goto end;
BB7:;
	_1 = 0;
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
