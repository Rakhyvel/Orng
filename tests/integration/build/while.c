/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685912304
#define ORNG_1685912304

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _212_x;
	int64_t _213_i;
	int64_t _211_t5;
	uint8_t _211_t3;
	int64_t _211_t10;
	int64_t _211_$retval;
BB0:
	_212_x = 0;
	_213_i = 0;
	goto BB1;
BB1:
	_211_t5 = 10;
	_211_t3 = _213_i <= _211_t5;
	if (!_211_t3) {
		goto BB10;
	} else {
		goto BB2;
	}
BB2:
	_212_x = _212_x + _213_i;
	_211_t10 = 1;
	_213_i = _213_i + _211_t10;
	goto BB1;
BB10:
	_211_$retval = _212_x;
	return _211_$retval;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
