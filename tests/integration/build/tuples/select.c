/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687128490
#define ORNG_1687128490

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _14_main();

/* Function definitions */
int64_t _14_main() {
	int64_t _14_t1;
	int64_t _14_t2;
	struct1 _15_x;
	int64_t _14_t3;
	int64_t _14_t4;
	int64_t _14_$retval;
BB0:
	_14_t1 = 50;
	_14_t2 = 5;
	_15_x = (struct1) {_14_t1, _14_t2};
	_14_t3 = _15_x._0;
	_14_t4 = _15_x._1;
	_14_$retval = _14_t3 + _14_t4;
	return _14_$retval;
}


int main()
{
  printf("%ld",_14_main());
  return 0;
}

#endif
