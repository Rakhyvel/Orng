/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684711326
#define ORNG_1684711326

#include <math.h>
#include <stdio.h>

/* Function Definitions */
int test_main();

int test_main() {
	// Bookkeeping
	int retval;
	int _0;
	int _1;
	int _25_x;
	int _2;
	int _3;
	int _4;
	int _5;
	int _6;
	int _7;
	int _8;
BB0:;
	_1 = 0;
	_25_x = _1;
	goto BB1;
BB1:;
	_3 = 10;
	_4 = _25_x < _3;
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
	_6 = _25_x + _5;
	_25_x = _6;
	_0 = _25_x;
	_7 = 1;
	_8 = _25_x + _7;
	_25_x = _8;
	goto BB1;
BB5:;
	_0 = _25_x;
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
