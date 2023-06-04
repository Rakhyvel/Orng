/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685907675
#define ORNG_1685907675

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _3_x;
	int64_t _4_i;
	int64_t _2_t5;
	uint8_t _2_t3;
	int64_t _2_t9;
	int64_t _2_t10;
	int64_t _2_t11;
	uint8_t _2_t7;
	int64_t _2_$retval;
	int64_t _2_t13;
	int64_t _2_t16;
BB0:
	_3_x = 36;
	_4_i = 0;
	goto BB1;
BB1:
	_2_t5 = 70;
	_2_t3 = _4_i < _2_t5;
	if (!_2_t3) {
		goto BB17;
	} else {
		goto BB2;
	}
BB2:
	_2_t9 = 2;
	_2_t10 = _4_i % _2_t9;
	_2_t11 = 0;
	_2_t7 = _2_t10 == _2_t11;
	if (!_2_t7) {
		goto BB14;
	} else {
		goto BB8;
	}
BB8:
	_2_$retval = _3_x;
	return _2_$retval;
BB14:
	_2_t13 = 1;
	_3_x = _3_x + _2_t13;
	_2_t16 = 1;
	_4_i = _4_i + _2_t16;
	goto BB1;
BB17:
	_3_x = 10;
	goto BB8;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
