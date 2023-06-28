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
} struct1;
typedef struct {
	int64_t* _0;
	int64_t _1;
} struct3;

/* Function forward definitions */
int64_t _14_main();
int64_t _16_f(struct3 _16_x);

/* Function definitions */
int64_t _14_main() {
	int64_t _14_t1;
	int64_t _14_t2;
	int64_t _14_t3;
	int64_t _14_t4;
	struct1 _15_x;
	int64_t _14_t6;
	int64_t _14_t7;
	int64_t* _14_t8;
	int64_t _14_t9;
	struct3 _15_y;
	int64_t _14_t10;
	int64_t _14_$retval;
BB0:
	_14_t1 = 1;
	_14_t2 = 2;
	_14_t3 = 3;
	_14_t4 = 4;
	_15_x = (struct1) {_14_t1, _14_t2, _14_t3, _14_t4};
	_14_t6 = 0;
	_14_t7 = *(((int64_t*)(&_15_x))+_14_t6);
	_14_t8 = (((int64_t*)(&_15_x))+_14_t6);
	_14_t9 = 4;
	_15_y = (struct3) {_14_t8, _14_t9};
	_14_t10 = _16_f(_15_y);
	_14_$retval = _14_t10;
	return _14_$retval;
}

int64_t _16_f(struct3 _16_x) {
	int64_t _16_t0;
	int64_t _16_t1;
	int64_t _16_t2;
	int64_t _16_$retval;
BB0:
	_16_t0 = 1;
	_16_t1 = *(((int64_t*)((&_16_x)->_0))+_16_t0);
	_16_t2 = 80;
	_16_$retval = _16_t1 + _16_t2;
	return _16_$retval;
}


int main()
{
  printf("%ld",_14_main());
  return 0;
}

#endif
