/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684897129
#define ORNG_1684897129

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int64_t _2_t0;
	int64_t _2_t1;
	int64_t _2_t2;
	int64_t _3_x;
	int64_t _0;
BB0: // 1
	_2_t0 = 20;
	_2_t1 = 7;
	_2_t2 = _2_t0 + _2_t1;
	_3_x = _2_t2;
	retval = _3_x;
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
