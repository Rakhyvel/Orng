/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686626622
#define ORNG_1686626622

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();

/* Function forward definitions */
int64_t _96_main();

/* Function definitions */
int64_t _96_main() {
	int64_t _97_x;
	int64_t _96_t4;
	uint8_t _96_t2;
	int64_t _96_t8;
	uint8_t _96_t6;
	int64_t _96_t13;
	int64_t _96_$retval;
	int64_t _96_t10;
	int64_t _96_t19;
BB0:
	_97_x = 0;
	goto BB1;
BB1:
	_96_t4 = 100;
	_96_t2 = _97_x < _96_t4;
	if (!_96_t2) {
		goto BB9;
	} else {
		goto BB2;
	}
BB2:
	_96_t8 = 36;
	_96_t6 = _97_x >= _96_t8;
	if (!_96_t6) {
		goto BB16;
	} else {
		goto BB5;
	}
BB5:
	_96_t13 = 2;
	_97_x = _97_x + _96_t13;
	goto BB9;
BB9:
	_96_$retval = _97_x;
	return _96_$retval;
BB16:
	_96_t10 = 2;
	_97_x = _97_x + _96_t10;
	_96_t19 = 1;
	_97_x = _97_x + _96_t19;
	goto BB1;
}


int main()
{
  printf("%ld",_96_main());
  return 0;
}

#endif
