/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686980573
#define ORNG_1686980573

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _319_main();

/* Function definitions */
int64_t _319_main() {
	int64_t _319_t1;
	int64_t _319_t2;
	struct1 _320_x;
	int64_t _319_t3;
	int64_t _319_t4;
	int64_t _319_t5;
	int64_t _319_$retval;
BB0:
	_319_t1 = 50;
	_319_t2 = 5;
	_320_x = (struct1) {_319_t1, _319_t2};
	_319_t3 = 6;
	_320_x._1 = _319_t3;
	_319_t4 = _320_x._0;
	_319_t5 = _320_x._1;
	_319_$retval = _319_t4 + _319_t5;
	return _319_$retval;
}


int main()
{
  printf("%ld",_319_main());
  return 0;
}

#endif
