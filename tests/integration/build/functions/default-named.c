/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687131003
#define ORNG_1687131003

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _254_main();
int64_t _255_add(int64_t _255_x,int64_t _255_y);

/* Function definitions */
int64_t _254_main() {
	int64_t _254_t1;
	int64_t _254_t2;
	int64_t _254_t0;
	int64_t _254_$retval;
BB0:
	_254_t1 = 4;
	_254_t2 = 50;
	_254_t0 = _255_add(_254_t1, _254_t2);
	_254_$retval = _254_t0;
	return _254_$retval;
}

int64_t _255_add(int64_t _255_x,int64_t _255_y) {
	int64_t _255_$retval;
BB0:
	_255_$retval = _255_x + _255_y;
	return _255_$retval;
}


int main()
{
  printf("%ld",_254_main());
  return 0;
}

#endif
