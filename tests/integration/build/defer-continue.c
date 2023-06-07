/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686104538
#define ORNG_1686104538

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _160_main();

int64_t _160_main() {
	int64_t _161_x;
	int64_t _160_t4;
	uint8_t _160_t2;
	int64_t _160_t8;
	int64_t _160_t9;
	int64_t _160_t10;
	uint8_t _160_t6;
	int64_t _160_t15;
	int64_t _160_t12;
	int64_t _160_$retval;
BB0:
	_161_x = 17;
	goto BB1;
BB1:
	_160_t4 = 36;
	_160_t2 = _161_x < _160_t4;
	if (!_160_t2) {
		goto BB17;
	} else {
		goto BB2;
	}
BB2:
	_160_t8 = 2;
	_160_t9 = _161_x % _160_t8;
	_160_t10 = 0;
	_160_t6 = _160_t9 == _160_t10;
	if (!_160_t6) {
		goto BB13;
	} else {
		goto BB8;
	}
BB8:
	_160_t15 = 9;
	_161_x = _161_x + _160_t15;
	goto BB1;
BB13:
	_160_t12 = 1;
	_161_x = _161_x + _160_t12;
	goto BB8;
BB17:
	_160_$retval = _161_x;
	return _160_$retval;
}


int main()
{
  printf("%ld",_160_main());
  return 0;
}

#endif
