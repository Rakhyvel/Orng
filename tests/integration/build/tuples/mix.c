/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687128491
#define ORNG_1687128491

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
int64_t _34_main();
struct1 _36_get_array(int64_t a,int64_t b);

/* Function definitions */
int64_t _34_main() {
	int64_t _34_t1;
	int64_t _34_t2;
	struct1 _34_t0;
	int64_t _35_z;
	int64_t* _34_t5;
	struct3 _35_y;
	int64_t _34_t6;
	int64_t _34_$retval;
BB0:
	_34_t1 = 15;
	_34_t2 = 16;
	_34_t0 = _36_get_array(_34_t1, _34_t2);
	_35_z = 64;
	_34_t5 = &_35_z;
	_35_y = (struct3) {_35_z, _34_t5};
	_34_t6 = _35_y._0;
	_34_$retval = _34_t6;
	return _34_$retval;
}

struct1 _36_get_array(int64_t a,int64_t b) {
	struct1 _36_$retval;
BB0:
	_36_$retval = (struct1) {a, b, a, b};
	return _36_$retval;
}


int main()
{
  printf("%ld",_34_main());
  return 0;
}

#endif
