/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686104538
#define ORNG_1686104538

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _30_main();

int64_t _30_main() {
	int64_t _30_t1;
	int64_t* _31_y;
	int64_t _30_t6;
	int64_t _30_t7;
	uint8_t _30_t4;
	int64_t _33_z;
	int64_t _30_t10;
	int64_t* _30_t11;
	int64_t _30_t14;
	int64_t _30_t23;
	int64_t _30_t24;
	int64_t _30_t28;
	int64_t _30_t29;
	int64_t _30_t32;
	int64_t _30_t33;
	double _30_t38;
	int64_t _30_t3;
	int64_t _30_$retval;
BB0:
	_30_t1 = 0;
	_31_y = &_30_t1;
	_30_t6 = *_31_y;
	_30_t7 = 0;
	_30_t4 = _30_t6 == _30_t7;
	if (!_30_t4) {
		goto BB9;
	} else {
		goto BB1;
	}
BB1:
	_33_z = *_31_y;
	_30_t10 = _33_z;
	_30_t14 = _33_z + _33_z;
	*(&_30_t10) = _30_t14;
	_33_z = _33_z - _33_z;
	_33_z = _33_z * _33_z;
	_30_t23 = 1;
	_30_t24 = _33_z + _30_t23;
	_33_z = _33_z / _30_t24;
	_30_t28 = 1;
	_30_t29 = _33_z + _30_t28;
	_33_z = _33_z % _30_t29;
	_30_t32 = 1;
	_30_t33 = _33_z + _30_t32;
	_33_z = powf(_33_z, _30_t33);
	_30_t38 = -1.0e+00;
	_33_z = _33_z * _30_t38;
	_30_t3 = _33_z;
	goto BB6;
BB6:
	_30_$retval = _30_t3;
	return _30_$retval;
BB9:
	_30_t3 = 1000;
	goto BB6;
}


int main()
{
  printf("%ld",_30_main());
  return 0;
}

#endif
