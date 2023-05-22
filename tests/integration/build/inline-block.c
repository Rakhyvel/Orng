/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684721444
#define ORNG_1684721444

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	// Bookkeeping
	int retval;
	int64_t _0;
	int64_t _80_x;
	int64_t _1;
	int64_t _2;
BB0:;
	_0 = 13;
	_80_x = _0;
	_1 = 2;
	_2 = _80_x * _1;
	_80_x = _2;
	retval = _80_x;
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
