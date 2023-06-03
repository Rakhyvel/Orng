/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685775392
#define ORNG_1685775392

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _23_t1;
	int64_t* _24_y;
	int64_t _23_$retval;
BB0:
	_23_t1 = 29;
	_24_y = &_23_t1;
	_23_$retval = *_24_y;
	return _23_$retval;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
