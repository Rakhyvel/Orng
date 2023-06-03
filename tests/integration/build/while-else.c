/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685778818
#define ORNG_1685778818

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _61_x;
	int64_t _59_t4;
	uint8_t _59_t2;
	int64_t _59_t6;
	int64_t _59_t10;
	int64_t _59_$retval;
BB0:
	_61_x = 0;
	goto BB1;
BB1:
	_59_t4 = 10;
	_59_t2 = _61_x < _59_t4;
	if (!_59_t2) {
		goto BB10;
	} else {
		goto BB2;
	}
BB2:
	_59_t6 = 1;
	_61_x = _61_x + _59_t6;
	_59_t10 = 1;
	_61_x = _61_x + _59_t10;
	goto BB1;
BB10:
	_59_$retval = _61_x;
	return _59_$retval;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
