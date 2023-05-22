/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684713966
#define ORNG_1684713966

#include <math.h>
#include <stdio.h>

/* Function Definitions */
int test_main();

int test_main() {
	// Bookkeeping
	int retval;
	int _0;
	int _42_x;
	int _1;
	int _2;
	int _3;
	int _4;
	int _5;
	int _6;
	int _7;
	int _8;
	int _9;
	int _10;
	int _11;
	int _12;
BB0:;
	_0 = 8;
	_42_x = _0;
	_1 = 2;
	_2 = _42_x + _1;
	_42_x = _2;
	_3 = 2;
	_4 = _42_x - _3;
	_42_x = _4;
	_5 = 2;
	_6 = _42_x * _5;
	_42_x = _6;
	_7 = 2;
	_8 = _42_x / _7;
	_42_x = _8;
	_9 = 15;
	_10 = _42_x % _9;
	_42_x = _10;
	_11 = 2;
	_12 = powf(_42_x, _11);
	_42_x = _12;
	retval = _42_x;
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
