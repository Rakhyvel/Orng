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
typedef struct {
	int64_t _0;
	int64_t* _1;
} struct3;

/* Function forward definitions */
int64_t _341_main();
struct1 _343_get_array(int64_t _343_a,int64_t _343_b);

/* Function definitions */
int64_t _341_main() {
	int64_t _341_t1;
	int64_t _341_t2;
	struct1 _341_t0;
	int64_t _342_z;
	int64_t* _341_t5;
	struct3 _342_y;
	int64_t _341_t6;
	int64_t _341_$retval;
BB0:
	_341_t1 = 15;
	_341_t2 = 16;
	_341_t0 = _343_get_array(_341_t1, _341_t2);
	_342_z = 64;
	_341_t5 = &_342_z;
	_342_y = (struct3) {_342_z, _341_t5};
	_341_t6 = _342_y._0;
	_341_$retval = _341_t6;
	return _341_$retval;
}

struct1 _343_get_array(int64_t _343_a,int64_t _343_b) {
	struct1 _343_$retval;
BB0:
	_343_$retval = (struct1) {_343_a, _343_b, _343_a, _343_b};
	return _343_$retval;
}


int main()
{
  printf("%ld",_341_main());
  return 0;
}

#endif
