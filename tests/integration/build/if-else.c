/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684895482
#define ORNG_1684895482

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int64_t _60_t1;
	int64_t _61_x;
	uint8_t _60_t2;
	int64_t _60_t3;
	int64_t _60_t4;
	int64_t _60_t0;
	int64_t _0;
	int64_t _60_t5;
	int64_t _60_t6;
BB0: // 1
	_60_t1 = 4;
	_61_x = _60_t1;
	_60_t2 = 0;
	if (!_60_t2) {
		goto BB3;
	} else {
		goto BB1;
	}
BB1: // 1
	_60_t3 = 3;
	_60_t4 = _61_x + _60_t3;
	_60_t0 = _60_t4;
	goto BB2;
BB2: // 2
	retval = _60_t0;
	goto end;
BB3: // 1
	_60_t5 = 7;
	_60_t6 = _61_x + _60_t5;
	_60_t0 = _60_t6;
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
