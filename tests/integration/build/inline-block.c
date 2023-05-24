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
	int64_t _83_t0;
	int64_t _84_x;
	int64_t _83_t1;
	int64_t _83_t2;
	int64_t _0;
BB0: // 1
	_83_t0 = 13;
	_84_x = _83_t0;
	_83_t1 = 2;
	_83_t2 = _84_x * _83_t1;
	_84_x = _83_t2;
	retval = _84_x;
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
