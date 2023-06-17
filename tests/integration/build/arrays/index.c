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
	int64_t _2;
	int64_t _3;
} struct1;

/* Function forward definitions */
int64_t _331_main();
struct1 _333_get_array(int64_t a,int64_t b);

/* Function definitions */
int64_t _331_main() {
	int64_t _331_t1;
	int64_t _331_t2;
	struct1 _331_t0;
	struct1 _332_x;
	int64_t _331_t3;
	int64_t _331_t4;
	int64_t _331_t5;
	int64_t _331_t6;
	int64_t _331_t7;
	int64_t _331_t8;
	int64_t _331_t9;
	int64_t _331_t10;
	int64_t _331_t11;
	int64_t _331_t12;
	int64_t _331_$retval;
BB0:
	_331_t1 = 15;
	_331_t2 = 16;
	_331_t0 = _333_get_array(_331_t1, _331_t2);
	_332_x = _331_t0;
	_331_t3 = 0;
	_331_t4 = ((int64_t*)(&_332_x))[_331_t3];
	_331_t5 = 1;
	_331_t6 = ((int64_t*)(&_332_x))[_331_t5];
	_331_t7 = _331_t4 + _331_t6;
	_331_t8 = 2;
	_331_t9 = ((int64_t*)(&_332_x))[_331_t8];
	_331_t10 = _331_t7 + _331_t9;
	_331_t11 = 3;
	_331_t12 = ((int64_t*)(&_332_x))[_331_t11];
	_331_$retval = _331_t10 + _331_t12;
	return _331_$retval;
}

struct1 _333_get_array(int64_t a,int64_t b) {
	struct1 _333_$retval;
BB0:
	_333_$retval = (struct1) {a, b, a, b};
	return _333_$retval;
}


int main()
{
  printf("%ld",_331_main());
  return 0;
}

#endif
