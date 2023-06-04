/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685922416
#define ORNG_1685922416

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _23_main();

int64_t _23_main() {
	int64_t _23_t1;
	int64_t* _24_y;
	int64_t _23_t6;
	int64_t _23_t7;
	uint8_t _23_t4;
	int64_t _26_z;
	int64_t _23_t10;
	int64_t* _23_t11;
	int64_t _23_t14;
	int64_t _23_t23;
	int64_t _23_t24;
	int64_t _23_t28;
	int64_t _23_t29;
	int64_t _23_t32;
	int64_t _23_t33;
	double _23_t38;
	int64_t _23_t3;
	int64_t _23_$retval;
BB0:
	_23_t1 = 0;
	_24_y = &_23_t1;
	_23_t6 = *_24_y;
	_23_t7 = 0;
	_23_t4 = _23_t6 == _23_t7;
	if (!_23_t4) {
		goto BB9;
	} else {
		goto BB1;
	}
BB1:
	_26_z = *_24_y;
	_23_t10 = _26_z;
	_23_t14 = _26_z + _26_z;
	*(&_23_t10) = _23_t14;
	_26_z = _26_z - _26_z;
	_26_z = _26_z * _26_z;
	_23_t23 = 1;
	_23_t24 = _26_z + _23_t23;
	_26_z = _26_z / _23_t24;
	_23_t28 = 1;
	_23_t29 = _26_z + _23_t28;
	_26_z = _26_z % _23_t29;
	_23_t32 = 1;
	_23_t33 = _26_z + _23_t32;
	_26_z = powf(_26_z, _23_t33);
	_23_t38 = -1.0e+00;
	_26_z = _26_z * _23_t38;
	_23_t3 = _26_z;
	goto BB6;
BB6:
	_23_$retval = _23_t3;
	return _23_$retval;
BB9:
	_23_t3 = 1000;
	goto BB6;
}


int main()
{
  printf("%ld",_23_main());
  return 0;
}

#endif
