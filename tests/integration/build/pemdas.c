/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1682742299
#define ORNG_1682742299

#include <math.h>
#include <stdio.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int _0;
	int _1;
	int _2;
	int _3;
	int _4;
	int _5;
	int _6;
BB0:;
	_0 = 4;
	_1 = 7;
	_2 = _0 + _1;
	_3 = 2;
	_4 = _2 * _3;
	_5 = 3;
	_6 = _4 - _5;
	retval = _6;
	goto end;
end:
	return retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
