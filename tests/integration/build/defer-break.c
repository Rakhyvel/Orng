/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685922416
#define ORNG_1685922416

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _73_main();

int64_t _73_main() {
	int64_t _74_x;
	int64_t _73_t4;
	uint8_t _73_t2;
	int64_t _73_t8;
	uint8_t _73_t6;
	int64_t _73_t13;
	int64_t _73_$retval;
	int64_t _73_t10;
	int64_t _73_t19;
BB0:
	_74_x = 0;
	goto BB1;
BB1:
	_73_t4 = 100;
	_73_t2 = _74_x < _73_t4;
	if (!_73_t2) {
		goto BB9;
	} else {
		goto BB2;
	}
BB2:
	_73_t8 = 36;
	_73_t6 = _74_x >= _73_t8;
	if (!_73_t6) {
		goto BB16;
	} else {
		goto BB5;
	}
BB5:
	_73_t13 = 2;
	_74_x = _74_x + _73_t13;
	goto BB9;
BB9:
	_73_$retval = _74_x;
	return _73_$retval;
BB16:
	_73_t10 = 2;
	_74_x = _74_x + _73_t10;
	_73_t19 = 1;
	_74_x = _74_x + _73_t19;
	goto BB1;
}


int main()
{
  printf("%ld",_73_main());
  return 0;
}

#endif
