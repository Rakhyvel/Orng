/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686023172
#define ORNG_1686023172

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _70_main();

int64_t _70_main() {
	int64_t _72_x;
	int64_t _70_t4;
	uint8_t _70_t2;
	int64_t _70_t6;
	int64_t _70_t10;
	int64_t _70_$retval;
BB0:
	_72_x = 0;
	goto BB1;
BB1:
	_70_t4 = 10;
	_70_t2 = _72_x < _70_t4;
	if (!_70_t2) {
		goto BB11;
	} else {
		goto BB2;
	}
BB2:
	_70_t6 = 1;
	_72_x = _72_x + _70_t6;
	_70_t10 = 1;
	_72_x = _72_x + _70_t10;
	goto BB1;
BB11:
	_70_$retval = _72_x;
	return _70_$retval;
}


int main()
{
  printf("%ld",_70_main());
  return 0;
}

#endif
