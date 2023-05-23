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
	int64_t _2;
	int64_t _3;
	int64_t _4;
	int64_t _5;
	int64_t _6;
	int64_t _7;
	int64_t _8;
	int64_t _9;
	int64_t _10;
	int64_t _11;
	int64_t _12;
	int64_t _13;
	int64_t _14;
BB0:;
	_0 = 4;
	_1 = 7;
	_2 = _0 + _1;
	_3 = 4;
	_4 = 2;
	_5 = _3 / _4;
	_6 = _2 * _5;
	_7 = 3;
	_8 = 3;
	_9 = powf(_8, _7);
	_10 = 4;
	_11 = _9 % _10;
	_12 = _6 - _11;
	_13 = 19;
	_14 = _12 - _13;
	retval = _14;
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
