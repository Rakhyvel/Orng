/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684206169
#define ORNG_1684206169

#include <math.h>
#include <stdio.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int _0;
	int _1;
	int tests_integration_if_else_x_0;
	int _2;
	int _3;
	int _4;
	int tests_integration_if_else_x_1;
	int _5;
	int _6;
	int tests_integration_if_else_x_2;
BB0:;
	_1 = 4;
	tests_integration_if_else_x_0 = _1;
	_2 = 0;
	if (!_2) {
		tests_integration_if_else_x_2 = tests_integration_if_else_x_0;
		goto BB3;
	} else {
		tests_integration_if_else_x_1 = tests_integration_if_else_x_0;
		goto BB1;
	}
BB1:;
	_3 = 3;
	_4 = tests_integration_if_else_x_1 + _3;
	_0 = _4;
	goto BB2;
BB2:;
	retval = _0;
	goto end;
BB3:;
	_5 = 7;
	_6 = tests_integration_if_else_x_2 + _5;
	_0 = _6;
	goto BB2;
end:
	return retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
