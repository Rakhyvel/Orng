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
	int _53_x;
	int _1;
	int _2;
BB0:;
	_0 = 4;
	_53_x = _0;
	_1 = 6;
	_2 = _53_x + _1;
	_53_x = _2;
	retval = _53_x;
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
