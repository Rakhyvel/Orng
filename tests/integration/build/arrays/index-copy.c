/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687316164
#define ORNG_1687316164

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
int64_t _371_main();

/* Function definitions */
int64_t _371_main() {
	int64_t _371_t1;
	int64_t _371_t2;
	int64_t _371_t3;
	int64_t _371_t4;
	struct1 _372_x;
	int64_t _371_t5;
	int64_t _371_t6;
	int64_t _371_t7;
	int64_t _371_t8;
	int64_t _371_$retval;
BB0:
	_371_t1 = 1;
	_371_t2 = 2;
	_371_t3 = 3;
	_371_t4 = 4;
	_372_x = (struct1) {_371_t1, _371_t2, _371_t3, _371_t4};
	_371_t5 = 2;
	_371_t6 = 62;
	*(((int64_t*)(&_372_x))+_371_t5) = _371_t6;
	_371_t7 = 2;
	_371_t8 = *(((int64_t*)(&_372_x))+_371_t7);
	_371_$retval = _371_t8;
	return _371_$retval;
}


int main()
{
  printf("%ld",_371_main());
  return 0;
}

#endif
