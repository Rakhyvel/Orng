/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687918146
#define ORNG_1687918146

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
	int64_t _2;
	int64_t _3;
	int64_t _4;
} struct1;
typedef struct {
	int64_t* _0;
	int64_t _1;
} struct3;

/* Function forward definitions */
int64_t _6_main();

/* Function definitions */
int64_t _6_main() {
	int64_t _6_t1;
	int64_t _6_t2;
	int64_t _6_t3;
	int64_t _6_t4;
	int64_t _6_t5;
	struct1 _7_x;
	int64_t _6_t7;
	int64_t _6_t8;
	int64_t* _6_t9;
	int64_t _6_t10;
	struct3 _7_y;
	int64_t _6_t11;
	int64_t _6_t12;
	int64_t _6_t13;
	int64_t _6_t14;
	int64_t _6_$retval;
BB0:
	_6_t1 = 1;
	_6_t2 = 2;
	_6_t3 = 3;
	_6_t4 = 4;
	_6_t5 = 5;
	_7_x = (struct1) {_6_t1, _6_t2, _6_t3, _6_t4, _6_t5};
	_6_t7 = 0;
	_6_t8 = *(((int64_t*)(&_7_x))+_6_t7);
	_6_t9 = (((int64_t*)(&_7_x))+_6_t7);
	_6_t10 = 5;
	_7_y = (struct3) {_6_t9, _6_t10};
	_6_t11 = 2;
	_6_t12 = 81;
	*(((int64_t*)((&_7_y)->_0))+_6_t11) = _6_t12;
	_6_t13 = 2;
	_6_t14 = *(((int64_t*)((&_7_y)->_0))+_6_t13);
	_6_$retval = _6_t14;
	return _6_$retval;
}


int main()
{
  printf("%ld",_6_main());
  return 0;
}

#endif
