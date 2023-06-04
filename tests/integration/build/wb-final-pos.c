/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685922416
#define ORNG_1685922416

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _225_main();

int64_t _225_main() {
	int64_t _226_x;
	int64_t _225_t4;
	uint8_t _225_t2;
	int64_t _225_t8;
	uint8_t _225_t6;
	int64_t _225_t10;
	int64_t _225_$retval;
	int64_t _225_t13;
BB0:
	_226_x = 0;
	goto BB1;
BB1:
	_225_t4 = 100;
	_225_t2 = _226_x < _225_t4;
	if (!_225_t2) {
		goto BB8;
	} else {
		goto BB2;
	}
BB2:
	_225_t8 = 40;
	_225_t6 = _226_x == _225_t8;
	if (!_225_t6) {
		goto BB14;
	} else {
		goto BB5;
	}
BB5:
	_225_t10 = 1;
	_226_x = _226_x + _225_t10;
	goto BB8;
BB8:
	_225_$retval = _226_x;
	return _225_$retval;
BB14:
	_225_t13 = 1;
	_226_x = _226_x + _225_t13;
	goto BB1;
}


int main()
{
  printf("%ld",_225_main());
  return 0;
}

#endif
