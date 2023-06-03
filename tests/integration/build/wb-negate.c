/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685778818
#define ORNG_1685778818

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _52_t1;
	int64_t* _52_t5;
	int64_t _52_t6;
	int64_t _52_t7;
	int64_t _52_t9;
	uint8_t _52_t4;
	int64_t _52_t3;
	int64_t _52_$retval;
BB0:
	_52_t1 = 1;
	_52_t5 = &_52_t1;
	_52_t6 = *_52_t5;
	_52_t7 = -_52_t6;
	_52_t9 = -1;
	_52_t4 = _52_t7 == _52_t9;
	if (!_52_t4) {
		goto BB9;
	} else {
		goto BB1;
	}
BB1:
	_52_t3 = 32;
	goto BB6;
BB6:
	_52_$retval = _52_t3;
	return _52_$retval;
BB9:
	_52_t3 = 10;
	goto BB6;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
