/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1683945866
#define ORNG_1683945866

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
BB0:;
	_0 = 3;
	_1 = 2;
	_2 = powf(_1, _0);
	_3 = 2;
	_4 = powf(_3, _2);
	_5 = -_4;
	retval = _5;
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
