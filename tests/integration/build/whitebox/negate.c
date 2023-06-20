/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687227438
#define ORNG_1687227438

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _51_main();

/* Function definitions */
int64_t _51_main() {
	int64_t _52_x;
	int64_t* _51_t1;
	int64_t _51_t4;
	int64_t _51_t5;
	int64_t _51_t7;
	uint8_t _51_t3;
	int64_t _51_t2;
	int64_t _51_$retval;
BB0:
	_52_x = 1;
	_51_t1 = &_52_x;
	_51_t4 = *_51_t1;
	_51_t5 = -_51_t4;
	_51_t7 = -1;
	_51_t3 = _51_t5 == _51_t7;
	if (!_51_t3) {
		goto BB9;
	} else {
		goto BB1;
	}
BB1:
	_51_t2 = 32;
	goto BB6;
BB6:
	_51_$retval = _51_t2;
	return _51_$retval;
BB9:
	_51_t2 = 10;
	goto BB6;
}


int main()
{
  printf("%ld",_51_main());
  return 0;
}

#endif
