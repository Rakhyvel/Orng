/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686104538
#define ORNG_1686104538

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _186_main();

int64_t _186_main() {
	int64_t _187_x;
	int64_t _188_i;
	int64_t _186_t5;
	uint8_t _186_t3;
	int64_t _186_t9;
	int64_t _186_t10;
	int64_t _186_t11;
	uint8_t _186_t7;
	int64_t _186_$retval;
	int64_t _186_t13;
	int64_t _186_t16;
BB0:
	_187_x = 36;
	_188_i = 0;
	goto BB1;
BB1:
	_186_t5 = 70;
	_186_t3 = _188_i < _186_t5;
	if (!_186_t3) {
		goto BB17;
	} else {
		goto BB2;
	}
BB2:
	_186_t9 = 2;
	_186_t10 = _188_i % _186_t9;
	_186_t11 = 0;
	_186_t7 = _186_t10 == _186_t11;
	if (!_186_t7) {
		goto BB14;
	} else {
		goto BB8;
	}
BB8:
	_186_$retval = _187_x;
	return _186_$retval;
BB14:
	_186_t13 = 1;
	_187_x = _187_x + _186_t13;
	_186_t16 = 1;
	_188_i = _188_i + _186_t16;
	goto BB1;
BB17:
	_187_x = 10;
	goto BB8;
}


int main()
{
  printf("%ld",_186_main());
  return 0;
}

#endif
