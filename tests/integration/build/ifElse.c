/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1682815338
#define ORNG_1682815338

#include <math.h>
#include <stdio.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int _0;
	int _1;
	int test_x_0;
	int _2;
	int _3;
	int _4;
	int _5;
	int _6;
BB0:;
	_1 = 4;
	test_x_0 = _1;
	_2 = 0;
	if (!_2) {
		goto BB3;
	} else {
		goto BB1;
	}
BB1:;
	_3 = 3;
	_4 = test_x_0 + _3;
	_0 = _4;
	goto BB2;
BB2:;
	retval = _0;
	goto end;
BB3:;
	_5 = 7;
	_6 = test_x_0 + _5;
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
