/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687130061
#define ORNG_1687130061

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _317_main();

/* Function definitions */
int64_t _317_main() {
	int64_t _317_t1;
	int64_t _317_t2;
	struct1 _318_x;
	int64_t _317_t3;
	int64_t _317_t4;
	int64_t _317_$retval;
BB0:
	_317_t1 = 20;
	_317_t2 = 3;
	_318_x = (struct1) {_317_t1, _317_t2};
	_317_t3 = _318_x._0;
	_317_t4 = _318_x._1;
	_317_$retval = _317_t3 * _317_t4;
	return _317_$retval;
}


int main()
{
  printf("%ld",_317_main());
  return 0;
}

#endif
