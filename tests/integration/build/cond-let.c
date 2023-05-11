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
	int tests_integration_cond_let_x_0;
	int _2;
	int _3;
	int _8;
	int _4;
	int _5;
	int _9;
	int _6;
	int _7;
	int _10;
BB0:;
	_1 = 4;
	tests_integration_cond_let_x_0 = _1;
	goto BB1;
BB1:;
	_2 = 4;
	_3 = tests_integration_cond_let_x_0 - _2;
	if (!_3) {
		goto BB5;
	} else {
		goto BB2;
	}
BB2:;
	goto BB3;
BB3:;
	_8 = 10;
	_0 = _8;
	goto BB4;
BB4:;
	retval = _0;
	goto end;
BB5:;
	_4 = 3;
	_5 = tests_integration_cond_let_x_0 - _4;
	if (!_5) {
		goto BB8;
	} else {
		goto BB6;
	}
BB6:;
	goto BB7;
BB7:;
	_9 = 23;
	_0 = _9;
	goto BB4;
BB8:;
	_6 = 2;
	_7 = tests_integration_cond_let_x_0 - _6;
	goto BB9;
BB9:;
	_10 = 10;
	_0 = _10;
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
