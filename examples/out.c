/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1682308033
#define ORNG_1682308033

#include <math.h>
#include <stdio.h>

/* Function Definitions */
int main();

int test_main() {
	int retval;
	int _0;
	int x_0;
	int _1;
	int _2;
	int _3;
	int _4;
	int _5;
	int _6;
	int _7;
BB0:;
	_0 = 26;
	x_0 = _0;
	_2 = 0;
	_3 = _2 < x_0;
	if (!_3) {
		goto BB4;
	} else {
		goto BB1;
	}
BB1:;
	_4 = 5;
	_5 = 2;
	_6 = powf(_4, _5);
	_7 = x_0 <= _6;
	if (!_7) {
		goto BB4;
	} else {
		goto BB2;
	}
BB2:;
	_1 = 1;
	goto BB3;
BB3:;
	retval = _1;
	goto end;
BB4:;
	_1 = 0;
	goto BB3;
end:
	return retval;
}

int main()
{
  printf("Result: %d\n", test_main());
  return 0;
}

#endif
