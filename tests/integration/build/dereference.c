/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685907398
#define ORNG_1685907398

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _30_t1;
	int64_t* _31_y;
	int64_t _30_$retval;
BB0:
	_30_t1 = 29;
	_31_y = &_30_t1;
	_30_$retval = *_31_y;
	return _30_$retval;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
