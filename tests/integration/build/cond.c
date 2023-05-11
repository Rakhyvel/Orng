/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1683775670
#define ORNG_1683775670

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
	_2 = 1;
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
	_3 = 2;
	goto BB9;
BB9:;
	_6 = 25;
	_0 = _6;
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
