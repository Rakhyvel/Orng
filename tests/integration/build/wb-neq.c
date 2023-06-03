/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685778818
#define ORNG_1685778818

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _13_t1;
	int64_t* _14_y;
	int64_t _13_t6;
	int64_t _13_t7;
	uint8_t _13_t8;
	int64_t _13_t3;
	int64_t _13_$retval;
	int64_t _13_t10;
	int64_t _13_t12;
	uint8_t _13_t9;
	double _13_t13;
BB0:
	_13_t1 = 3;
	_14_y = &_13_t1;
	_13_t6 = *_14_y;
	_13_t7 = 5;
	_13_t8 = _13_t6 != _13_t7;
	if (!_13_t8) {
		goto BB9;
	} else {
		goto BB3;
	}
BB3:
	_13_t3 = 33;
	goto BB6;
BB6:
	_13_$retval = _13_t3;
	return _13_$retval;
BB9:
	_13_t10 = 4;
	_13_t12 = *_14_y;
	_13_t9 = _13_t10 > _13_t12;
	if (!_13_t9) {
		goto BB13;
	} else {
		goto BB10;
	}
BB10:
	_13_t13 = 3.0e+00;
	_13_t9 = _13_t12 >= _13_t13;
	if (!_13_t9) {
		goto BB13;
	} else {
		goto BB3;
	}
BB13:
	_13_t3 = 10;
	goto BB6;
}

int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
