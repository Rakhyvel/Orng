/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686278317
#define ORNG_1686278317

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();

/* Function forward definitions */
int64_t _89_main();

/* Function definitions */
int64_t _89_main() {
	int64_t _91_x;
	int64_t _89_t4;
	uint8_t _89_t2;
	int64_t _89_t6;
	int64_t _89_t10;
	int64_t _89_$retval;
BB0:
	_91_x = 0;
	goto BB1;
BB1:
	_89_t4 = 10;
	_89_t2 = _91_x < _89_t4;
	if (!_89_t2) {
		goto BB11;
	} else {
		goto BB2;
	}
BB2:
	_89_t6 = 1;
	_91_x = _91_x + _89_t6;
	_89_t10 = 1;
	_91_x = _91_x + _89_t10;
	goto BB1;
BB11:
	_89_$retval = _91_x;
	return _89_$retval;
}


int main()
{
  printf("%ld",_89_main());
  return 0;
}

#endif
