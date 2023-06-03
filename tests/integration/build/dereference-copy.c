/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685775392
#define ORNG_1685775392

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _93_t1;
	int64_t* _94_y;
	int64_t _93_t4;
	int64_t _93_$retval;
BB0:
	_93_t1 = 4;
	_94_y = &_93_t1;
	_93_t4 = 28;
	*_94_y = _93_t4;
	_93_$retval = *_94_y;
	return _93_$retval;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
