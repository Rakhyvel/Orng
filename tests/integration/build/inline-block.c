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
	int _76_x;
	int _1;
	int _2;
BB0:;
	_0 = 13;
	_76_x = _0;
	_1 = 2;
	_2 = _76_x * _1;
	_76_x = _2;
	retval = _76_x;
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
