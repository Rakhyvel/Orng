/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685902519
#define ORNG_1685902519

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _179_x;
	int64_t _180_i;
	int64_t _178_t5;
	uint8_t _178_t3;
	int64_t _178_t10;
	int64_t _178_$retval;
BB0:
	_179_x = 0;
	_180_i = 0;
	goto BB1;
BB1:
	_178_t5 = 10;
	_178_t3 = _180_i <= _178_t5;
	if (!_178_t3) {
		goto BB10;
	} else {
		goto BB2;
	}
BB2:
	_179_x = _179_x + _180_i;
	_178_t10 = 1;
	_180_i = _180_i + _178_t10;
	goto BB1;
BB10:
	_178_$retval = _179_x;
	return _178_$retval;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
