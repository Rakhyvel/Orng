/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685912303
#define ORNG_1685912303

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _93_x;
	int64_t _94_i;
	int64_t _92_t5;
	uint8_t _92_t3;
	int64_t _92_t9;
	int64_t _92_t10;
	int64_t _92_t11;
	uint8_t _92_t7;
	int64_t _92_t16;
	int64_t _92_t13;
	int64_t _92_$retval;
BB0:
	_93_x = 0;
	_94_i = 0;
	goto BB1;
BB1:
	_92_t5 = 70;
	_92_t3 = _94_i < _92_t5;
	if (!_92_t3) {
		goto BB16;
	} else {
		goto BB2;
	}
BB2:
	_92_t9 = 2;
	_92_t10 = _94_i % _92_t9;
	_92_t11 = 0;
	_92_t7 = _92_t10 == _92_t11;
	if (!_92_t7) {
		goto BB12;
	} else {
		goto BB8;
	}
BB8:
	_92_t16 = 1;
	_94_i = _94_i + _92_t16;
	goto BB1;
BB12:
	_92_t13 = 1;
	_93_x = _93_x + _92_t13;
	goto BB8;
BB16:
	_92_$retval = _93_x;
	return _92_$retval;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
