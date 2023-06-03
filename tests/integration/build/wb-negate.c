/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685775392
#define ORNG_1685775392

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _45_t1;
	int64_t* _45_t5;
	int64_t _45_t6;
	int64_t _45_t7;
	int64_t _45_t9;
	uint8_t _45_t4;
	int64_t _45_t3;
	int64_t _45_$retval;
BB0:
	_45_t1 = 1;
	_45_t5 = &_45_t1;
	_45_t6 = *_45_t5;
	_45_t7 = -_45_t6;
	_45_t9 = -1;
	_45_t4 = _45_t7 == _45_t9;
	if (!_45_t4) {
		goto BB6;
	} else {
		goto BB1;
	}
BB1:
	_45_t3 = 32;
	goto BB4;
BB4:
	_45_$retval = _45_t3;
	return _45_$retval;
BB6:
	_45_t3 = 10;
	goto BB4;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
