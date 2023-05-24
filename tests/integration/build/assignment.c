/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684898822
#define ORNG_1684898822

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int64_t _56_t0;
	int64_t _57_x;
	int64_t _56_t1;
	int64_t _56_t2;
	int64_t _0;
BB0: // 1
	_56_t0 = 4;
	_57_x = _56_t0;
	_56_t1 = 6;
	_56_t2 = _57_x + _56_t1;
	_57_x = _56_t2;
	retval = _57_x;
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
