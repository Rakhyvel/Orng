/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684807658
#define ORNG_1684807658

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int64_t _0;
	int64_t _1;
	uint8_t _2;
BB0:;
	_0 = 4;
	_1 = 4;
	_2 = _0 != _1;
	retval = _2;
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
