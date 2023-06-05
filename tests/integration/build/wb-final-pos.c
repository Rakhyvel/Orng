/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685933745
#define ORNG_1685933745

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _246_main();

int64_t _246_main() {
	int64_t _247_x;
	int64_t _246_t4;
	uint8_t _246_t2;
	int64_t _246_t8;
	uint8_t _246_t6;
	int64_t _246_t10;
	int64_t _246_$retval;
	int64_t _246_t13;
BB0:
	_247_x = 0;
	goto BB1;
BB1:
	_246_t4 = 100;
	_246_t2 = _247_x < _246_t4;
	if (!_246_t2) {
		goto BB8;
	} else {
		goto BB2;
	}
BB2:
	_246_t8 = 40;
	_246_t6 = _247_x == _246_t8;
	if (!_246_t6) {
		goto BB14;
	} else {
		goto BB5;
	}
BB5:
	_246_t10 = 1;
	_247_x = _247_x + _246_t10;
	goto BB8;
BB8:
	_246_$retval = _247_x;
	return _246_$retval;
BB14:
	_246_t13 = 1;
	_247_x = _247_x + _246_t13;
	goto BB1;
}


int main()
{
  printf("%ld",_246_main());
  return 0;
}

#endif
