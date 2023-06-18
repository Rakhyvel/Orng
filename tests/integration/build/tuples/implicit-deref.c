/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687127760
#define ORNG_1687127760

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _311_main();

/* Function definitions */
int64_t _311_main() {
	int64_t _311_t1;
	int64_t _311_t2;
	struct1 _312_x;
	struct1* _312_y;
	struct1 _311_t4;
	int64_t _311_t5;
	struct1 _311_t6;
	int64_t _311_t7;
	int64_t _311_$retval;
BB0:
	_311_t1 = 50;
	_311_t2 = 11;
	_312_x = (struct1) {_311_t1, _311_t2};
	_312_y = &_312_x;
	_311_t4 = *_312_y;
	_311_t5 = _311_t4._0;
	_311_t6 = *_312_y;
	_311_t7 = _311_t6._1;
	_311_$retval = _311_t5 + _311_t7;
	return _311_$retval;
}


int main()
{
  printf("%ld",_311_main());
  return 0;
}

#endif
