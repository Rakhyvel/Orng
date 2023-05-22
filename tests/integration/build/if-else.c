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
	int64_t _1;
	int64_t _61_x;
	uint8_t _2;
	int64_t _3;
	int64_t _4;
	int64_t _5;
	int64_t _6;
BB0:;
	_1 = 4;
	_61_x = _1;
	_2 = 0;
	if (!_2) {
		goto BB3;
	} else {
		goto BB1;
	}
BB1:;
	_3 = 3;
	_4 = _61_x + _3;
	_0 = _4;
	goto BB2;
BB2:;
	retval = _0;
	goto end;
BB3:;
	_5 = 7;
	_6 = _61_x + _5;
	_0 = _6;
	goto BB2;
end:
	return retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
