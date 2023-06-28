/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685915540041912035
#define ORNG_1685915540041912035

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _143_main();

/* Function definitions */
int64_t _143_main() {
	int64_t _144_x;
	int64_t _143_t3;
	uint8_t _143_t2;
	int64_t _143_t6;
	int64_t _143_t7;
	int64_t _143_t8;
	uint8_t _143_t5;
	int64_t _143_t11;
	int64_t _143_t9;
	int64_t _143_$retval;
BB0:
	_144_x = 17;
	goto BB1;
BB1:
	_143_t3 = 36;
	_143_t2 = _144_x < _143_t3;
	if (!_143_t2) {
		goto BB17;
	} else {
		goto BB2;
	}
BB2:
	_143_t6 = 2;
	_143_t7 = _144_x % _143_t6;
	_143_t8 = 0;
	_143_t5 = _143_t7 == _143_t8;
	if (!_143_t5) {
		goto BB13;
	} else {
		goto BB8;
	}
BB8:
	_143_t11 = 9;
	_144_x = _144_x + _143_t11;
	goto BB1;
BB13:
	_143_t9 = 1;
	_144_x = _144_x + _143_t9;
	goto BB8;
BB17:
	_143_$retval = _144_x;
	return _143_$retval;
}


int main()
{
  printf("%ld",_143_main());
  return 0;
}

#endif
