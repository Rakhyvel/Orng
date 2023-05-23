/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684812568
#define ORNG_1684812568

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int64_t _0;
	int64_t _1;
	int64_t _2;
	int64_t _3_x;
BB0:;
	_0 = 20;
	_1 = 7;
	_2 = _0 + _1;
	_3_x = _2;
	retval = _3_x;
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
