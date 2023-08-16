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
	int64_t _4_x;
	int64_t _2_t3;
	uint8_t _2_t2;
	int64_t _2_t4;
	int64_t _2_t7;
	int64_t _2_$retval;
BB0:
	_4_x = 0;
	goto BB1;
BB1:
	_2_t3 = 10;
	_2_t2 = _4_x < _2_t3;
	if (_2_t2) {
		goto BB2;
	} else {
		goto BB11;
	}
BB11:
	_2_$retval = _4_x;
	return _2_$retval;
BB2:
	_2_t4 = 1;
	_4_x = _4_x + _2_t4;
	_2_t7 = 1;
	_4_x = _4_x + _2_t7;
	goto BB1;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
