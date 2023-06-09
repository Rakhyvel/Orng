/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686278317
#define ORNG_1686278317

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();

/* Function forward definitions */
int64_t _104_main();

/* Function definitions */
int64_t _104_main() {
	int64_t _105_x;
	int64_t _106_i;
	int64_t _104_t5;
	uint8_t _104_t3;
	int64_t _104_t9;
	int64_t _104_t10;
	int64_t _104_t11;
	uint8_t _104_t7;
	int64_t _104_t16;
	int64_t _104_t13;
	int64_t _104_$retval;
BB0:
	_105_x = 0;
	_106_i = 0;
	goto BB1;
BB1:
	_104_t5 = 70;
	_104_t3 = _106_i < _104_t5;
	if (!_104_t3) {
		goto BB16;
	} else {
		goto BB2;
	}
BB2:
	_104_t9 = 2;
	_104_t10 = _106_i % _104_t9;
	_104_t11 = 0;
	_104_t7 = _104_t10 == _104_t11;
	if (!_104_t7) {
		goto BB12;
	} else {
		goto BB8;
	}
BB8:
	_104_t16 = 1;
	_106_i = _106_i + _104_t16;
	goto BB1;
BB12:
	_104_t13 = 1;
	_105_x = _105_x + _104_t13;
	goto BB8;
BB16:
	_104_$retval = _105_x;
	return _104_$retval;
}


int main()
{
  printf("%ld",_104_main());
  return 0;
}

#endif
