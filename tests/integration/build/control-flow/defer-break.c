/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686980573
#define ORNG_1686980573

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _96_main();

/* Function definitions */
int64_t _96_main() {
	int64_t _97_x;
	int64_t _96_t3;
	uint8_t _96_t2;
	int64_t _96_t6;
	uint8_t _96_t5;
	int64_t _96_t9;
	int64_t _96_$retval;
	int64_t _96_t7;
	int64_t _96_t13;
BB0:
	_97_x = 0;
	goto BB1;
BB1:
	_96_t3 = 100;
	_96_t2 = _97_x < _96_t3;
	if (!_96_t2) {
		goto BB10;
	} else {
		goto BB2;
	}
BB2:
	_96_t6 = 36;
	_96_t5 = _97_x >= _96_t6;
	if (!_96_t5) {
		goto BB16;
	} else {
		goto BB5;
	}
BB5:
	_96_t9 = 2;
	_97_x = _97_x + _96_t9;
	goto BB10;
BB10:
	_96_$retval = _97_x;
	return _96_$retval;
BB16:
	_96_t7 = 2;
	_97_x = _97_x + _96_t7;
	_96_t13 = 1;
	_97_x = _97_x + _96_t13;
	goto BB1;
}


int main()
{
  printf("%ld",_96_main());
  return 0;
}

#endif
