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
	int _4;
	int _2;
	int _3;
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
	goto BB4;
BB4:;
	_4 = 25;
	retval = _4;
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
	goto BB4;
BB8:;
	_3 = 1;
	if (!_3) {
		goto BB11;
	} else {
		goto BB9;
	}
BB9:;
	goto BB10;
BB10:;
	goto BB4;
BB11:;
	goto BB12;
BB12:;
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
