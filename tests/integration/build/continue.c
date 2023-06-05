/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685933745
#define ORNG_1685933745

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _95_main();

int64_t _95_main() {
	int64_t _96_x;
	int64_t _97_i;
	int64_t _95_t5;
	uint8_t _95_t3;
	int64_t _95_t9;
	int64_t _95_t10;
	int64_t _95_t11;
	uint8_t _95_t7;
	int64_t _95_t16;
	int64_t _95_t13;
	int64_t _95_$retval;
BB0:
	_96_x = 0;
	_97_i = 0;
	goto BB1;
BB1:
	_95_t5 = 70;
	_95_t3 = _97_i < _95_t5;
	if (!_95_t3) {
		goto BB16;
	} else {
		goto BB2;
	}
BB2:
	_95_t9 = 2;
	_95_t10 = _97_i % _95_t9;
	_95_t11 = 0;
	_95_t7 = _95_t10 == _95_t11;
	if (!_95_t7) {
		goto BB12;
	} else {
		goto BB8;
	}
BB8:
	_95_t16 = 1;
	_97_i = _97_i + _95_t16;
	goto BB1;
BB12:
	_95_t13 = 1;
	_96_x = _96_x + _95_t13;
	goto BB8;
BB16:
	_95_$retval = _96_x;
	return _95_$retval;
}


int main()
{
  printf("%ld",_95_main());
  return 0;
}

#endif
