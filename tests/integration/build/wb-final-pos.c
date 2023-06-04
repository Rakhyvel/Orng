/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685916327
#define ORNG_1685916327

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _222_x;
	int64_t _221_t4;
	uint8_t _221_t2;
	int64_t _221_t8;
	uint8_t _221_t6;
	int64_t _221_t10;
	int64_t _221_$retval;
	int64_t _221_t13;
BB0:
	_222_x = 0;
	goto BB1;
BB1:
	_221_t4 = 100;
	_221_t2 = _222_x < _221_t4;
	if (!_221_t2) {
		goto BB8;
	} else {
		goto BB2;
	}
BB2:
	_221_t8 = 40;
	_221_t6 = _222_x == _221_t8;
	if (!_221_t6) {
		goto BB14;
	} else {
		goto BB5;
	}
BB5:
	_221_t10 = 1;
	_222_x = _222_x + _221_t10;
	goto BB8;
BB8:
	_221_$retval = _222_x;
	return _221_$retval;
BB14:
	_221_t13 = 1;
	_222_x = _222_x + _221_t13;
	goto BB1;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
