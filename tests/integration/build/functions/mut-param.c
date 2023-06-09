/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686278317
#define ORNG_1686278317

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();
typedef int64_t(*function1)(int64_t);

/* Function forward definitions */
int64_t _207_main();
int64_t _208_sumDown(int64_t x);

/* Function definitions */
int64_t _207_main() {
	function1 _207_t0;
	int64_t _207_t2;
	int64_t _207_t1;
	int64_t _207_t3;
	int64_t _207_$retval;
BB0:
	_207_t0 = _208_sumDown;
	_207_t2 = 8;
	_207_t1 = _207_t0(_207_t2);
	_207_t3 = 2;
	_207_$retval = _207_t1 + _207_t3;
	return _207_$retval;
}

int64_t _208_sumDown(int64_t x) {
	int64_t _210_i;
	int64_t _208_t4;
	uint8_t _208_t2;
	int64_t _208_t9;
	int64_t _208_$retval;
BB0:
	_210_i = x;
	goto BB1;
BB1:
	_208_t4 = 0;
	_208_t2 = _210_i >= _208_t4;
	if (!_208_t2) {
		goto BB10;
	} else {
		goto BB2;
	}
BB2:
	x = x + _210_i;
	_208_t9 = 1;
	_210_i = _210_i - _208_t9;
	goto BB1;
BB10:
	_208_$retval = x;
	return _208_$retval;
}


int main()
{
  printf("%ld",_207_main());
  return 0;
}

#endif
