/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687128101
#define ORNG_1687128101

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _55_main();
int64_t _56_add(int64_t x,int64_t y);

/* Function definitions */
int64_t _55_main() {
	int64_t _55_t1;
	int64_t _55_t2;
	int64_t _55_t0;
	int64_t _55_$retval;
BB0:
	_55_t1 = 4;
	_55_t2 = 50;
	_55_t0 = _56_add(_55_t1, _55_t2);
	_55_$retval = _55_t0;
	return _55_$retval;
}

int64_t _56_add(int64_t x,int64_t y) {
	int64_t _56_$retval;
BB0:
	_56_$retval = x + y;
	return _56_$retval;
}


int main()
{
  printf("%ld",_55_main());
  return 0;
}

#endif
