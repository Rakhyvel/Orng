/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686886319
#define ORNG_1686886319

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _323_main();

/* Function definitions */
int64_t _323_main() {
	int64_t _323_t1;
	int64_t _323_t2;
	struct1 _324_x;
	int64_t _323_t3;
	int64_t _323_t4;
	int64_t _323_$retval;
BB0:
	_323_t1 = 50;
	_323_t2 = 7;
	_324_x = (struct1) {_323_t1, _323_t2};
	_323_t3 = _324_x._0;
	_323_t4 = _324_x._1;
	_323_$retval = _323_t3 + _323_t4;
	return _323_$retval;
}


int main()
{
  printf("%ld",_323_main());
  return 0;
}

#endif
