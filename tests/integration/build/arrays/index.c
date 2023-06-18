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
	int64_t _2;
	int64_t _3;
} struct1;

/* Function forward definitions */
int64_t _346_main();
struct1 _348_get_array(int64_t _348_a,int64_t _348_b);

/* Function definitions */
int64_t _346_main() {
	int64_t _346_t1;
	int64_t _346_t2;
	struct1 _346_t0;
	struct1 _347_x;
	int64_t _346_t3;
	int64_t _346_t4;
	int64_t _346_t5;
	int64_t _346_t6;
	int64_t _346_t7;
	int64_t _346_t8;
	int64_t _346_t9;
	int64_t _346_t10;
	int64_t _346_t11;
	int64_t _346_t12;
	int64_t _346_$retval;
BB0:
	_346_t1 = 15;
	_346_t2 = 16;
	_346_t0 = _348_get_array(_346_t1, _346_t2);
	_347_x = _346_t0;
	_346_t3 = 0;
	_346_t4 = ((int64_t*)(&_347_x))[_346_t3];
	_346_t5 = 1;
	_346_t6 = ((int64_t*)(&_347_x))[_346_t5];
	_346_t7 = _346_t4 + _346_t6;
	_346_t8 = 2;
	_346_t9 = ((int64_t*)(&_347_x))[_346_t8];
	_346_t10 = _346_t7 + _346_t9;
	_346_t11 = 3;
	_346_t12 = ((int64_t*)(&_347_x))[_346_t11];
	_346_$retval = _346_t10 + _346_t12;
	return _346_$retval;
}

struct1 _348_get_array(int64_t _348_a,int64_t _348_b) {
	struct1 _348_$retval;
BB0:
	_348_$retval = (struct1) {_348_a, _348_b, _348_a, _348_b};
	return _348_$retval;
}


int main()
{
  printf("%ld",_346_main());
  return 0;
}

#endif
