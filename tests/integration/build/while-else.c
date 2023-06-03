/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685775392
#define ORNG_1685775392

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _54_x;
	int64_t _52_t4;
	uint8_t _52_t2;
	int64_t _52_t6;
	int64_t _52_t0;
	int64_t _52_t10;
	int64_t _52_$retval;
BB0:
	_54_x = 0;
	goto BB1;
BB1:
	_52_t4 = 10;
	_52_t2 = _54_x < _52_t4;
	if (!_52_t2) {
		goto BB7;
	} else {
		goto BB2;
	}
BB2:
	_52_t6 = 1;
	_54_x = _54_x + _52_t6;
	_52_t0 = 0;
	_52_t10 = 1;
	_54_x = _54_x + _52_t10;
	goto BB1;
BB7:
	_52_t0 = _54_x;
	_52_$retval = _52_t0;
	return _52_$retval;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
