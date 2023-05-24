/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684897129
#define ORNG_1684897129

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	uint8_t _124_t1;
	int64_t _124_t4;
	int64_t _0;
	uint8_t _124_t2;
	uint8_t _124_t3;
BB1: // 1
	_124_t1 = 0;
	if (!_124_t1) {
		goto BB5;
	} else {
		goto BB4;
	}
BB4: // 3
	_124_t4 = 25;
	retval = _124_t4;
	goto end;
BB5: // 1
	_124_t2 = 0;
	if (!_124_t2) {
		goto BB8;
	} else {
		goto BB4;
	}
BB8: // 1
	_124_t3 = 1;
	goto BB4;
end:
	return retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
