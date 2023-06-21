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
int64_t _325_main();

/* Function definitions */
int64_t _325_main() {
	int64_t _325_t1;
	int64_t _325_t4;
	struct1 _326_x;
	struct1* _325_t5;
	struct1 _325_t6;
	int64_t _325_t7;
	struct1 _325_t8;
	int64_t _325_t9;
	int64_t _325_$retval;
BB0:
	_325_t1 = 19;
	_325_t4 = 39;
	_326_x = (struct1) {_325_t1, _325_t4};
	_325_t5 = &_326_x;
	_325_t7 = *&((_325_t5)->_0);
	_325_t9 = *&((_325_t5)->_1);
	_325_$retval = _325_t7 + _325_t9;
	return _325_$retval;
}


int main()
{
  printf("%ld",_325_main());
  return 0;
}

#endif
