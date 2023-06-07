/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686104538
#define ORNG_1686104538

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _112_main();

int64_t _112_main() {
	int64_t _113_x;
	int64_t _114_i;
	int64_t _112_t5;
	uint8_t _112_t3;
	int64_t _112_t9;
	int64_t _112_t10;
	int64_t _112_t11;
	uint8_t _112_t7;
	int64_t _112_t16;
	int64_t _112_t13;
	int64_t _112_$retval;
BB0:
	_113_x = 0;
	_114_i = 0;
	goto BB1;
BB1:
	_112_t5 = 70;
	_112_t3 = _114_i < _112_t5;
	if (!_112_t3) {
		goto BB16;
	} else {
		goto BB2;
	}
BB2:
	_112_t9 = 2;
	_112_t10 = _114_i % _112_t9;
	_112_t11 = 0;
	_112_t7 = _112_t10 == _112_t11;
	if (!_112_t7) {
		goto BB12;
	} else {
		goto BB8;
	}
BB8:
	_112_t16 = 1;
	_114_i = _114_i + _112_t16;
	goto BB1;
BB12:
	_112_t13 = 1;
	_113_x = _113_x + _112_t13;
	goto BB8;
BB16:
	_112_$retval = _113_x;
	return _112_$retval;
}


int main()
{
  printf("%ld",_112_main());
  return 0;
}

#endif
