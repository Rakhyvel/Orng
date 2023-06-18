/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687131173
#define ORNG_1687131173

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
int64_t _359_main();

/* Function definitions */
int64_t _359_main() {
	int64_t _359_t1;
	int64_t _359_t2;
	int64_t _359_t3;
	int64_t _359_t4;
	struct1 _360_x;
	int64_t _359_t5;
	int64_t _359_t6;
	int64_t* _360_y;
	int64_t _359_t8;
	int64_t _359_t9;
	int64_t _359_t10;
	int64_t _359_$retval;
BB0:
	_359_t1 = 1;
	_359_t2 = 2;
	_359_t3 = 3;
	_359_t4 = 4;
	_360_x = (struct1) {_359_t1, _359_t2, _359_t3, _359_t4};
	_359_t5 = 0;
	_360_y = (((int64_t*)(&_360_x))+_359_t5);
	_359_t8 = 63;
	*(((int64_t*)(&_360_x))+_359_t5) = _359_t8;
	_359_t9 = 0;
	_359_t10 = ((int64_t*)(&_360_x))[_359_t9];
	_359_$retval = _359_t10;
	return _359_$retval;
}


int main()
{
  printf("%ld",_359_main());
  return 0;
}

#endif
