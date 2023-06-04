/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685915967
#define ORNG_1685915967

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _127_x;
	int64_t _126_t4;
	uint8_t _126_t2;
	int64_t _126_t8;
	int64_t _126_t9;
	int64_t _126_t10;
	uint8_t _126_t6;
	int64_t _126_t15;
	int64_t _126_t12;
	int64_t _126_$retval;
BB0:
	_127_x = 17;
	goto BB1;
BB1:
	_126_t4 = 36;
	_126_t2 = _127_x < _126_t4;
	if (!_126_t2) {
		goto BB17;
	} else {
		goto BB2;
	}
BB2:
	_126_t8 = 2;
	_126_t9 = _127_x % _126_t8;
	_126_t10 = 0;
	_126_t6 = _126_t9 == _126_t10;
	if (!_126_t6) {
		goto BB13;
	} else {
		goto BB8;
	}
BB8:
	_126_t15 = 9;
	_127_x = _127_x + _126_t15;
	goto BB1;
BB13:
	_126_t12 = 1;
	_127_x = _127_x + _126_t12;
	goto BB8;
BB17:
	_126_$retval = _127_x;
	return _126_$retval;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
