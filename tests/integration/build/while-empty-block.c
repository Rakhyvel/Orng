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
	uint8_t _87_t1;
	int64_t _87_t2;
	int64_t _0;
BB1: // 2
	_87_t1 = 0;
	if (!_87_t1) {
		goto BB4;
	} else {
		goto BB1;
	}
BB4: // 1
	_87_t2 = 25;
	retval = _87_t2;
	goto end;
end:
	return retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
