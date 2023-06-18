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
int64_t _317_main();

/* Function definitions */
int64_t _317_main() {
	int64_t _317_t1;
	int64_t _317_t2;
	struct1 _318_x;
	struct1* _318_y;
	struct1 _317_t4;
	int64_t _317_t5;
	struct1 _317_t6;
	int64_t _317_t7;
	int64_t _317_$retval;
BB0:
	_317_t1 = 50;
	_317_t2 = 11;
	_318_x = (struct1) {_317_t1, _317_t2};
	_318_y = &_318_x;
	_317_t4 = *_318_y;
	_317_t5 = _317_t4._0;
	_317_t6 = *_318_y;
	_317_t7 = _317_t6._1;
	_317_$retval = _317_t5 + _317_t7;
	return _317_$retval;
}


int main()
{
  printf("%ld",_317_main());
  return 0;
}

#endif
