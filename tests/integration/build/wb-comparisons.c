/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685753088
#define ORNG_1685753088

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _139_t1;
	int64_t* _140_y;
	int64_t _139_t6;
	int64_t _139_t7;
	uint8_t _139_t8;
	int64_t _139_t3;
	int64_t _139_$retval;
	int64_t _139_t10;
	int64_t _139_t12;
	uint8_t _139_t9;
	double _139_t13;
BB0:
	_139_t1 = 3;
	_140_y = &_139_t1;
	_139_t6 = *_140_y;
	_139_t7 = 5;
	_139_t8 = _139_t6 != _139_t7;
	if (!_139_t8) {
		goto BB6;
	} else {
		goto BB3;
	}
BB3:
	_139_t3 = 33;
	goto BB4;
BB4:
	_139_$retval = _139_t3;
	return _139_$retval;
BB6:
	_139_t10 = 4;
	_139_t12 = *_140_y;
	_139_t9 = _139_t10 > _139_t12;
	if (!_139_t9) {
		goto BB10;
	} else {
		goto BB7;
	}
BB7:
	_139_t13 = 3.0e+00;
	_139_t9 = _139_t12 >= _139_t13;
	if (!_139_t9) {
		goto BB10;
	} else {
		goto BB3;
	}
BB10:
	_139_t3 = 10;
	goto BB4;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
