/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685933745
#define ORNG_1685933745

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _123_main();
int64_t _124_add(int64_t _124_x, int64_t _124_y);

int64_t _123_main() {
	int64_t (*_123_t0)(int64_t _124_x, int64_t _124_y);
	int64_t _123_t2;
	int64_t _123_t3;
	int64_t _123_$retval;
BB0:
	_123_t0 = _124_add;
	_123_t2 = 40;
	_123_t3 = 3;
	_123_$retval = _123_t0(_123_t2, _123_t3);
	return _123_$retval;
}

int64_t _124_add(int64_t _124_x, int64_t _124_y) {
	int64_t _124_$retval;
BB0:
	_124_$retval = _124_x + _124_y;
	return _124_$retval;
}


int main()
{
  printf("%ld",_123_main());
  return 0;
}

#endif
