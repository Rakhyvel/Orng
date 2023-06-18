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
int64_t _6_main();

/* Function definitions */
int64_t _6_main() {
	int64_t _6_t1;
	int64_t _6_t2;
	struct1 _7_x;
	int64_t _6_t3;
	int64_t _6_t4;
	int64_t _6_$retval;
BB0:
	_6_t1 = 20;
	_6_t2 = 3;
	_7_x = (struct1) {_6_t1, _6_t2};
	_6_t3 = _7_x._0;
	_6_t4 = _7_x._1;
	_6_$retval = _6_t3 * _6_t4;
	return _6_$retval;
}


int main()
{
  printf("%ld",_6_main());
  return 0;
}

#endif
