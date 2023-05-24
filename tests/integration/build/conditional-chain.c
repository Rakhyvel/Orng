/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684898822
#define ORNG_1684898822

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	double _16_t0;
	double _17_x;
	double _16_t2;
	uint8_t _16_t3;
	double _16_t4;
	uint8_t _16_t5;
	double _16_t6;
	uint8_t _16_t7;
	double _16_t8;
	uint8_t _16_t9;
	double _16_t10;
	uint8_t _16_t11;
	uint8_t _16_t1;
	uint8_t _0;
BB0: // 1
	_16_t0 = 4.50005e+00;
	_17_x = _16_t0;
	_16_t2 = 0.0e+00;
	_16_t3 = _16_t2 < _17_x;
	if (!_16_t3) {
		goto BB7;
	} else {
		goto BB1;
	}
BB1: // 1
	_16_t4 = 3.0e+00;
	_16_t5 = _17_x <= _16_t4;
	if (!_16_t5) {
		goto BB7;
	} else {
		goto BB2;
	}
BB2: // 1
	_16_t6 = 3.0e+00;
	_16_t7 = _16_t4 == _16_t6;
	if (!_16_t7) {
		goto BB7;
	} else {
		goto BB3;
	}
BB3: // 1
	_16_t8 = 2.0e+00;
	_16_t9 = _16_t6 > _16_t8;
	if (!_16_t9) {
		goto BB7;
	} else {
		goto BB4;
	}
BB4: // 1
	_16_t10 = 1.0e+00;
	_16_t11 = _16_t8 >= _16_t10;
	if (!_16_t11) {
		goto BB7;
	} else {
		goto BB5;
	}
BB5: // 1
	_16_t1 = 1;
	goto BB6;
BB6: // 2
	retval = _16_t1;
	goto end;
BB7: // 5
	_16_t1 = 0;
	goto BB6;
end:
	return retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
