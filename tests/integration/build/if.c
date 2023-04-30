/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1682818350
#define ORNG_1682818350

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
	_5 = 11;
	retval = _5;
	goto end;
BB3:;
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
