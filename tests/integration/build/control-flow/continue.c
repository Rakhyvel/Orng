/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685816031608895524
#define ORNG_1685816031608895524

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _113_main();

/* Function definitions */
int64_t _113_main() {
	int64_t _114_x;
	int64_t _115_i;
	int64_t _113_t4;
	uint8_t _113_t3;
	int64_t _113_t7;
	int64_t _113_t8;
	int64_t _113_t9;
	uint8_t _113_t6;
	int64_t _113_t12;
	int64_t _113_t10;
	int64_t _113_$retval;
BB0:
	_114_x = 0;
	_115_i = 0;
	goto BB1;
BB1:
	_113_t4 = 70;
	_113_t3 = _115_i < _113_t4;
	if (!_113_t3) {
		goto BB16;
	} else {
		goto BB2;
	}
BB2:
	_113_t7 = 2;
	_113_t8 = _115_i % _113_t7;
	_113_t9 = 0;
	_113_t6 = _113_t8 == _113_t9;
	if (!_113_t6) {
		goto BB12;
	} else {
		goto BB8;
	}
BB8:
	_113_t12 = 1;
	_115_i = _115_i + _113_t12;
	goto BB1;
BB12:
	_113_t10 = 1;
	_114_x = _114_x + _113_t10;
	goto BB8;
BB16:
	_113_$retval = _114_x;
	return _113_$retval;
}


int main()
{
  printf("%ld",_113_main());
  return 0;
}

#endif
