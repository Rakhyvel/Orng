/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685775392
#define ORNG_1685775392

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _16_t1;
	int64_t* _17_y;
	int64_t _16_t6;
	int64_t _16_t7;
	uint8_t _16_t4;
	int64_t _19_z;
	int64_t _16_t12;
	int64_t _16_t15;
	int64_t _16_t17;
	int64_t _16_t18;
	int64_t _16_t19;
	int64_t _16_t21;
	int64_t _16_t22;
	int64_t _16_t24;
	int64_t _16_t25;
	int64_t _16_t26;
	int64_t _16_t27;
	int64_t _16_t3;
	int64_t _16_$retval;
BB0:
	_16_t1 = 0;
	_17_y = &_16_t1;
	_16_t6 = *_17_y;
	_16_t7 = 0;
	_16_t4 = _16_t6 == _16_t7;
	if (!_16_t4) {
		goto BB6;
	} else {
		goto BB1;
	}
BB1:
	_19_z = *_17_y;
	_16_t12 = _19_z + _19_z;
	_16_t15 = _19_z * _19_z;
	_16_t17 = 1;
	_16_t18 = _19_z + _16_t17;
	_16_t19 = _16_t15 / _16_t18;
	_16_t21 = 1;
	_16_t22 = _19_z + _16_t21;
	_16_t24 = 1;
	_16_t25 = _19_z + _16_t24;
	_16_t26 = powf(_16_t25, _16_t22);
	_16_t27 = _16_t19 % _16_t26;
	_16_t3 = _16_t12 - _16_t27;
	goto BB4;
BB4:
	_16_$retval = _16_t3;
	return _16_$retval;
BB6:
	_16_t3 = 1000;
	goto BB4;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
