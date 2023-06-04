/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685907400
#define ORNG_1685907400

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _81_x;
	int64_t _82_i;
	int64_t _80_t5;
	uint8_t _80_t3;
	int64_t _80_t9;
	int64_t _80_t10;
	int64_t _80_t11;
	uint8_t _80_t7;
	int64_t _80_t16;
	int64_t _80_t13;
	int64_t _80_$retval;
BB0:
	_81_x = 0;
	_82_i = 0;
	goto BB1;
BB1:
	_80_t5 = 70;
	_80_t3 = _82_i < _80_t5;
	if (!_80_t3) {
		goto BB16;
	} else {
		goto BB2;
	}
BB2:
	_80_t9 = 2;
	_80_t10 = _82_i % _80_t9;
	_80_t11 = 0;
	_80_t7 = _80_t10 == _80_t11;
	if (!_80_t7) {
		goto BB12;
	} else {
		goto BB8;
	}
BB8:
	_80_t16 = 1;
	_82_i = _82_i + _80_t16;
	goto BB1;
BB12:
	_80_t13 = 1;
	_81_x = _81_x + _80_t13;
	goto BB8;
BB16:
	_80_$retval = _81_x;
	return _80_$retval;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
