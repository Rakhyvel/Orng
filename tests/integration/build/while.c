/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686104538
#define ORNG_1686104538

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _255_main();

int64_t _255_main() {
	int64_t _256_x;
	int64_t _257_i;
	int64_t _255_t5;
	uint8_t _255_t3;
	int64_t _255_t10;
	int64_t _255_$retval;
BB0:
	_256_x = 0;
	_257_i = 0;
	goto BB1;
BB1:
	_255_t5 = 10;
	_255_t3 = _257_i <= _255_t5;
	if (!_255_t3) {
		goto BB10;
	} else {
		goto BB2;
	}
BB2:
	_256_x = _256_x + _257_i;
	_255_t10 = 1;
	_257_i = _257_i + _255_t10;
	goto BB1;
BB10:
	_255_$retval = _256_x;
	return _255_$retval;
}


int main()
{
  printf("%ld",_255_main());
  return 0;
}

#endif
