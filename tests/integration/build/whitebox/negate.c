/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686886319
#define ORNG_1686886319

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _47_main();

/* Function definitions */
int64_t _47_main() {
	int64_t _48_x;
	int64_t* _48_y;
	int64_t _47_t4;
	int64_t _47_t5;
	int64_t _47_t7;
	uint8_t _47_t3;
	int64_t _47_t2;
	int64_t _47_$retval;
BB0:
	_48_x = 1;
	_48_y = &_48_x;
	_47_t4 = *_48_y;
	_47_t5 = -_47_t4;
	_47_t7 = -1;
	_47_t3 = _47_t5 == _47_t7;
	if (!_47_t3) {
		goto BB9;
	} else {
		goto BB1;
	}
BB1:
	_47_t2 = 32;
	goto BB6;
BB6:
	_47_$retval = _47_t2;
	return _47_$retval;
BB9:
	_47_t2 = 10;
	goto BB6;
}


int main()
{
  printf("%ld",_47_main());
  return 0;
}

#endif
