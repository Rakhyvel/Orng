/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685933745
#define ORNG_1685933745

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _80_main();

int64_t _80_main() {
	int64_t _81_x;
	int64_t _80_t4;
	uint8_t _80_t2;
	int64_t _80_t8;
	uint8_t _80_t6;
	int64_t _80_t13;
	int64_t _80_$retval;
	int64_t _80_t10;
	int64_t _80_t19;
BB0:
	_81_x = 0;
	goto BB1;
BB1:
	_80_t4 = 100;
	_80_t2 = _81_x < _80_t4;
	if (!_80_t2) {
		goto BB9;
	} else {
		goto BB2;
	}
BB2:
	_80_t8 = 36;
	_80_t6 = _81_x >= _80_t8;
	if (!_80_t6) {
		goto BB16;
	} else {
		goto BB5;
	}
BB5:
	_80_t13 = 2;
	_81_x = _81_x + _80_t13;
	goto BB9;
BB9:
	_80_$retval = _81_x;
	return _80_$retval;
BB16:
	_80_t10 = 2;
	_81_x = _81_x + _80_t10;
	_80_t19 = 1;
	_81_x = _81_x + _80_t19;
	goto BB1;
}


int main()
{
  printf("%ld",_80_main());
  return 0;
}

#endif
