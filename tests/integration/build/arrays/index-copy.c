/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687131003
#define ORNG_1687131003

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
	int64_t _2;
	int64_t _3;
} struct1;

/* Function forward definitions */
int64_t _355_main();

/* Function definitions */
int64_t _355_main() {
	int64_t _355_t1;
	int64_t _355_t2;
	int64_t _355_t3;
	int64_t _355_t4;
	struct1 _356_x;
	int64_t _355_t5;
	int64_t _355_t6;
	int64_t _355_t7;
	int64_t _355_t8;
	int64_t _355_$retval;
BB0:
	_355_t1 = 1;
	_355_t2 = 2;
	_355_t3 = 3;
	_355_t4 = 4;
	_356_x = (struct1) {_355_t1, _355_t2, _355_t3, _355_t4};
	_355_t5 = 2;
	_355_t6 = 62;
(((int64_t*)(&_356_x))[_355_t5]) = _355_t6;
	_355_t7 = 2;
	_355_t8 = ((int64_t*)(&_356_x))[_355_t7];
	_355_$retval = _355_t8;
	return _355_$retval;
}


int main()
{
  printf("%ld",_355_main());
  return 0;
}

#endif
