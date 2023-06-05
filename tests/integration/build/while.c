/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685933745
#define ORNG_1685933745

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _232_main();

int64_t _232_main() {
	int64_t _233_x;
	int64_t _234_i;
	int64_t _232_t5;
	uint8_t _232_t3;
	int64_t _232_t10;
	int64_t _232_$retval;
BB0:
	_233_x = 0;
	_234_i = 0;
	goto BB1;
BB1:
	_232_t5 = 10;
	_232_t3 = _234_i <= _232_t5;
	if (!_232_t3) {
		goto BB10;
	} else {
		goto BB2;
	}
BB2:
	_233_x = _233_x + _234_i;
	_232_t10 = 1;
	_234_i = _234_i + _232_t10;
	goto BB1;
BB10:
	_232_$retval = _233_x;
	return _232_$retval;
}


int main()
{
  printf("%ld",_232_main());
  return 0;
}

#endif
