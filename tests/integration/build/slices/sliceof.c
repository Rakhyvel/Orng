/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687738073
#define ORNG_1687738073

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
int64_t _411_main();

/* Function definitions */
int64_t _411_main() {
	int64_t _411_t1;
	int64_t _411_t2;
	int64_t _411_t3;
	int64_t _411_t4;
	int64_t _411_t5;
	struct1 _412_x;
	struct1* _411_t7;
	int64_t _411_t8;
	struct3 _412_y;
	int64_t _411_t9;
	int64_t _411_t10;
	int64_t _411_t11;
	int64_t _411_$retval;
BB0:
	_411_t1 = 1;
	_411_t2 = 2;
	_411_t3 = 3;
	_411_t4 = 4;
	_411_t5 = 5;
	_412_x = (struct1) {_411_t1, _411_t2, _411_t3, _411_t4, _411_t5};
	_411_t7 = &_412_x;
	_411_t8 = 5;
	_412_y = (struct3) {(int64_t*)_411_t7, _411_t8};
	_411_t9 = 2;
	_411_t10 = *(((int64_t*)((&_412_y)->_0))+_411_t9);
	_411_t11 = 77;
	_411_$retval = _411_t10 + _411_t11;
	return _411_$retval;
}


int main()
{
  printf("%ld",_411_main());
  return 0;
}

#endif
