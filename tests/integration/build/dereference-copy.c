/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685915967
#define ORNG_1685915967

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _122_t1;
	int64_t* _123_y;
	int64_t _122_t4;
	int64_t _122_$retval;
BB0:
	_122_t1 = 4;
	_123_y = &_122_t1;
	_122_t4 = 28;
	*_123_y = _122_t4;
	_122_$retval = *_123_y;
	return _122_$retval;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
