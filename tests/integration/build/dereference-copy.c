/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685912303
#define ORNG_1685912303

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _126_t1;
	int64_t* _127_y;
	int64_t _126_t4;
	int64_t _126_$retval;
BB0:
	_126_t1 = 4;
	_127_y = &_126_t1;
	_126_t4 = 28;
	*_127_y = _126_t4;
	_126_$retval = *_127_y;
	return _126_$retval;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
