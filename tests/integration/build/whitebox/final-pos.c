/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686886319
#define ORNG_1686886319

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _23_main();

/* Function definitions */
int64_t _23_main() {
	int64_t _24_x;
	int64_t _23_t3;
	uint8_t _23_t2;
	int64_t _23_t6;
	uint8_t _23_t5;
	int64_t _23_t7;
	int64_t _23_$retval;
	int64_t _23_t9;
BB0:
	_24_x = 0;
	goto BB1;
BB1:
	_23_t3 = 100;
	_23_t2 = _24_x < _23_t3;
	if (!_23_t2) {
		goto BB9;
	} else {
		goto BB2;
	}
BB2:
	_23_t6 = 40;
	_23_t5 = _24_x == _23_t6;
	if (!_23_t5) {
		goto BB14;
	} else {
		goto BB5;
	}
BB5:
	_23_t7 = 1;
	_24_x = _24_x + _23_t7;
	goto BB9;
BB9:
	_23_$retval = _24_x;
	return _23_$retval;
BB14:
	_23_t9 = 1;
	_24_x = _24_x + _23_t9;
	goto BB1;
}


int main()
{
  printf("%ld",_23_main());
  return 0;
}

#endif
