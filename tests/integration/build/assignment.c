/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684711326
#define ORNG_1684711326

#include <math.h>
#include <stdio.h>

/* Function Definitions */
int test_main();

int test_main() {
	// Bookkeeping
	int retval;
	int _0;
	int _49_x;
	int _1;
	int _2;
BB0:;
	_0 = 4;
	_49_x = _0;
	_1 = 6;
	_2 = _49_x + _1;
	_49_x = _2;
	retval = _49_x;
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
