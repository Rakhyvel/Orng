/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686513839
#define ORNG_1686513839

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();

/* Function forward definitions */
int64_t _61_main();

/* Function definitions */
int64_t _61_main() {
	uint8_t _62_found;
	int64_t _63_n;
	int64_t _61_t5;
	uint8_t _61_t3;
	int64_t _61_t12;
	uint8_t _61_t10;
	int64_t _61_t15;
	int64_t _61_t17;
	int64_t _61_$retval;
BB0:
	_62_found = 0;
	_63_n = 0;
	goto BB1;
BB1:
	_61_t5 = 10;
	_61_t3 = _63_n < _61_t5;
	if (!_61_t3) {
		goto BB26;
	} else {
		goto BB2;
	}
BB2:
	if (!_62_found) {
		goto BB7;
	} else {
		goto BB5;
	}
BB5:
	_63_n = 100;
	goto BB7;
BB7:
	_61_t12 = 6;
	_61_t10 = _63_n == _61_t12;
	if (!_61_t10) {
		goto BB13;
	} else {
		goto BB8;
	}
BB8:
	_62_found = 1;
	goto BB13;
BB13:
	_61_t15 = 1;
	_63_n = _63_n + _61_t15;
	goto BB1;
BB26:
	if (!_62_found) {
		goto BB24;
	} else {
		goto BB20;
	}
BB20:
	_61_t17 = 15;
	goto BB23;
BB23:
	_61_$retval = _61_t17;
	return _61_$retval;
BB24:
	_61_t17 = 4;
	goto BB23;
}


int main()
{
  printf("%ld",_61_main());
  return 0;
}

#endif