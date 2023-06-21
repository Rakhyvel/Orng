/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687314590
#define ORNG_1687314590

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
	int64_t _2;
} struct1;
typedef struct {
	struct1 _0;
	struct1 _1;
} struct2;

/* Function forward definitions */
int64_t _39_main();

/* Function definitions */
int64_t _39_main() {
	int64_t _39_t2;
	int64_t _39_t3;
	int64_t _39_t4;
	struct1 _39_t1;
	int64_t _39_t6;
	int64_t _39_t7;
	int64_t _39_t8;
	struct1 _39_t5;
	struct2 _40_x;
	struct1 _39_t9;
	int64_t _39_t10;
	int64_t _39_t11;
	struct1 _39_t12;
	int64_t _39_t13;
	int64_t _39_t14;
	int64_t _39_$retval;
BB0:
	_39_t2 = 1;
	_39_t3 = 2;
	_39_t4 = 3;
	_39_t1 = (struct1) {_39_t2, _39_t3, _39_t4};
	_39_t6 = 4;
	_39_t7 = 5;
	_39_t8 = 6;
	_39_t5 = (struct1) {_39_t6, _39_t7, _39_t8};
	_40_x = (struct2) {_39_t1, _39_t5};
	_39_t9 = *&((&_40_x)->_0);
	_39_t10 = 1;
	_39_t11 = 72;
	*(((int64_t*)(&((&_40_x)->_0)))+_39_t10) = _39_t11;
	_39_t12 = *&((&_40_x)->_0);
	_39_t13 = 1;
	_39_t14 = *(((int64_t*)(&((&_40_x)->_0)))+_39_t13);
	_39_$retval = _39_t14;
	return _39_$retval;
}


int main()
{
  printf("%ld",_39_main());
  return 0;
}

#endif
