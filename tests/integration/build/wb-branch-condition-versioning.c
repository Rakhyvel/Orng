/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685922416
#define ORNG_1685922416

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _165_main();

int64_t _165_main() {
	uint8_t _166_found;
	int64_t _167_n;
	int64_t _165_t5;
	uint8_t _165_t3;
	int64_t _165_t12;
	uint8_t _165_t10;
	int64_t _165_t15;
	int64_t _165_t17;
	int64_t _165_$retval;
BB0:
	_166_found = 0;
	_167_n = 0;
	goto BB1;
BB1:
	_165_t5 = 10;
	_165_t3 = _167_n < _165_t5;
	if (!_165_t3) {
		goto BB26;
	} else {
		goto BB2;
	}
BB2:
	if (!_166_found) {
		goto BB7;
	} else {
		goto BB5;
	}
BB5:
	_167_n = 100;
	goto BB7;
BB7:
	_165_t12 = 6;
	_165_t10 = _167_n == _165_t12;
	if (!_165_t10) {
		goto BB13;
	} else {
		goto BB8;
	}
BB8:
	_166_found = 1;
	goto BB13;
BB13:
	_165_t15 = 1;
	_167_n = _167_n + _165_t15;
	goto BB1;
BB26:
	if (!_166_found) {
		goto BB24;
	} else {
		goto BB20;
	}
BB20:
	_165_t17 = 15;
	goto BB23;
BB23:
	_165_$retval = _165_t17;
	return _165_$retval;
BB24:
	_165_t17 = 4;
	goto BB23;
}


int main()
{
  printf("%ld",_165_main());
  return 0;
}

#endif
