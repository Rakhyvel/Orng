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
	int _121_x;
	int _1;
	int _2;
	int _122_i;
	int _3;
	int _4;
	int _5;
	int _6;
	int _7;
	int _8;
BB0:;
	_0 = 0;
	_121_x = _0;
	_2 = 0;
	_122_i = _2;
	goto BB1;
BB1:;
	_4 = 10;
	_5 = _122_i <= _4;
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
	_6 = _121_x + _122_i;
	_121_x = _6;
	_1 = _121_x;
	_7 = 1;
	_8 = _122_i + _7;
	_122_i = _8;
	goto BB1;
BB5:;
	goto BB6;
BB6:;
	retval = _121_x;
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
