/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685753088
#define ORNG_1685753088

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _2_t1;
	int64_t* _2_t5;
	int64_t _2_t6;
	int64_t _2_t7;
	uint8_t _2_t4;
	uint8_t _2_t8;
	int64_t _2_t3;
	int64_t _2_$retval;
BB0:
	_2_t1 = 0;
	_2_t5 = &_2_t1;
	_2_t6 = *_2_t5;
	_2_t7 = 1;
	_2_t4 = _2_t6 == _2_t7;
	if (!_2_t4) {
		goto BB6;
	} else {
		goto BB1;
	}
BB1:
	_2_t4 = 1;
	goto BB2;
BB2:
	_2_t8 = !_2_t4;
	if (!_2_t8) {
		goto BB5;
	} else {
		goto BB3;
	}
BB3:
	_2_t3 = 31;
	goto BB4;
BB4:
	_2_$retval = _2_t3;
	return _2_$retval;
BB5:
	_2_t3 = 10;
	goto BB4;
BB6:
	_2_t4 = 0;
	goto BB2;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
