/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687123796
#define ORNG_1687123796

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _16_main();

/* Function definitions */
int64_t _16_main() {
	int64_t _17_x;
	int64_t* _17_y;
	int64_t _16_t3;
	int64_t _16_t4;
	uint8_t _16_t2;
	uint8_t _16_t5;
	uint8_t _16_t6;
	uint8_t _16_t7;
	int64_t _16_t8;
	int64_t _16_$retval;
BB0:
	_17_x = 0;
	_17_y = &_17_x;
	_16_t3 = *_17_y;
	_16_t4 = 1;
	_16_t2 = _16_t3 == _16_t4;
	if (!_16_t2) {
		goto BB9;
	} else {
		goto BB1;
	}
BB1:
	_16_t2 = 1;
	goto BB2;
BB2:
	_16_t5 = !_16_t2;
	_16_t6 = !_16_t5;
	_16_t7 = !_16_t6;
	if (!_16_t7) {
		goto BB7;
	} else {
		goto BB3;
	}
BB3:
	_16_t8 = 31;
	goto BB6;
BB6:
	_16_$retval = _16_t8;
	return _16_$retval;
BB7:
	_16_t8 = 10;
	goto BB6;
BB9:
	_16_t2 = 0;
	goto BB2;
}


int main()
{
  printf("%ld",_16_main());
  return 0;
}

#endif
