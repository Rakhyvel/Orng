/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687313477
#define ORNG_1687313477

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
int64_t _42_main();
struct1 _44_get_array(int64_t _44_a,int64_t _44_b);

/* Function definitions */
int64_t _42_main() {
	int64_t _42_t1;
	int64_t _42_t2;
	struct1 _42_t0;
	int64_t _43_z;
	int64_t* _42_t5;
	struct3 _43_y;
	int64_t _42_t6;
	int64_t _42_$retval;
BB0:
	_42_t1 = 15;
	_42_t2 = 16;
	_42_t0 = _44_get_array(_42_t1, _42_t2);
	_43_z = 64;
	_42_t5 = &_43_z;
	_43_y = (struct3) {_43_z, _42_t5};
	_42_t6 = *&((&_43_y)->_0);
	_42_$retval = _42_t6;
	return _42_$retval;
}

struct1 _44_get_array(int64_t _44_a,int64_t _44_b) {
	struct1 _44_$retval;
BB0:
	_44_$retval = (struct1) {_44_a, _44_b, _44_a, _44_b};
	return _44_$retval;
}


int main()
{
  printf("%ld",_42_main());
  return 0;
}

#endif
