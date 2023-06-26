/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687738073
#define ORNG_1687738073

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _353_main();

/* Function definitions */
int64_t _353_main() {
	int64_t _353_t1;
	int64_t _353_t2;
	struct1 _354_x;
	int64_t _353_t3;
	int64_t _353_t4;
	int64_t _353_$retval;
BB0:
	_353_t1 = 50;
	_353_t2 = 7;
	_354_x = (struct1) {_353_t1, _353_t2};
	_353_t3 = *&((&_354_x)->_0);
	_353_t4 = *&((&_354_x)->_1);
	_353_$retval = _353_t3 + _353_t4;
	return _353_$retval;
}


int main()
{
  printf("%ld",_353_main());
  return 0;
}

#endif
