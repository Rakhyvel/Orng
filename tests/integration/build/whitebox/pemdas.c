/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686712671
#define ORNG_1686712671

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();

/* Function forward definitions */
int64_t _9_main();

/* Function definitions */
int64_t _9_main() {
	int64_t _10_x;
	int64_t* _10_y;
	int64_t _9_t4;
	int64_t _9_t5;
	uint8_t _9_t3;
	int64_t _12_z;
	int64_t* _9_t7;
	int64_t _9_t8;
	int64_t _9_t11;
	int64_t _9_t12;
	int64_t _9_t14;
	int64_t _9_t15;
	int64_t _9_t17;
	int64_t _9_t18;
	double _9_t21;
	int64_t _9_t2;
	int64_t _9_$retval;
BB0:
	_10_x = 0;
	_10_y = &_10_x;
	_9_t4 = *_10_y;
	_9_t5 = 0;
	_9_t3 = _9_t4 == _9_t5;
	if (!_9_t3) {
		goto BB9;
	} else {
		goto BB1;
	}
BB1:
	_12_z = *_10_y;
	_9_t8 = _12_z + _12_z;
	*(&_12_z) = _9_t8;
	_12_z = _12_z - _12_z;
	_12_z = _12_z * _12_z;
	_9_t11 = 1;
	_9_t12 = _12_z + _9_t11;
	_12_z = _12_z / _9_t12;
	_9_t14 = 1;
	_9_t15 = _12_z + _9_t14;
	_12_z = _12_z % _9_t15;
	_9_t17 = 1;
	_9_t18 = _12_z + _9_t17;
	_12_z = powf(_12_z, _9_t18);
	_9_t21 = -1.0e+00;
	_12_z = _12_z * _9_t21;
	_9_t2 = _12_z;
	goto BB6;
BB6:
	_9_$retval = _9_t2;
	return _9_$retval;
BB9:
	_9_t2 = 1000;
	goto BB6;
}


int main()
{
  printf("%ld",_9_main());
  return 0;
}

#endif
