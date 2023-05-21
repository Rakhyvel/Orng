/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684712155
#define ORNG_1684712155

#include <math.h>
#include <stdio.h>

/* Function Definitions */
int test_main();

int test_main() {
	// Bookkeeping
	int retval;
	int _0;
	int _72_x;
	int _1;
	int _2;
BB0:;
	_0 = 13;
	_72_x = _0;
	_1 = 2;
	_2 = _72_x * _1;
	_72_x = _2;
	retval = _72_x;
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
