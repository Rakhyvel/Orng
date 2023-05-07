/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1683494789
#define ORNG_1683494789

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
BB0:;
	_1 = 4;
	test_x_0 = _1;
	_2 = 1;
	if (!_2) {
		goto BB3;
	} else {
		goto BB1;
	}
BB1:;
	_3 = 7;
	_4 = test_x_0 + _3;
	_0 = _4;
	goto BB2;
BB2:;
	retval = _0;
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
