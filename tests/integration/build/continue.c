/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685922416
#define ORNG_1685922416

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _88_main();

int64_t _88_main() {
	int64_t _89_x;
	int64_t _90_i;
	int64_t _88_t5;
	uint8_t _88_t3;
	int64_t _88_t9;
	int64_t _88_t10;
	int64_t _88_t11;
	uint8_t _88_t7;
	int64_t _88_t16;
	int64_t _88_t13;
	int64_t _88_$retval;
BB0:
	_89_x = 0;
	_90_i = 0;
	goto BB1;
BB1:
	_88_t5 = 70;
	_88_t3 = _90_i < _88_t5;
	if (!_88_t3) {
		goto BB16;
	} else {
		goto BB2;
	}
BB2:
	_88_t9 = 2;
	_88_t10 = _90_i % _88_t9;
	_88_t11 = 0;
	_88_t7 = _88_t10 == _88_t11;
	if (!_88_t7) {
		goto BB12;
	} else {
		goto BB8;
	}
BB8:
	_88_t16 = 1;
	_90_i = _90_i + _88_t16;
	goto BB1;
BB12:
	_88_t13 = 1;
	_89_x = _89_x + _88_t13;
	goto BB8;
BB16:
	_88_$retval = _89_x;
	return _88_$retval;
}


int main()
{
  printf("%ld",_88_main());
  return 0;
}

#endif
