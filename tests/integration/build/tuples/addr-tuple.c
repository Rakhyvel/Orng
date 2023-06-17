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
int64_t _303_main();

/* Function definitions */
int64_t _303_main() {
	int64_t _303_t1;
	int64_t _303_t4;
	struct1 _304_x;
	struct1* _304_y;
	struct1 _303_t6;
	int64_t _303_t7;
	struct1 _303_t8;
	int64_t _303_t9;
	int64_t _303_$retval;
BB0:
	_303_t1 = 19;
	_303_t4 = 39;
	_304_x = (struct1) {_303_t1, _303_t4};
	_304_y = &_304_x;
	_303_t6 = *_304_y;
	_303_t7 = _303_t6._0;
	_303_t8 = *_304_y;
	_303_t9 = _303_t8._1;
	_303_$retval = _303_t7 + _303_t9;
	return _303_$retval;
}


int main()
{
  printf("%ld",_303_main());
  return 0;
}

#endif
