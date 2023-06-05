/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685933745
#define ORNG_1685933745

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _178_main();

int64_t _178_main() {
	uint8_t _179_found;
	int64_t _180_n;
	int64_t _178_t5;
	uint8_t _178_t3;
	int64_t _178_t12;
	uint8_t _178_t10;
	int64_t _178_t15;
	int64_t _178_t17;
	int64_t _178_$retval;
BB0:
	_179_found = 0;
	_180_n = 0;
	goto BB1;
BB1:
	_178_t5 = 10;
	_178_t3 = _180_n < _178_t5;
	if (!_178_t3) {
		goto BB26;
	} else {
		goto BB2;
	}
BB2:
	if (!_179_found) {
		goto BB7;
	} else {
		goto BB5;
	}
BB5:
	_180_n = 100;
	goto BB7;
BB7:
	_178_t12 = 6;
	_178_t10 = _180_n == _178_t12;
	if (!_178_t10) {
		goto BB13;
	} else {
		goto BB8;
	}
BB8:
	_179_found = 1;
	goto BB13;
BB13:
	_178_t15 = 1;
	_180_n = _180_n + _178_t15;
	goto BB1;
BB26:
	if (!_179_found) {
		goto BB24;
	} else {
		goto BB20;
	}
BB20:
	_178_t17 = 15;
	goto BB23;
BB23:
	_178_$retval = _178_t17;
	return _178_$retval;
BB24:
	_178_t17 = 4;
	goto BB23;
}


int main()
{
  printf("%ld",_178_main());
  return 0;
}

#endif
