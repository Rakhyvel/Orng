/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687131003
#define ORNG_1687131003

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _105_main();

/* Function definitions */
int64_t _105_main() {
	int64_t _106_x;
	int64_t _105_t3;
	uint8_t _105_t2;
	int64_t _105_t6;
	uint8_t _105_t5;
	int64_t _105_t9;
	int64_t _105_$retval;
	int64_t _105_t7;
	int64_t _105_t13;
BB0:
	_106_x = 0;
	goto BB1;
BB1:
	_105_t3 = 100;
	_105_t2 = _106_x < _105_t3;
	if (!_105_t2) {
		goto BB10;
	} else {
		goto BB2;
	}
BB2:
	_105_t6 = 36;
	_105_t5 = _106_x >= _105_t6;
	if (!_105_t5) {
		goto BB16;
	} else {
		goto BB5;
	}
BB5:
	_105_t9 = 2;
	_106_x = _106_x + _105_t9;
	goto BB10;
BB10:
	_105_$retval = _106_x;
	return _105_$retval;
BB16:
	_105_t7 = 2;
	_106_x = _106_x + _105_t7;
	_105_t13 = 1;
	_106_x = _106_x + _105_t13;
	goto BB1;
}


int main()
{
  printf("%ld",_105_main());
  return 0;
}

#endif
