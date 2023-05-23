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
	int64_t _46_x;
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
BB0:;
	_0 = 8;
	_46_x = _0;
	_1 = 2;
	_2 = _46_x + _1;
	_46_x = _2;
	_3 = 2;
	_4 = _46_x - _3;
	_46_x = _4;
	_5 = 2;
	_6 = _46_x * _5;
	_46_x = _6;
	_7 = 2;
	_8 = _46_x / _7;
	_46_x = _8;
	_9 = 15;
	_10 = _46_x % _9;
	_46_x = _10;
	_11 = 2;
	_12 = powf(_46_x, _11);
	_46_x = _12;
	retval = _46_x;
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
