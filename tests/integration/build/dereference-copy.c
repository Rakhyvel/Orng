/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685907401
#define ORNG_1685907401

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _114_t1;
	int64_t* _115_y;
	int64_t _114_t4;
	int64_t _114_$retval;
BB0:
	_114_t1 = 4;
	_115_y = &_114_t1;
	_114_t4 = 28;
	*_115_y = _114_t4;
	_114_$retval = *_115_y;
	return _114_$retval;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
