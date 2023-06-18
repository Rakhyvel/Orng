/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687128491
#define ORNG_1687128491

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t* _0;
	int64_t* _1;
} struct2;

/* Function forward definitions */
int64_t _30_main();

/* Function definitions */
int64_t _30_main() {
	int64_t _31_x;
	int64_t _31_y;
	int64_t* _30_t3;
	int64_t* _30_t4;
	struct2 _31_z;
	int64_t* _30_t5;
	int64_t _30_t6;
	int64_t* _30_t7;
	int64_t _30_t8;
	int64_t _30_$retval;
BB0:
	_31_x = 30;
	_31_y = 29;
	_30_t3 = &_31_x;
	_30_t4 = &_31_y;
	_31_z = (struct2) {_30_t3, _30_t4};
	_30_t5 = _31_z._0;
	_30_t6 = *_30_t5;
	_30_t7 = _31_z._1;
	_30_t8 = *_30_t7;
	_30_$retval = _30_t6 + _30_t8;
	return _30_$retval;
}


int main()
{
  printf("%ld",_30_main());
  return 0;
}

#endif
