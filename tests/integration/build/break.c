/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685915967
#define ORNG_1685915967

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _153_x;
	int64_t _154_i;
	int64_t _152_t5;
	uint8_t _152_t3;
	int64_t _152_t9;
	int64_t _152_t10;
	int64_t _152_t11;
	uint8_t _152_t7;
	int64_t _152_$retval;
	int64_t _152_t13;
	int64_t _152_t16;
BB0:
	_153_x = 36;
	_154_i = 0;
	goto BB1;
BB1:
	_152_t5 = 70;
	_152_t3 = _154_i < _152_t5;
	if (!_152_t3) {
		goto BB17;
	} else {
		goto BB2;
	}
BB2:
	_152_t9 = 2;
	_152_t10 = _154_i % _152_t9;
	_152_t11 = 0;
	_152_t7 = _152_t10 == _152_t11;
	if (!_152_t7) {
		goto BB14;
	} else {
		goto BB8;
	}
BB8:
	_152_$retval = _153_x;
	return _152_$retval;
BB14:
	_152_t13 = 1;
	_153_x = _153_x + _152_t13;
	_152_t16 = 1;
	_154_i = _154_i + _152_t16;
	goto BB1;
BB17:
	_153_x = 10;
	goto BB8;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
