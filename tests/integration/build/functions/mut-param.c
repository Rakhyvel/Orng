/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687738073
#define ORNG_1687738073

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _223_main();
int64_t _224_sumDown(int64_t _224_x);

/* Function definitions */
int64_t _223_main() {
	int64_t _223_t1;
	int64_t _223_t0;
	int64_t _223_t2;
	int64_t _223_$retval;
BB0:
	_223_t1 = 8;
	_223_t0 = _224_sumDown(_223_t1);
	_223_t2 = 2;
	_223_$retval = _223_t0 + _223_t2;
	return _223_$retval;
}

int64_t _224_sumDown(int64_t _224_x) {
	int64_t _226_i;
	int64_t _224_t2;
	uint8_t _224_t1;
	int64_t _224_t4;
	int64_t _224_$retval;
BB0:
	_226_i = _224_x;
	goto BB1;
BB1:
	_224_t2 = 0;
	_224_t1 = _226_i >= _224_t2;
	if (!_224_t1) {
		goto BB10;
	} else {
		goto BB2;
	}
BB2:
	_224_x = _224_x + _226_i;
	_224_t4 = 1;
	_226_i = _226_i - _224_t4;
	goto BB1;
BB10:
	_224_$retval = _224_x;
	return _224_$retval;
}


int main()
{
  printf("%ld",_223_main());
  return 0;
}

#endif
