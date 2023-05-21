/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684712155
#define ORNG_1684712155

#include <math.h>
#include <stdio.h>

/* Function Definitions */
int test_main();

int test_main() {
	// Bookkeeping
	int retval;
	int _0;
	int _38_x;
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
	_38_x = _0;
	_1 = 2;
	_2 = _38_x + _1;
	_38_x = _2;
	_3 = 2;
	_4 = _38_x - _3;
	_38_x = _4;
	_5 = 2;
	_6 = _38_x * _5;
	_38_x = _6;
	_7 = 2;
	_8 = _38_x / _7;
	_38_x = _8;
	_9 = 15;
	_10 = _38_x % _9;
	_38_x = _10;
	_11 = 2;
	_12 = powf(_38_x, _11);
	_38_x = _12;
	retval = _38_x;
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
