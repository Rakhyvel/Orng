/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684291386
#define ORNG_1684291386

#include <math.h>
#include <stdio.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int _0;
	int _1;
	int tests_integration_while_else_x_0;
	int _2;
	int _3;
	int _4;
	int tests_integration_while_else_x_3;
	int tests_integration_while_else_x_4;
	int tests_integration_while_else_x_5;
	int _5;
	int _6;
	int tests_integration_while_else_x_1;
	int _7;
	int _8;
	int tests_integration_while_else_x_2;
	int tests_integration_while_else_x_6;
	int tests_integration_while_else_x_7;
	int tests_integration_while_else_x_8;
BB0:;
	_1 = 0;
	tests_integration_while_else_x_0 = _1;
	tests_integration_while_else_x_3 = tests_integration_while_else_x_0;
	goto BB1;
BB1:;
	_3 = 10;
	_4 = tests_integration_while_else_x_3 < _3;
	if (!_4) {
		tests_integration_while_else_x_8 = tests_integration_while_else_x_3;
		goto BB7;
	} else {
		tests_integration_while_else_x_4 = tests_integration_while_else_x_3;
		goto BB2;
	}
BB2:;
	_2 = 1;
	tests_integration_while_else_x_5 = tests_integration_while_else_x_4;
	goto BB3;
BB3:;
	if (!_2) {
		tests_integration_while_else_x_7 = tests_integration_while_else_x_5;
		goto BB5;
	} else {
		tests_integration_while_else_x_6 = tests_integration_while_else_x_5;
		goto BB4;
	}
BB4:;
	_5 = 1;
	_6 = tests_integration_while_else_x_6 + _5;
	tests_integration_while_else_x_1 = _6;
	_0 = tests_integration_while_else_x_1;
	_7 = 1;
	_8 = tests_integration_while_else_x_1 + _7;
	tests_integration_while_else_x_2 = _8;
	tests_integration_while_else_x_3 = tests_integration_while_else_x_2;
	goto BB1;
BB5:;
	_0 = tests_integration_while_else_x_7;
	goto BB6;
BB6:;
	retval = _0;
	goto end;
BB7:;
	_2 = 0;
	tests_integration_while_else_x_5 = tests_integration_while_else_x_8;
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
