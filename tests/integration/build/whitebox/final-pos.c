/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686709170
#define ORNG_1686709170

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();

/* Function forward definitions */
int64_t _23_main();

/* Function definitions */
int64_t _23_main() {
	int64_t _24_x;
	int64_t _23_t4;
	uint8_t _23_t2;
	int64_t _23_t8;
	uint8_t _23_t6;
	int64_t _23_t10;
	int64_t _23_$retval;
	int64_t _23_t13;
BB0:
	_24_x = 0;
	goto BB1;
BB1:
	_23_t4 = 100;
	_23_t2 = _24_x < _23_t4;
	if (!_23_t2) {
		goto BB8;
	} else {
		goto BB2;
	}
BB2:
	_23_t8 = 40;
	_23_t6 = _24_x == _23_t8;
	if (!_23_t6) {
		goto BB14;
	} else {
		goto BB5;
	}
BB5:
	_23_t10 = 1;
	_24_x = _24_x + _23_t10;
	goto BB8;
BB8:
	_23_$retval = _24_x;
	return _23_$retval;
BB14:
	_23_t13 = 1;
	_24_x = _24_x + _23_t13;
	goto BB1;
}


int main()
{
  printf("%ld",_23_main());
  return 0;
}

#endif
