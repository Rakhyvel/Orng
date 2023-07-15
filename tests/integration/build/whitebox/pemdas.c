/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688935488875353378
#define ORNG_1688935488875353378

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _3_x;
	int64_t* _3_y;
	int64_t _2_t4;
	int64_t _2_t5;
	uint8_t _2_t3;
	int64_t _5_z;
	int64_t* _2_t7;
	int64_t _2_t8;
	int64_t _2_t11;
	int64_t _2_t12;
	int64_t _2_t14;
	int64_t _2_t15;
	int64_t _2_t17;
	int64_t _2_t18;
	double _2_t21;
	int64_t _2_t2;
	int64_t _2_$retval;
BB0:
	_3_x = 0;
	_3_y = &_3_x;
	_2_t4 = *_3_y;
	_2_t5 = 0;
	_2_t3 = _2_t4 == _2_t5;
	if (_2_t3) {
		goto BB1;
	} else {
		goto BB9;
	}
BB9:
	_2_t2 = 1000;
	goto BB6;
BB6:
	_2_$retval = _2_t2;
	return _2_$retval;
BB1:
	_5_z = *_3_y;
	_2_t7 = _3_y;
	_2_t8 = _5_z + _5_z;
	**&_2_t7 = _2_t8;
	_5_z = _5_z - _5_z;
	_5_z = _5_z * _5_z;
	_2_t11 = 1;
	_2_t12 = _5_z + _2_t11;
	_5_z = _5_z / _2_t12;
	_2_t14 = 1;
	_2_t15 = _5_z + _2_t14;
	_5_z = _5_z % _2_t15;
	_2_t17 = 1;
	_2_t18 = _5_z + _2_t17;
	_5_z = powf(_5_z, _2_t18);
	_2_t21 = -1.0e+00;
	_5_z = _5_z * _2_t21;
	_2_t2 = _5_z;
	goto BB6;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
