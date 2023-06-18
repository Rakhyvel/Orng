/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687128100
#define ORNG_1687128100

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _20_main();
int64_t _21_id(int64_t x);

/* Function definitions */
int64_t _20_main() {
	int64_t _20_t1;
	int64_t _20_t0;
	int64_t _20_$retval;
BB0:
	_20_t1 = 52;
	_20_t0 = _21_id(_20_t1);
	_20_$retval = _20_t0;
	return _20_$retval;
}

int64_t _21_id(int64_t x) {
	int64_t _21_$retval;
BB0:
	_21_$retval = x;
	return _21_$retval;
}


int main()
{
  printf("%ld",_20_main());
  return 0;
}

#endif
