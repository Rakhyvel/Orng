/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686709170
#define ORNG_1686709170

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();

/* Function forward definitions */
int64_t _191_main();

/* Function definitions */
int64_t _191_main() {
	int64_t _192_x;
	int64_t _193_i;
	int64_t _191_t5;
	uint8_t _191_t3;
	int64_t _191_t10;
	int64_t _191_$retval;
BB0:
	_192_x = 0;
	_193_i = 0;
	goto BB1;
BB1:
	_191_t5 = 10;
	_191_t3 = _193_i <= _191_t5;
	if (!_191_t3) {
		goto BB10;
	} else {
		goto BB2;
	}
BB2:
	_192_x = _192_x + _193_i;
	_191_t10 = 1;
	_193_i = _193_i + _191_t10;
	goto BB1;
BB10:
	_191_$retval = _192_x;
	return _191_$retval;
}


int main()
{
  printf("%ld",_191_main());
  return 0;
}

#endif
