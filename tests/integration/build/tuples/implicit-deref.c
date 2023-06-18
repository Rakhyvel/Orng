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
int64_t _10_main();

/* Function definitions */
int64_t _10_main() {
	int64_t _10_t1;
	int64_t _10_t2;
	struct1 _11_x;
	struct1* _11_y;
	struct1 _10_t4;
	int64_t _10_t5;
	struct1 _10_t6;
	int64_t _10_t7;
	int64_t _10_$retval;
BB0:
	_10_t1 = 50;
	_10_t2 = 11;
	_11_x = (struct1) {_10_t1, _10_t2};
	_11_y = &_11_x;
	_10_t4 = *_11_y;
	_10_t5 = _10_t4._0;
	_10_t6 = *_11_y;
	_10_t7 = _10_t6._1;
	_10_$retval = _10_t5 + _10_t7;
	return _10_$retval;
}


int main()
{
  printf("%ld",_10_main());
  return 0;
}

#endif
