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
int64_t _341_main();

/* Function definitions */
int64_t _341_main() {
	int64_t _341_t1;
	int64_t _341_t2;
	int64_t _341_t3;
	int64_t _341_t4;
	struct1 _342_x;
	int64_t _341_t5;
	int64_t _341_t6;
	int64_t* _342_y;
	int64_t _341_t8;
	int64_t _341_t9;
	int64_t _341_t10;
	int64_t _341_$retval;
BB0:
	_341_t1 = 1;
	_341_t2 = 2;
	_341_t3 = 3;
	_341_t4 = 4;
	_342_x = (struct1) {_341_t1, _341_t2, _341_t3, _341_t4};
	_341_t5 = 0;
	_342_y = (((int64_t*)(&_342_x))+_341_t5);
	_341_t8 = 63;
	*(((int64_t*)(&_342_x))+_341_t5) = _341_t8;
	_341_t9 = 0;
	_341_t10 = ((int64_t*)(&_342_x))[_341_t9];
	_341_$retval = _341_t10;
	return _341_$retval;
}


int main()
{
  printf("%ld",_341_main());
  return 0;
}

#endif
