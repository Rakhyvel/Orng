/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687313477
#define ORNG_1687313477

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _30_main();

/* Function definitions */
int64_t _30_main() {
	int64_t _30_t1;
	int64_t _30_t2;
	struct1 _31_x;
	int64_t _30_t3;
	int64_t _30_t4;
	int64_t _30_t5;
	int64_t _30_$retval;
BB0:
	_30_t1 = 50;
	_30_t2 = 5;
	_31_x = (struct1) {_30_t1, _30_t2};
	_30_t3 = 6;
	(&_31_x)->_1 = _30_t3;
	_30_t4 = *&((&_31_x)->_0);
	_30_t5 = *&((&_31_x)->_1);
	_30_$retval = _30_t4 + _30_t5;
	return _30_$retval;
}


int main()
{
  printf("%ld",_30_main());
  return 0;
}

#endif
