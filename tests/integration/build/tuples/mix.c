/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687121195676386576
#define ORNG_1687121195676386576

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
typedef struct {
	int64_t _0;
	int64_t* _1;
} struct3;

/* Function forward definitions */
int64_t _2_main();
struct1 _4_get_array(int64_t _4_a,int64_t _4_b);

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t2;
	struct1 _2_t0;
	int64_t _3_z;
	int64_t* _2_t5;
	struct3 _3_y;
	int64_t _2_t6;
	int64_t _2_$retval;
BB0:
	_2_t1 = 15;
	_2_t2 = 16;
	_2_t0 = _4_get_array(_2_t1, _2_t2);
	_3_z = 64;
	_2_t5 = &_3_z;
	_3_y = (struct3) {_3_z, _2_t5};
	_2_t6 = *&((&_3_y)->_0);
	_2_$retval = _2_t6;
	return _2_$retval;
}

struct1 _4_get_array(int64_t _4_a,int64_t _4_b) {
	struct1 _4_$retval;
BB0:
	_4_$retval = (struct1) {_4_a, _4_b, _4_a, _4_b};
	return _4_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
