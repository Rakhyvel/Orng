/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687130061
#define ORNG_1687130061

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
int64_t _350_main();
struct1 _352_get_array(int64_t _352_a,int64_t _352_b);

/* Function definitions */
int64_t _350_main() {
	int64_t _350_t1;
	int64_t _350_t2;
	struct1 _350_t0;
	struct1 _351_x;
	int64_t _350_t3;
	int64_t _350_t4;
	int64_t _350_t5;
	int64_t _350_t6;
	int64_t _350_t7;
	int64_t _350_t8;
	int64_t _350_t9;
	int64_t _350_t10;
	int64_t _350_t11;
	int64_t _350_t12;
	int64_t _350_$retval;
BB0:
	_350_t1 = 15;
	_350_t2 = 16;
	_350_t0 = _352_get_array(_350_t1, _350_t2);
	_351_x = _350_t0;
	_350_t3 = 0;
	_350_t4 = ((int64_t*)(&_351_x))[_350_t3];
	_350_t5 = 1;
	_350_t6 = ((int64_t*)(&_351_x))[_350_t5];
	_350_t7 = _350_t4 + _350_t6;
	_350_t8 = 2;
	_350_t9 = ((int64_t*)(&_351_x))[_350_t8];
	_350_t10 = _350_t7 + _350_t9;
	_350_t11 = 3;
	_350_t12 = ((int64_t*)(&_351_x))[_350_t11];
	_350_$retval = _350_t10 + _350_t12;
	return _350_$retval;
}

struct1 _352_get_array(int64_t _352_a,int64_t _352_b) {
	struct1 _352_$retval;
BB0:
	_352_$retval = (struct1) {_352_a, _352_b, _352_a, _352_b};
	return _352_$retval;
}


int main()
{
  printf("%ld",_350_main());
  return 0;
}

#endif
