/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685922416
#define ORNG_1685922416

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _219_main();

int64_t _219_main() {
	int64_t _220_x;
	int64_t _221_i;
	int64_t _219_t5;
	uint8_t _219_t3;
	int64_t _219_t10;
	int64_t _219_$retval;
BB0:
	_220_x = 0;
	_221_i = 0;
	goto BB1;
BB1:
	_219_t5 = 10;
	_219_t3 = _221_i <= _219_t5;
	if (!_219_t3) {
		goto BB10;
	} else {
		goto BB2;
	}
BB2:
	_220_x = _220_x + _221_i;
	_219_t10 = 1;
	_221_i = _221_i + _219_t10;
	goto BB1;
BB10:
	_219_$retval = _220_x;
	return _219_$retval;
}


int main()
{
  printf("%ld",_219_main());
  return 0;
}

#endif
