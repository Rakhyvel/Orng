/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684895482
#define ORNG_1684895482

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int64_t _52_t0;
	int64_t _52_t1;
	uint8_t _52_t2;
	uint8_t _0;
BB0: // 1
	_52_t0 = 4;
	_52_t1 = 4;
	_52_t2 = _52_t0 != _52_t1;
	retval = _52_t2;
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
