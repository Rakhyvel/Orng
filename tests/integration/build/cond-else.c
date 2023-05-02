/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1682995710
#define ORNG_1682995710

#include <math.h>
#include <stdio.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int _0;
	int _1;
	int _4;
	int _2;
	int _5;
	int _3;
	int _6;
	int _7;
BB0:;
	goto BB1;
BB1:;
	_1 = 0;
	if (!_1) {
		goto BB5;
	} else {
		goto BB2;
	}
BB2:;
	goto BB3;
BB3:;
	_4 = 5;
	_0 = _4;
	goto BB4;
BB4:;
	retval = _0;
	goto end;
BB5:;
	_2 = 0;
	if (!_2) {
		goto BB8;
	} else {
		goto BB6;
	}
BB6:;
	goto BB7;
BB7:;
	_5 = 10;
	_0 = _5;
	goto BB4;
BB8:;
	_3 = 0;
	if (!_3) {
		goto BB11;
	} else {
		goto BB9;
	}
BB9:;
	goto BB10;
BB10:;
	_6 = 25;
	_0 = _6;
	goto BB4;
BB11:;
	goto BB12;
BB12:;
	_7 = 10;
	_0 = _7;
	goto BB4;
end:
	return retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
