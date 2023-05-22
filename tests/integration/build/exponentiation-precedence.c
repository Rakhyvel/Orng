/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684727983
#define ORNG_1684727983

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
	int64_t _3;
	int64_t _4;
	int64_t _5;
BB0:;
	_0 = 3;
	_1 = 2;
	_2 = powf(_1, _0);
	_3 = 2;
	_4 = powf(_3, _2);
	_5 = -_4;
	retval = _5;
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
