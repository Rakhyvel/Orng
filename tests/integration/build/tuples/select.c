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
int64_t _22_main();

/* Function definitions */
int64_t _22_main() {
	int64_t _22_t1;
	int64_t _22_t2;
	struct1 _23_x;
	int64_t _22_t3;
	int64_t _22_t4;
	int64_t _22_$retval;
BB0:
	_22_t1 = 50;
	_22_t2 = 5;
	_23_x = (struct1) {_22_t1, _22_t2};
	_22_t3 = *&((&_23_x)->_0);
	_22_t4 = *&((&_23_x)->_1);
	_22_$retval = _22_t3 + _22_t4;
	return _22_$retval;
}


int main()
{
  printf("%ld",_22_main());
  return 0;
}

#endif
