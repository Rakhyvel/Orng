/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1691899681449729182
#define ORNG_1691899681449729182

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include<stdlib.h>

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
	int64_t _2_t3;
	uint8_t _2_t2;
	int64_t _2_t6;
	int64_t _2_t7;
	int64_t _2_t8;
	uint8_t _2_t5;
	int64_t _2_t11;
	int64_t _2_t9;
	int64_t _2_$retval;
BB0:
	_3_x = 17;
	goto BB1;
BB1:
	_2_t3 = 36;
	_2_t2 = _3_x < _2_t3;
	if (_2_t2) {
		goto BB2;
	} else {
		goto BB17;
	}
BB17:
	_2_$retval = _3_x;
	return _2_$retval;
BB2:
	_2_t6 = 2;
	_2_t7 = _3_x % _2_t6;
	_2_t8 = 0;
	_2_t5 = _2_t7 == _2_t8;
	if (_2_t5) {
		goto BB8;
	} else {
		goto BB13;
	}
BB13:
	_2_t9 = 1;
	_3_x = _3_x + _2_t9;
	goto BB8;
BB8:
	_2_t11 = 9;
	_3_x = _3_x + _2_t11;
	goto BB1;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
