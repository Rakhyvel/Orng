/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687131173
#define ORNG_1687131173

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _169_main();

/* Function definitions */
int64_t _169_main() {
	int64_t _170_x;
	int64_t _171_i;
	int64_t _169_t4;
	uint8_t _169_t3;
	int64_t _169_t7;
	int64_t _169_t8;
	int64_t _169_t9;
	uint8_t _169_t6;
	int64_t _169_$retval;
	int64_t _169_t10;
	int64_t _169_t12;
BB0:
	_170_x = 36;
	_171_i = 0;
	goto BB1;
BB1:
	_169_t4 = 70;
	_169_t3 = _171_i < _169_t4;
	if (!_169_t3) {
		goto BB17;
	} else {
		goto BB2;
	}
BB2:
	_169_t7 = 2;
	_169_t8 = _171_i % _169_t7;
	_169_t9 = 0;
	_169_t6 = _169_t8 == _169_t9;
	if (!_169_t6) {
		goto BB14;
	} else {
		goto BB9;
	}
BB9:
	_169_$retval = _170_x;
	return _169_$retval;
BB14:
	_169_t10 = 1;
	_170_x = _170_x + _169_t10;
	_169_t12 = 1;
	_171_i = _171_i + _169_t12;
	goto BB1;
BB17:
	_170_x = 10;
	goto BB9;
}


int main()
{
  printf("%ld",_169_main());
  return 0;
}

#endif
