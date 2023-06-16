/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686886319
#define ORNG_1686886319

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _207_main();
int64_t _208_add(int64_t x,int64_t y);

/* Function definitions */
int64_t _207_main() {
	int64_t _207_t1;
	int64_t _207_t2;
	int64_t _207_t0;
	int64_t _207_$retval;
BB0:
	_207_t1 = 40;
	_207_t2 = 3;
	_207_t0 = _208_add(_207_t1, _207_t2);
	_207_$retval = _207_t0;
	return _207_$retval;
}

int64_t _208_add(int64_t x,int64_t y) {
	int64_t _208_$retval;
BB0:
	_208_$retval = x + y;
	return _208_$retval;
}


int main()
{
  printf("%ld",_207_main());
  return 0;
}

#endif
