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
	int tests_integration_cond_let_x_0;
	int _2;
	int _3;
	int _4;
	int _5;
	int _6;
	int tests_integration_cond_let_x_1;
	int tests_integration_cond_let_x_2;
	int tests_integration_cond_let_x_3;
	int _17;
	int _7;
	int _8;
	int _9;
	int _10;
	int _11;
	int tests_integration_cond_let_x_4;
	int tests_integration_cond_let_x_5;
	int tests_integration_cond_let_x_6;
	int _18;
	int _12;
	int _13;
	int _14;
	int _15;
	int _16;
	int tests_integration_cond_let_x_7;
	int _19;
	int tests_integration_cond_let_x_8;
	int tests_integration_cond_let_x_9;
BB0:;
	_1 = 4;
	tests_integration_cond_let_x_0 = _1;
	tests_integration_cond_let_x_1 = tests_integration_cond_let_x_0;
	goto BB1;
BB1:;
	_3 = 4;
	_4 = tests_integration_cond_let_x_1 - _3;
	_5 = 1;
	_6 = _4 == _5;
	if (!_6) {
		tests_integration_cond_let_x_9 = tests_integration_cond_let_x_1;
		goto BB18;
	} else {
		tests_integration_cond_let_x_2 = tests_integration_cond_let_x_1;
		goto BB2;
	}
BB2:;
	_2 = 1;
	tests_integration_cond_let_x_3 = tests_integration_cond_let_x_2;
	goto BB3;
BB3:;
	if (!_2) {
		tests_integration_cond_let_x_4 = tests_integration_cond_let_x_3;
		goto BB7;
	} else {
		goto BB4;
	}
BB4:;
	goto BB5;
BB5:;
	_17 = 10;
	_0 = _17;
	goto BB6;
BB6:;
	retval = _0;
	goto end;
BB7:;
	_8 = 3;
	_9 = tests_integration_cond_let_x_4 - _8;
	_10 = 1;
	_11 = _9 == _10;
	if (!_11) {
		tests_integration_cond_let_x_8 = tests_integration_cond_let_x_4;
		goto BB17;
	} else {
		tests_integration_cond_let_x_5 = tests_integration_cond_let_x_4;
		goto BB8;
	}
BB8:;
	_7 = 1;
	tests_integration_cond_let_x_6 = tests_integration_cond_let_x_5;
	goto BB9;
BB9:;
	if (!_7) {
		tests_integration_cond_let_x_7 = tests_integration_cond_let_x_6;
		goto BB12;
	} else {
		goto BB10;
	}
BB10:;
	goto BB11;
BB11:;
	_18 = 23;
	_0 = _18;
	goto BB6;
BB12:;
	_13 = 2;
	_14 = tests_integration_cond_let_x_7 - _13;
	_15 = 1;
	_16 = _14 == _15;
	if (!_16) {
		goto BB16;
	} else {
		goto BB13;
	}
BB13:;
	_12 = 1;
	goto BB14;
BB14:;
	goto BB15;
BB15:;
	_19 = 10;
	_0 = _19;
	goto BB6;
BB16:;
	_12 = 0;
	goto BB14;
BB17:;
	_7 = 0;
	tests_integration_cond_let_x_6 = tests_integration_cond_let_x_8;
	goto BB9;
BB18:;
	_2 = 0;
	tests_integration_cond_let_x_3 = tests_integration_cond_let_x_9;
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
