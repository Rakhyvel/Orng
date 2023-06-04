/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685912302
#define ORNG_1685912302

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _70_x;
	int64_t _69_t4;
	uint8_t _69_t2;
	int64_t _69_t8;
	uint8_t _69_t6;
	int64_t _69_t13;
	int64_t _69_$retval;
	int64_t _69_t10;
	int64_t _69_t19;
BB0:
	_70_x = 0;
	goto BB1;
BB1:
	_69_t4 = 100;
	_69_t2 = _70_x < _69_t4;
	if (!_69_t2) {
		goto BB9;
	} else {
		goto BB2;
	}
BB2:
	_69_t8 = 36;
	_69_t6 = _70_x >= _69_t8;
	if (!_69_t6) {
		goto BB16;
	} else {
		goto BB5;
	}
BB5:
	_69_t13 = 2;
	_70_x = _70_x + _69_t13;
	goto BB9;
BB9:
	_69_$retval = _70_x;
	return _69_$retval;
BB16:
	_69_t10 = 2;
	_70_x = _70_x + _69_t10;
	_69_t19 = 1;
	_70_x = _70_x + _69_t19;
	goto BB1;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
