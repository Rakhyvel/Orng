/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685928987
#define ORNG_1685928987

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _2_main();
int64_t _3_add(int64_t _3_x, int64_t _3_y);

int64_t _2_main() {
	int64_t (*_2_t0)(int64_t _3_x, int64_t _3_y);
	int64_t _2_t2;
	int64_t _2_t3;
	int64_t _2_$retval;
BB0:
	_2_t0 = _3_add;
	_2_t2 = 40;
	_2_t3 = 3;
	_2_$retval = _2_t0(_2_t2, _2_t3);
	return _2_$retval;
}

int64_t _3_add(int64_t _3_x, int64_t _3_y) {
	int64_t _3_$retval;
BB0:
	_3_$retval = _3_x + _3_y;
	return _3_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
