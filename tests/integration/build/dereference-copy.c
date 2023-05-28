/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685256120
#define ORNG_1685256120

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _100_t1;
	int64_t* _101_y;
	int64_t* _100_t3;
	int64_t _100_t4;
	int64_t _100_$retval;
BB0:
	_100_t1 = 4;
	_101_y = &_100_t1;
	_100_t3 = _101_y;
	_100_t4 = 28;
	*_100_t3 = _100_t4;
	_100_$retval = *_101_y;
	return _100_$retval;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
