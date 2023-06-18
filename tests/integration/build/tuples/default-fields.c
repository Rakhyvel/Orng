/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687128491
#define ORNG_1687128491

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _26_main();

/* Function definitions */
int64_t _26_main() {
	int64_t _26_t1;
	int64_t _26_t2;
	struct1 _27_x;
	int64_t _26_t3;
	int64_t _26_t4;
	int64_t _26_$retval;
BB0:
	_26_t1 = 50;
	_26_t2 = 7;
	_27_x = (struct1) {_26_t1, _26_t2};
	_26_t3 = _27_x._0;
	_26_t4 = _27_x._1;
	_26_$retval = _26_t3 + _26_t4;
	return _26_$retval;
}


int main()
{
  printf("%ld",_26_main());
  return 0;
}

#endif
