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
	int64_t _25_x;
	int64_t* _1;
	int64_t* _25_y;
	int64_t _2;
	int64_t _3;
BB0:;
	_0 = 4;
	_25_x = _0;
	_1 = &_25_x;
	_25_y = _1;
	_2 = 28;
	*_25_y = _2;
	_3 = *_25_y;
	retval = _3;
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
