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
int64_t _52_main();

/* Function definitions */
int64_t _52_main() {
	int64_t _53_x;
	int64_t* _53_y;
	int64_t _52_t3;
	int64_t _52_t4;
	uint8_t _52_t2;
	uint8_t _52_t5;
	uint8_t _52_t6;
	uint8_t _52_t7;
	int64_t _52_t8;
	int64_t _52_$retval;
BB0:
	_53_x = 0;
	_53_y = &_53_x;
	_52_t3 = *_53_y;
	_52_t4 = 1;
	_52_t2 = _52_t3 == _52_t4;
	if (_52_t2) {
		goto BB1;
	} else {
		goto BB9;
	}
BB9:
	_52_t2 = 0;
	goto BB2;
BB2:
	_52_t5 = !_52_t2;
	_52_t6 = !_52_t5;
	_52_t7 = !_52_t6;
	if (_52_t7) {
		goto BB3;
	} else {
		goto BB7;
	}
BB7:
	_52_t8 = 10;
	goto BB6;
BB6:
	_52_$retval = _52_t8;
	return _52_$retval;
BB3:
	_52_t8 = 31;
	goto BB6;
BB1:
	_52_t2 = 1;
	goto BB2;
}


int main()
{
  printf("%ld",_52_main());
  return 0;
}

#endif
