/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684721095530469870
#define ORNG_1684721095530469870

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _93_main();

/* Function definitions */
int64_t _93_main() {
	int64_t _95_x;
	int64_t _93_t3;
	uint8_t _93_t2;
	int64_t _93_t4;
	int64_t _93_t7;
	int64_t _93_$retval;
BB0:
	_95_x = 0;
	goto BB1;
BB1:
	_93_t3 = 10;
	_93_t2 = _95_x < _93_t3;
	if (!_93_t2) {
		goto BB11;
	} else {
		goto BB2;
	}
BB2:
	_93_t4 = 1;
	_95_x = _95_x + _93_t4;
	_93_t7 = 1;
	_95_x = _95_x + _93_t7;
	goto BB1;
BB11:
	_93_$retval = _95_x;
	return _93_$retval;
}


int main()
{
  printf("%ld",_93_main());
  return 0;
}

#endif
