/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685933745
#define ORNG_1685933745

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _137_main();

int64_t _137_main() {
	int64_t _138_x;
	int64_t _137_t4;
	uint8_t _137_t2;
	int64_t _137_t8;
	int64_t _137_t9;
	int64_t _137_t10;
	uint8_t _137_t6;
	int64_t _137_t15;
	int64_t _137_t12;
	int64_t _137_$retval;
BB0:
	_138_x = 17;
	goto BB1;
BB1:
	_137_t4 = 36;
	_137_t2 = _138_x < _137_t4;
	if (!_137_t2) {
		goto BB17;
	} else {
		goto BB2;
	}
BB2:
	_137_t8 = 2;
	_137_t9 = _138_x % _137_t8;
	_137_t10 = 0;
	_137_t6 = _137_t9 == _137_t10;
	if (!_137_t6) {
		goto BB13;
	} else {
		goto BB8;
	}
BB8:
	_137_t15 = 9;
	_138_x = _138_x + _137_t15;
	goto BB1;
BB13:
	_137_t12 = 1;
	_138_x = _138_x + _137_t12;
	goto BB8;
BB17:
	_137_$retval = _138_x;
	return _137_$retval;
}


int main()
{
  printf("%ld",_137_main());
  return 0;
}

#endif
