/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684986347
#define ORNG_1684986347

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int64_t _13_t0;
	int64_t _13_t1;
	int64_t _13_t2;
	int64_t _13_t3;
	int64_t _13_t4;
	int64_t _13_t5;
	int64_t _13_t6;
	int64_t _13_t7;
	int64_t _13_t8;
	int64_t _13_t9;
	int64_t _13_t10;
	int64_t _13_t11;
	int64_t _13_t12;
	int64_t _13_t13;
	int64_t _13_t14;
	int64_t _0;
BB0: // 1
	_13_t0 = 4;
	_13_t1 = 7;
	_13_t2 = _13_t0 + _13_t1;
	_13_t3 = 4;
	_13_t4 = 2;
	_13_t5 = _13_t3 / _13_t4;
	_13_t6 = _13_t2 * _13_t5;
	_13_t7 = 3;
	_13_t8 = 3;
	_13_t9 = powf(_13_t8, _13_t7);
	_13_t10 = 4;
	_13_t11 = _13_t9 % _13_t10;
	_13_t12 = _13_t6 - _13_t11;
	_13_t13 = 19;
	_13_t14 = _13_t12 - _13_t13;
	retval = _13_t14;
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
