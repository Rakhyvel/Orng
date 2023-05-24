/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684898822
#define ORNG_1684898822

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	uint8_t _25_t2;
	uint8_t _25_t3;
	uint8_t _25_t1;
	uint8_t _25_t4;
	uint8_t _25_t0;
	uint8_t _0;
BB0: // 1
	_25_t2 = 1;
	if (!_25_t2) {
		goto BB6;
	} else {
		goto BB1;
	}
BB1: // 1
	_25_t3 = 1;
	_25_t1 = _25_t3;
	goto BB2;
BB2: // 2
	if (!_25_t1) {
		goto BB5;
	} else {
		goto BB3;
	}
BB3: // 1
	_25_t4 = 1;
	_25_t0 = _25_t4;
	goto BB4;
BB4: // 2
	retval = _25_t0;
	goto end;
BB5: // 1
	_25_t0 = 0;
	goto BB4;
BB6: // 1
	_25_t1 = 0;
	goto BB2;
end:
	return retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
