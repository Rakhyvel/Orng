/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686537896
#define ORNG_1686537896

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();

/* Function forward definitions */
int64_t _16_main();

/* Function definitions */
int64_t _16_main() {
	int64_t _16_t1;
	int64_t* _16_t4;
	int64_t _16_t5;
	int64_t _16_t6;
	uint8_t _16_t3;
	uint8_t _16_t7;
	uint8_t _16_t9;
	uint8_t _16_t11;
	int64_t _16_t12;
	int64_t _16_$retval;
BB0:
	_16_t1 = 0;
	_16_t4 = &_16_t1;
	_16_t5 = *_16_t4;
	_16_t6 = 1;
	_16_t3 = _16_t5 == _16_t6;
	if (!_16_t3) {
		goto BB9;
	} else {
		goto BB1;
	}
BB1:
	_16_t3 = 1;
	goto BB2;
BB2:
	_16_t7 = !_16_t3;
	_16_t9 = !_16_t7;
	_16_t11 = !_16_t9;
	if (!_16_t11) {
		goto BB7;
	} else {
		goto BB3;
	}
BB3:
	_16_t12 = 31;
	goto BB6;
BB6:
	_16_$retval = _16_t12;
	return _16_$retval;
BB7:
	_16_t12 = 10;
	goto BB6;
BB9:
	_16_t3 = 0;
	goto BB2;
}


int main()
{
  printf("%ld",_16_main());
  return 0;
}

#endif
