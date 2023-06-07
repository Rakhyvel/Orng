/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686104538
#define ORNG_1686104538

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _102_main();
int64_t _103_sumDown(int64_t x);

int64_t _102_main() {
	int64_t (*_102_t0)(int64_t x);
	int64_t _102_t2;
	int64_t _102_t1;
	int64_t _102_t3;
	int64_t _102_$retval;
BB0:
	_102_t0 = _103_sumDown;
	_102_t2 = 8;
	_102_t1 = _102_t0(_102_t2);
	_102_t3 = 2;
	_102_$retval = _102_t1 + _102_t3;
	return _102_$retval;
}

int64_t _103_sumDown(int64_t x) {
	int64_t _105_i;
	int64_t _103_t4;
	uint8_t _103_t2;
	int64_t _103_t9;
	int64_t _103_$retval;
BB0:
	_105_i = x;
	goto BB1;
BB1:
	_103_t4 = 0;
	_103_t2 = _105_i >= _103_t4;
	if (!_103_t2) {
		goto BB10;
	} else {
		goto BB2;
	}
BB2:
	x = x + _105_i;
	_103_t9 = 1;
	_105_i = _105_i - _103_t9;
	goto BB1;
BB10:
	_103_$retval = x;
	return _103_$retval;
}


int main()
{
  printf("%ld",_102_main());
  return 0;
}

#endif
