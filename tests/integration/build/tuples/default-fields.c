/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687131173
#define ORNG_1687131173

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _337_main();

/* Function definitions */
int64_t _337_main() {
	int64_t _337_t1;
	int64_t _337_t2;
	struct1 _338_x;
	int64_t _337_t3;
	int64_t _337_t4;
	int64_t _337_$retval;
BB0:
	_337_t1 = 50;
	_337_t2 = 7;
	_338_x = (struct1) {_337_t1, _337_t2};
	_337_t3 = _338_x._0;
	_337_t4 = _338_x._1;
	_337_$retval = _337_t3 + _337_t4;
	return _337_$retval;
}


int main()
{
  printf("%ld",_337_main());
  return 0;
}

#endif
