/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685933745
#define ORNG_1685933745

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _163_main();

int64_t _163_main() {
	int64_t _164_x;
	int64_t _165_i;
	int64_t _163_t5;
	uint8_t _163_t3;
	int64_t _163_t9;
	int64_t _163_t10;
	int64_t _163_t11;
	uint8_t _163_t7;
	int64_t _163_$retval;
	int64_t _163_t13;
	int64_t _163_t16;
BB0:
	_164_x = 36;
	_165_i = 0;
	goto BB1;
BB1:
	_163_t5 = 70;
	_163_t3 = _165_i < _163_t5;
	if (!_163_t3) {
		goto BB17;
	} else {
		goto BB2;
	}
BB2:
	_163_t9 = 2;
	_163_t10 = _165_i % _163_t9;
	_163_t11 = 0;
	_163_t7 = _163_t10 == _163_t11;
	if (!_163_t7) {
		goto BB14;
	} else {
		goto BB8;
	}
BB8:
	_163_$retval = _164_x;
	return _163_$retval;
BB14:
	_163_t13 = 1;
	_164_x = _164_x + _163_t13;
	_163_t16 = 1;
	_165_i = _165_i + _163_t16;
	goto BB1;
BB17:
	_164_x = 10;
	goto BB8;
}


int main()
{
  printf("%ld",_163_main());
  return 0;
}

#endif
