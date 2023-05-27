/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685163890
#define ORNG_1685163890

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _60_t1;
	int64_t _61_x;
	uint8_t _60_t2;
	int64_t _60_t6;
	int64_t _60_t7;
	int64_t _60_t8;
	int64_t _60_t0;
	int64_t _60_$retval;
BB0: // 1
	_60_t1 = 4;
	_61_x = 4;
	_60_t2 = 0;
	_60_t6 = _61_x;
	_60_t7 = 7;
	_60_t8 = _60_t6 + _60_t7;
	_60_t0 = _60_t8;
	_60_$retval = _60_t8;
	goto end;
end:
	return _60_$retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
