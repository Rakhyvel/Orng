/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687316164
#define ORNG_1687316164

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _341_main();

/* Function definitions */
int64_t _341_main() {
	int64_t _341_t1;
	int64_t _341_t2;
	struct1 _342_x;
	struct1* _341_t3;
	struct1 _341_t4;
	int64_t _341_t5;
	struct1* _341_t6;
	struct1 _341_t7;
	int64_t _341_t8;
	int64_t _341_$retval;
BB0:
	_341_t1 = 1;
	_341_t2 = 2;
	_342_x = (struct1) {_341_t1, _341_t2};
	_341_t3 = &_342_x;
	_341_t5 = 76;
	(_341_t3)->_0 = _341_t5;
	_341_t6 = &_342_x;
	_341_t8 = *&((_341_t6)->_0);
	_341_$retval = _341_t8;
	return _341_$retval;
}


int main()
{
  printf("%ld",_341_main());
  return 0;
}

#endif
