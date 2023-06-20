/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687227438
#define ORNG_1687227438

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _195_main();

/* Function definitions */
int64_t _195_main() {
	int64_t _196_x;
	int64_t _197_i;
	int64_t _195_t4;
	uint8_t _195_t3;
	int64_t _195_t6;
	int64_t _195_$retval;
BB0:
	_196_x = 0;
	_197_i = 0;
	goto BB1;
BB1:
	_195_t4 = 10;
	_195_t3 = _197_i <= _195_t4;
	if (!_195_t3) {
		goto BB10;
	} else {
		goto BB2;
	}
BB2:
	_196_x = _196_x + _197_i;
	_195_t6 = 1;
	_197_i = _197_i + _195_t6;
	goto BB1;
BB10:
	_195_$retval = _196_x;
	return _195_$retval;
}


int main()
{
  printf("%ld",_195_main());
  return 0;
}

#endif
