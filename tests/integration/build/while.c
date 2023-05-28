/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685256120
#define ORNG_1685256120

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _165_x;
	int64_t _166_i;
	int64_t _164_t5;
	uint8_t _164_t3;
	int64_t _164_t10;
	int64_t _164_$retval;
BB0:
	_165_x = 0;
	_166_i = 0;
	goto BB1;
BB1:
	_164_t5 = 10;
	_164_t3 = _166_i <= _164_t5;
	if (!_164_t3) {
		goto BB7;
	} else {
		goto BB2;
	}
BB2:
	_165_x = _165_x + _166_i;
	_164_t10 = 1;
	_166_i = _166_i + _164_t10;
	goto BB1;
BB7:
	_164_$retval = _165_x;
	return _164_$retval;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
