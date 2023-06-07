/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686104538
#define ORNG_1686104538

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _201_main();

int64_t _201_main() {
	uint8_t _202_found;
	int64_t _203_n;
	int64_t _201_t5;
	uint8_t _201_t3;
	int64_t _201_t12;
	uint8_t _201_t10;
	int64_t _201_t15;
	int64_t _201_t17;
	int64_t _201_$retval;
BB0:
	_202_found = 0;
	_203_n = 0;
	goto BB1;
BB1:
	_201_t5 = 10;
	_201_t3 = _203_n < _201_t5;
	if (!_201_t3) {
		goto BB26;
	} else {
		goto BB2;
	}
BB2:
	if (!_202_found) {
		goto BB7;
	} else {
		goto BB5;
	}
BB5:
	_203_n = 100;
	goto BB7;
BB7:
	_201_t12 = 6;
	_201_t10 = _203_n == _201_t12;
	if (!_201_t10) {
		goto BB13;
	} else {
		goto BB8;
	}
BB8:
	_202_found = 1;
	goto BB13;
BB13:
	_201_t15 = 1;
	_203_n = _203_n + _201_t15;
	goto BB1;
BB26:
	if (!_202_found) {
		goto BB24;
	} else {
		goto BB20;
	}
BB20:
	_201_t17 = 15;
	goto BB23;
BB23:
	_201_$retval = _201_t17;
	return _201_$retval;
BB24:
	_201_t17 = 4;
	goto BB23;
}


int main()
{
  printf("%ld",_201_main());
  return 0;
}

#endif
