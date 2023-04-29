/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1682807831
#define ORNG_1682807831

#include <math.h>
#include <stdio.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int _0;
	int test_x_0;
	int _1;
	int _2;
	int _3;
	int _4;
	int _5;
BB0:;
	_0 = 4;
	test_x_0 = _0;
	_2 = 0;
	_3 = _2 < test_x_0;
	if (!_3) {
		goto BB4;
	} else {
		goto BB1;
	}
BB1:;
	_4 = 3;
	_5 = test_x_0 <= _4;
	if (!_5) {
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
  printf("%d", test_main());
  return 0;
}

#endif
