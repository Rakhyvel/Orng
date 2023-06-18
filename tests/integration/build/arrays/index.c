/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687127760
#define ORNG_1687127760

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
int64_t _336_main();
struct1 _338_get_array(int64_t a,int64_t b);

/* Function definitions */
int64_t _336_main() {
	int64_t _336_t1;
	int64_t _336_t2;
	struct1 _336_t0;
	struct1 _337_x;
	int64_t _336_t3;
	int64_t _336_t4;
	int64_t _336_t5;
	int64_t _336_t6;
	int64_t _336_t7;
	int64_t _336_t8;
	int64_t _336_t9;
	int64_t _336_t10;
	int64_t _336_t11;
	int64_t _336_t12;
	int64_t _336_$retval;
BB0:
	_336_t1 = 15;
	_336_t2 = 16;
	_336_t0 = _338_get_array(_336_t1, _336_t2);
	_337_x = _336_t0;
	_336_t3 = 0;
	_336_t4 = ((int64_t*)(&_337_x))[_336_t3];
	_336_t5 = 1;
	_336_t6 = ((int64_t*)(&_337_x))[_336_t5];
	_336_t7 = _336_t4 + _336_t6;
	_336_t8 = 2;
	_336_t9 = ((int64_t*)(&_337_x))[_336_t8];
	_336_t10 = _336_t7 + _336_t9;
	_336_t11 = 3;
	_336_t12 = ((int64_t*)(&_337_x))[_336_t11];
	_336_$retval = _336_t10 + _336_t12;
	return _336_$retval;
}

struct1 _338_get_array(int64_t a,int64_t b) {
	struct1 _338_$retval;
BB0:
	_338_$retval = (struct1) {a, b, a, b};
	return _338_$retval;
}


int main()
{
  printf("%ld",_336_main());
  return 0;
}

#endif
