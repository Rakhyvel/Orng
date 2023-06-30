/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687919227081540448
#define ORNG_1687919227081540448

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
int64_t _431_main();
int64_t _433_f(struct3 _433_x);

/* Function definitions */
int64_t _431_main() {
	int64_t _431_t1;
	int64_t _431_t2;
	int64_t _431_t3;
	int64_t _431_t4;
	struct1 _432_x;
	int64_t _431_t6;
	int64_t _431_t7;
	int64_t* _431_t8;
	int64_t _431_t9;
	struct3 _432_y;
	int64_t _431_t10;
	int64_t _431_$retval;
BB0:
	_431_t1 = 1;
	_431_t2 = 2;
	_431_t3 = 3;
	_431_t4 = 4;
	_432_x = (struct1) {_431_t1, _431_t2, _431_t3, _431_t4};
	_431_t6 = 0;
	_431_t7 = *(((int64_t*)(&_432_x))+_431_t6);
	_431_t8 = (((int64_t*)(&_432_x))+_431_t6);
	_431_t9 = 4;
	_432_y = (struct3) {_431_t8, _431_t9};
	_431_t10 = _433_f(_432_y);
	_431_$retval = _431_t10;
	return _431_$retval;
}

int64_t _433_f(struct3 _433_x) {
	int64_t _433_t0;
	int64_t _433_t1;
	int64_t _433_t2;
	int64_t _433_$retval;
BB0:
	_433_t0 = 1;
	_433_t1 = *(((int64_t*)((&_433_x)->_0))+_433_t0);
	_433_t2 = 80;
	_433_$retval = _433_t1 + _433_t2;
	return _433_$retval;
}


int main()
{
  printf("%ld",_431_main());
  return 0;
}

#endif
