/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686626622
#define ORNG_1686626622

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();

/* Function forward definitions */
int64_t _156_main();

/* Function definitions */
int64_t _156_main() {
	int64_t _157_x;
	int64_t _158_i;
	int64_t _156_t5;
	uint8_t _156_t3;
	int64_t _156_t9;
	int64_t _156_t10;
	int64_t _156_t11;
	uint8_t _156_t7;
	int64_t _156_$retval;
	int64_t _156_t13;
	int64_t _156_t16;
BB0:
	_157_x = 36;
	_158_i = 0;
	goto BB1;
BB1:
	_156_t5 = 70;
	_156_t3 = _158_i < _156_t5;
	if (!_156_t3) {
		goto BB17;
	} else {
		goto BB2;
	}
BB2:
	_156_t9 = 2;
	_156_t10 = _158_i % _156_t9;
	_156_t11 = 0;
	_156_t7 = _156_t10 == _156_t11;
	if (!_156_t7) {
		goto BB14;
	} else {
		goto BB8;
	}
BB8:
	_156_$retval = _157_x;
	return _156_$retval;
BB14:
	_156_t13 = 1;
	_157_x = _157_x + _156_t13;
	_156_t16 = 1;
	_158_i = _158_i + _156_t16;
	goto BB1;
BB17:
	_157_x = 10;
	goto BB8;
}


int main()
{
  printf("%ld",_156_main());
  return 0;
}

#endif
