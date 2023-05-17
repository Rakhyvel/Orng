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
	int tests_integration_while_x_0;
	int _1;
	int _2;
	int tests_integration_while_i_0;
	int _3;
	int _4;
	int _5;
	int tests_integration_while_i_2;
	int tests_integration_while_x_2;
	int tests_integration_while_x_3;
	int tests_integration_while_i_3;
	int tests_integration_while_x_4;
	int tests_integration_while_i_4;
	int _6;
	int tests_integration_while_x_1;
	int _7;
	int _8;
	int tests_integration_while_i_1;
	int tests_integration_while_x_5;
	int tests_integration_while_i_5;
	int tests_integration_while_x_6;
	int tests_integration_while_x_7;
	int tests_integration_while_x_8;
	int tests_integration_while_i_6;
BB0:;
	_0 = 0;
	tests_integration_while_x_0 = _0;
	_2 = 0;
	tests_integration_while_i_0 = _2;
	tests_integration_while_i_2 = tests_integration_while_i_0;
	tests_integration_while_x_2 = tests_integration_while_x_0;
	goto BB1;
BB1:;
	_4 = 10;
	_5 = tests_integration_while_i_2 <= _4;
	if (!_5) {
		tests_integration_while_x_8 = tests_integration_while_x_2;
		tests_integration_while_i_6 = tests_integration_while_i_2;
		goto BB7;
	} else {
		tests_integration_while_x_3 = tests_integration_while_x_2;
		tests_integration_while_i_3 = tests_integration_while_i_2;
		goto BB2;
	}
BB2:;
	_3 = 1;
	tests_integration_while_x_4 = tests_integration_while_x_3;
	tests_integration_while_i_4 = tests_integration_while_i_3;
	goto BB3;
BB3:;
	if (!_3) {
		tests_integration_while_x_6 = tests_integration_while_x_4;
		goto BB5;
	} else {
		tests_integration_while_x_5 = tests_integration_while_x_4;
		tests_integration_while_i_5 = tests_integration_while_i_4;
		goto BB4;
	}
BB4:;
	_6 = tests_integration_while_x_5 + tests_integration_while_i_5;
	tests_integration_while_x_1 = _6;
	_1 = tests_integration_while_x_1;
	_7 = 1;
	_8 = tests_integration_while_i_5 + _7;
	tests_integration_while_i_1 = _8;
	tests_integration_while_i_2 = tests_integration_while_i_1;
	tests_integration_while_x_2 = tests_integration_while_x_1;
	goto BB1;
BB5:;
	tests_integration_while_x_7 = tests_integration_while_x_6;
	goto BB6;
BB6:;
	retval = tests_integration_while_x_7;
	goto end;
BB7:;
	_3 = 0;
	tests_integration_while_x_4 = tests_integration_while_x_8;
	tests_integration_while_i_4 = tests_integration_while_i_6;
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
