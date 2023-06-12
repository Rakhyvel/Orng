/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686537896
#define ORNG_1686537896

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();

/* Function forward definitions */
int64_t _9_main();

/* Function definitions */
int64_t _9_main() {
	int64_t _9_t1;
	int64_t* _10_y;
	int64_t _9_t6;
	int64_t _9_t7;
	uint8_t _9_t4;
	int64_t _12_z;
	int64_t _9_t10;
	int64_t* _9_t11;
	int64_t _9_t14;
	int64_t _9_t23;
	int64_t _9_t24;
	int64_t _9_t28;
	int64_t _9_t29;
	int64_t _9_t32;
	int64_t _9_t33;
	double _9_t38;
	int64_t _9_t3;
	int64_t _9_$retval;
BB0:
	_9_t1 = 0;
	_10_y = &_9_t1;
	_9_t6 = *_10_y;
	_9_t7 = 0;
	_9_t4 = _9_t6 == _9_t7;
	if (!_9_t4) {
		goto BB9;
	} else {
		goto BB1;
	}
BB1:
	_12_z = *_10_y;
	_9_t10 = _12_z;
	_9_t14 = _12_z + _12_z;
	*(&_9_t10) = _9_t14;
	_12_z = _12_z - _12_z;
	_12_z = _12_z * _12_z;
	_9_t23 = 1;
	_9_t24 = _12_z + _9_t23;
	_12_z = _12_z / _9_t24;
	_9_t28 = 1;
	_9_t29 = _12_z + _9_t28;
	_12_z = _12_z % _9_t29;
	_9_t32 = 1;
	_9_t33 = _12_z + _9_t32;
	_12_z = powf(_12_z, _9_t33);
	_9_t38 = -1.0e+00;
	_12_z = _12_z * _9_t38;
	_9_t3 = _12_z;
	goto BB6;
BB6:
	_9_$retval = _9_t3;
	return _9_$retval;
BB9:
	_9_t3 = 1000;
	goto BB6;
}


int main()
{
  printf("%ld",_9_main());
  return 0;
}

#endif
