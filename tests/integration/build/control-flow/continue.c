/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686886319
#define ORNG_1686886319

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _104_main();

/* Function definitions */
int64_t _104_main() {
	int64_t _105_x;
	int64_t _106_i;
	int64_t _104_t4;
	uint8_t _104_t3;
	int64_t _104_t7;
	int64_t _104_t8;
	int64_t _104_t9;
	uint8_t _104_t6;
	int64_t _104_t12;
	int64_t _104_t10;
	int64_t _104_$retval;
BB0:
	_105_x = 0;
	_106_i = 0;
	goto BB1;
BB1:
	_104_t4 = 70;
	_104_t3 = _106_i < _104_t4;
	if (!_104_t3) {
		goto BB16;
	} else {
		goto BB2;
	}
BB2:
	_104_t7 = 2;
	_104_t8 = _106_i % _104_t7;
	_104_t9 = 0;
	_104_t6 = _104_t8 == _104_t9;
	if (!_104_t6) {
		goto BB12;
	} else {
		goto BB8;
	}
BB8:
	_104_t12 = 1;
	_106_i = _106_i + _104_t12;
	goto BB1;
BB12:
	_104_t10 = 1;
	_105_x = _105_x + _104_t10;
	goto BB8;
BB16:
	_104_$retval = _105_x;
	return _104_$retval;
}


int main()
{
  printf("%ld",_104_main());
  return 0;
}

#endif
