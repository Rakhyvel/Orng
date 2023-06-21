/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687313476
#define ORNG_1687313476

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _10_main();

/* Function definitions */
int64_t _10_main() {
	int64_t _10_t1;
	int64_t _10_t2;
	struct1 _11_x;
	struct1* _10_t3;
	struct1 _10_t4;
	int64_t _10_t5;
	struct1 _10_t6;
	int64_t _10_t7;
	struct1 _10_t8;
	int64_t _10_t9;
	int64_t _10_$retval;
BB0:
	_10_t1 = 11;
	_10_t2 = 11;
	_11_x = (struct1) {_10_t1, _10_t2};
	_10_t3 = &_11_x;
	_10_t5 = 50;
	(_10_t3)->_0 = _10_t5;
	_10_t6 = *_10_t3;
	_10_t7 = *&((_10_t3)->_0);
	_10_t8 = *_10_t3;
	_10_t9 = *&((_10_t3)->_1);
	_10_$retval = _10_t7 + _10_t9;
	return _10_$retval;
}


int main()
{
  printf("%ld",_10_main());
  return 0;
}

#endif
