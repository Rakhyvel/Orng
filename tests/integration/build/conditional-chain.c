/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684727983
#define ORNG_1684727983

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	double _0;
	double _17_x;
	uint8_t _1;
	double _2;
	uint8_t _3;
	double _4;
	uint8_t _5;
	double _6;
	uint8_t _7;
	double _8;
	uint8_t _9;
	double _10;
	uint8_t _11;
BB0:;
	_0 = 4.50005e+00;
	_17_x = _0;
	_2 = 0.0e+00;
	_3 = _2 < _17_x;
	if (!_3) {
		goto BB7;
	} else {
		goto BB1;
	}
BB1:;
	_4 = 3.0e+00;
	_5 = _17_x <= _4;
	if (!_5) {
		goto BB7;
	} else {
		goto BB2;
	}
BB2:;
	_6 = 3.0e+00;
	_7 = _4 == _6;
	if (!_7) {
		goto BB7;
	} else {
		goto BB3;
	}
BB3:;
	_8 = 2.0e+00;
	_9 = _6 > _8;
	if (!_9) {
		goto BB7;
	} else {
		goto BB4;
	}
BB4:;
	_10 = 1.0e+00;
	_11 = _8 >= _10;
	if (!_11) {
		goto BB7;
	} else {
		goto BB5;
	}
BB5:;
	_1 = 1;
	goto BB6;
BB6:;
	retval = _1;
	goto end;
BB7:;
	_1 = 0;
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
