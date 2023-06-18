/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687128100
#define ORNG_1687128100

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _24_main();
int64_t _25_sumDown(int64_t x);

/* Function definitions */
int64_t _24_main() {
	int64_t _24_t1;
	int64_t _24_t0;
	int64_t _24_t2;
	int64_t _24_$retval;
BB0:
	_24_t1 = 8;
	_24_t0 = _25_sumDown(_24_t1);
	_24_t2 = 2;
	_24_$retval = _24_t0 + _24_t2;
	return _24_$retval;
}

int64_t _25_sumDown(int64_t x) {
	int64_t _27_i;
	int64_t _25_t2;
	uint8_t _25_t1;
	int64_t _25_t4;
	int64_t _25_$retval;
BB0:
	_27_i = x;
	goto BB1;
BB1:
	_25_t2 = 0;
	_25_t1 = _27_i >= _25_t2;
	if (!_25_t1) {
		goto BB10;
	} else {
		goto BB2;
	}
BB2:
	x = x + _27_i;
	_25_t4 = 1;
	_27_i = _27_i - _25_t4;
	goto BB1;
BB10:
	_25_$retval = x;
	return _25_$retval;
}


int main()
{
  printf("%ld",_24_main());
  return 0;
}

#endif
