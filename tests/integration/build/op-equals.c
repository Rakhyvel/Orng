/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685163890
#define ORNG_1685163890

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
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
	int64_t _45_t13;
	int64_t _45_t14;
	int64_t _45_t15;
	int64_t _45_t16;
	int64_t _45_t17;
	int64_t _45_t18;
	int64_t _45_t19;
	int64_t _45_$retval;
BB0: // 1
	_45_t0 = 8;
	_46_x = 8;
	_45_t1 = 8;
	_45_t2 = 2;
	_45_t3 = _45_t1 + _45_t2;
	_46_x = _45_t3;
	_45_t4 = _45_t3;
	_45_t5 = 2;
	_45_t6 = _45_t4 - _45_t5;
	_46_x = _45_t6;
	_45_t7 = _45_t6;
	_45_t8 = 2;
	_45_t9 = _45_t7 * _45_t8;
	_46_x = _45_t9;
	_45_t10 = _45_t9;
	_45_t11 = 2;
	_45_t12 = _45_t10 / _45_t11;
	_46_x = _45_t12;
	_45_t13 = _45_t12;
	_45_t14 = 15;
	_45_t15 = _45_t13 % _45_t14;
	_46_x = _45_t15;
	_45_t16 = 2;
	_45_t17 = _45_t15;
	_45_t18 = powf(_45_t17, _45_t16);
	_46_x = _45_t18;
	_45_t19 = _45_t18;
	_45_$retval = _45_t18;
	goto end;
end:
	return _45_$retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
