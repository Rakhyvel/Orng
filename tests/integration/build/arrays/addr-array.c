/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687227438
#define ORNG_1687227438

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
int64_t _368_main();

/* Function definitions */
int64_t _368_main() {
	int64_t _368_t1;
	int64_t _368_t2;
	int64_t _368_t3;
	int64_t _368_t4;
	struct1 _369_x;
	struct1* _368_t5;
	struct1 _368_t6;
	int64_t _368_t7;
	int64_t _368_t8;
	struct1 _368_t9;
	int64_t _368_t10;
	int64_t _368_t11;
	int64_t _368_$retval;
BB0:
	_368_t1 = 1;
	_368_t2 = 2;
	_368_t3 = 3;
	_368_t4 = 4;
	_369_x = (struct1) {_368_t1, _368_t2, _368_t3, _368_t4};
	_368_t5 = &_369_x;
	_368_t6 = *_368_t5;
	_368_t7 = 2;
	_368_t8 = 70;
*(((int64_t*)(&_368_t5))+_368_t7) = _368_t8;
	_368_t9 = *_368_t5;
	_368_t10 = 2;
	_368_t11 = *(((int64_t*)(&_368_t5))+_368_t10);
	_368_$retval = _368_t11;
	return _368_$retval;
}


int main()
{
  printf("%ld",_368_main());
  return 0;
}

#endif
