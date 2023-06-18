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
typedef struct {
	int64_t _0;
	int64_t* _1;
} struct3;

/* Function forward definitions */
int64_t _345_main();
struct1 _347_get_array(int64_t _347_a,int64_t _347_b);

/* Function definitions */
int64_t _345_main() {
	int64_t _345_t1;
	int64_t _345_t2;
	struct1 _345_t0;
	int64_t _346_z;
	int64_t* _345_t5;
	struct3 _346_y;
	int64_t _345_t6;
	int64_t _345_$retval;
BB0:
	_345_t1 = 15;
	_345_t2 = 16;
	_345_t0 = _347_get_array(_345_t1, _345_t2);
	_346_z = 64;
	_345_t5 = &_346_z;
	_346_y = (struct3) {_346_z, _345_t5};
	_345_t6 = _346_y._0;
	_345_$retval = _345_t6;
	return _345_$retval;
}

struct1 _347_get_array(int64_t _347_a,int64_t _347_b) {
	struct1 _347_$retval;
BB0:
	_347_$retval = (struct1) {_347_a, _347_b, _347_a, _347_b};
	return _347_$retval;
}


int main()
{
  printf("%ld",_345_main());
  return 0;
}

#endif
