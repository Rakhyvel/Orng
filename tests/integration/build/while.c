/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685778818
#define ORNG_1685778818

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _171_x;
	int64_t _172_i;
	int64_t _170_t5;
	uint8_t _170_t3;
	int64_t _170_t10;
	int64_t _170_$retval;
BB0:
	_171_x = 0;
	_172_i = 0;
	goto BB1;
BB1:
	_170_t5 = 10;
	_170_t3 = _172_i <= _170_t5;
	if (!_170_t3) {
		goto BB9;
	} else {
		goto BB2;
	}
BB2:
	_171_x = _171_x + _172_i;
	_170_t10 = 1;
	_172_i = _172_i + _170_t10;
	goto BB1;
BB9:
	_170_$retval = _171_x;
	return _170_$retval;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
