/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1682302859
#define ORNG_1682302859

#include <math.h>

/* Function Definitions */
int main();

int test_main() {
	int retval;
	int _0;
	int _1;
	int _2;
	int _3;
	int _4;
BB0:;
	_2 = 0;
	if (!_2) {
		goto BB6;
	} else {
		goto BB1;
	}
BB1:;
	_3 = 354;
	_1 = _3;
	goto BB2;
BB2:;
	if (!_1) {
		goto BB5;
	} else {
		goto BB3;
	}
BB3:;
	_0 = 1;
	goto BB4;
BB4:;
	retval = _0;
	goto end;
BB5:;
	_4 = 0;
	_0 = _4;
	goto BB4;
BB6:;
	_1 = 0;
	goto BB2;
end:
	return retval;
}

int main()
{
  printf("Result: %d", test_main());
  return 0;
}

#endif
