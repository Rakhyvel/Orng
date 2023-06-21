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
int64_t _366_main();
struct1 _368_get_array(int64_t _368_a,int64_t _368_b);

/* Function definitions */
int64_t _366_main() {
	int64_t _366_t1;
	int64_t _366_t2;
	struct1 _366_t0;
	struct1 _367_x;
	int64_t _366_t3;
	int64_t _366_t4;
	int64_t _366_t5;
	int64_t _366_t6;
	int64_t _366_t7;
	int64_t _366_t8;
	int64_t _366_t9;
	int64_t _366_t10;
	int64_t _366_t11;
	int64_t _366_t12;
	int64_t _366_$retval;
BB0:
	_366_t1 = 15;
	_366_t2 = 16;
	_366_t0 = _368_get_array(_366_t1, _366_t2);
	_367_x = _366_t0;
	_366_t3 = 0;
	_366_t4 = *(((int64_t*)(&_367_x))+_366_t3);
	_366_t5 = 1;
	_366_t6 = *(((int64_t*)(&_367_x))+_366_t5);
	_366_t7 = _366_t4 + _366_t6;
	_366_t8 = 2;
	_366_t9 = *(((int64_t*)(&_367_x))+_366_t8);
	_366_t10 = _366_t7 + _366_t9;
	_366_t11 = 3;
	_366_t12 = *(((int64_t*)(&_367_x))+_366_t11);
	_366_$retval = _366_t10 + _366_t12;
	return _366_$retval;
}

struct1 _368_get_array(int64_t _368_a,int64_t _368_b) {
	struct1 _368_$retval;
BB0:
	_368_$retval = (struct1) {_368_a, _368_b, _368_a, _368_b};
	return _368_$retval;
}


int main()
{
  printf("%ld",_366_main());
  return 0;
}

#endif
