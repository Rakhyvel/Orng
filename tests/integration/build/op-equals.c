/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684898822
#define ORNG_1684898822

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int64_t _45_t0;
	int64_t _46_x;
	int64_t _45_t1;
	int64_t _45_t2;
	int64_t _45_t3;
	int64_t _45_t4;
	int64_t _45_t5;
	int64_t _45_t6;
	int64_t _45_t7;
	int64_t _45_t8;
	int64_t _45_t9;
	int64_t _45_t10;
	int64_t _45_t11;
	int64_t _45_t12;
	int64_t _0;
BB0: // 1
	_45_t0 = 8;
	_46_x = _45_t0;
	_45_t1 = 2;
	_45_t2 = _46_x + _45_t1;
	_46_x = _45_t2;
	_45_t3 = 2;
	_45_t4 = _46_x - _45_t3;
	_46_x = _45_t4;
	_45_t5 = 2;
	_45_t6 = _46_x * _45_t5;
	_46_x = _45_t6;
	_45_t7 = 2;
	_45_t8 = _46_x / _45_t7;
	_46_x = _45_t8;
	_45_t9 = 15;
	_45_t10 = _46_x % _45_t9;
	_46_x = _45_t10;
	_45_t11 = 2;
	_45_t12 = powf(_46_x, _45_t11);
	_46_x = _45_t12;
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
