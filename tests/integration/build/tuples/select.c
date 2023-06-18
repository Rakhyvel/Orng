/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687129465
#define ORNG_1687129465

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _321_main();

/* Function definitions */
int64_t _321_main() {
	int64_t _321_t1;
	int64_t _321_t2;
	struct1 _322_x;
	int64_t _321_t3;
	int64_t _321_t4;
	int64_t _321_$retval;
BB0:
	_321_t1 = 50;
	_321_t2 = 5;
	_322_x = (struct1) {_321_t1, _321_t2};
	_321_t3 = _322_x._0;
	_321_t4 = _322_x._1;
	_321_$retval = _321_t3 + _321_t4;
	return _321_$retval;
}


int main()
{
  printf("%ld",_321_main());
  return 0;
}

#endif
