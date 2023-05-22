/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684713966
#define ORNG_1684713966

#include <math.h>
#include <stdio.h>

/* Function Definitions */
int test_main();

int test_main() {
	// Bookkeeping
	int retval;
	int _0;
	int _1;
	int _2;
	int _3_x;
BB0:;
	_0 = 20;
	_1 = 7;
	_2 = _0 + _1;
	_3_x = _2;
	retval = _3_x;
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
