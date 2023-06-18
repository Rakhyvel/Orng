/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687131003
#define ORNG_1687131003

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
	int64_t _325_t2;
	struct1 _326_x;
	int64_t _325_t3;
	int64_t _325_t4;
	int64_t _325_$retval;
BB0:
	_325_t1 = 50;
	_325_t2 = 5;
	_326_x = (struct1) {_325_t1, _325_t2};
	_325_t3 = _326_x._0;
	_325_t4 = _326_x._1;
	_325_$retval = _325_t3 + _325_t4;
	return _325_$retval;
}


int main()
{
  printf("%ld",_325_main());
  return 0;
}

#endif
