/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687131003
#define ORNG_1687131003

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _219_main();
int64_t _220_id(int64_t _220_x);

/* Function definitions */
int64_t _219_main() {
	int64_t _219_t1;
	int64_t _219_t0;
	int64_t _219_$retval;
BB0:
	_219_t1 = 52;
	_219_t0 = _220_id(_219_t1);
	_219_$retval = _219_t0;
	return _219_$retval;
}

int64_t _220_id(int64_t _220_x) {
	int64_t _220_$retval;
BB0:
	_220_$retval = _220_x;
	return _220_$retval;
}


int main()
{
  printf("%ld",_219_main());
  return 0;
}

#endif
