/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684718682
#define ORNG_1684718682

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	// Bookkeeping
	int retval;
	int64_t _0;
	int64_t _3_x;
	int64_t* _1;
	int64_t* _3_y;
	int64_t _2;
	int64_t _3;
BB0:;
	_0 = 4;
	_3_x = _0;
	_1 = &_3_x;
	_3_y = _1;
	_2 = 28;
	*_3_y = _2;
	_3 = *_3_y;
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
