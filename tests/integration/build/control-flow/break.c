/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686980573
#define ORNG_1686980573

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _156_main();

/* Function definitions */
int64_t _156_main() {
	int64_t _157_x;
	int64_t _158_i;
	int64_t _156_t4;
	uint8_t _156_t3;
	int64_t _156_t7;
	int64_t _156_t8;
	int64_t _156_t9;
	uint8_t _156_t6;
	int64_t _156_$retval;
	int64_t _156_t10;
	int64_t _156_t12;
BB0:
	_157_x = 36;
	_158_i = 0;
	goto BB1;
BB1:
	_156_t4 = 70;
	_156_t3 = _158_i < _156_t4;
	if (!_156_t3) {
		goto BB17;
	} else {
		goto BB2;
	}
BB2:
	_156_t7 = 2;
	_156_t8 = _158_i % _156_t7;
	_156_t9 = 0;
	_156_t6 = _156_t8 == _156_t9;
	if (!_156_t6) {
		goto BB14;
	} else {
		goto BB9;
	}
BB9:
	_156_$retval = _157_x;
	return _156_$retval;
BB14:
	_156_t10 = 1;
	_157_x = _157_x + _156_t10;
	_156_t12 = 1;
	_158_i = _158_i + _156_t12;
	goto BB1;
BB17:
	_157_x = 10;
	goto BB9;
}


int main()
{
  printf("%ld",_156_main());
  return 0;
}

#endif
