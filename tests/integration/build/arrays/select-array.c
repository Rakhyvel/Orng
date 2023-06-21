/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687316164
#define ORNG_1687316164

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
int64_t _403_main();

/* Function definitions */
int64_t _403_main() {
	int64_t _403_t2;
	int64_t _403_t3;
	int64_t _403_t4;
	struct1 _403_t1;
	int64_t _403_t6;
	int64_t _403_t7;
	int64_t _403_t8;
	struct1 _403_t5;
	struct2 _404_x;
	struct1 _403_t9;
	int64_t _403_t10;
	int64_t _403_t11;
	struct1 _403_t12;
	int64_t _403_t13;
	int64_t _403_t14;
	int64_t _403_$retval;
BB0:
	_403_t2 = 1;
	_403_t3 = 2;
	_403_t4 = 3;
	_403_t1 = (struct1) {_403_t2, _403_t3, _403_t4};
	_403_t6 = 4;
	_403_t7 = 5;
	_403_t8 = 6;
	_403_t5 = (struct1) {_403_t6, _403_t7, _403_t8};
	_404_x = (struct2) {_403_t1, _403_t5};
	_403_t9 = *&((&_404_x)->_0);
	_403_t10 = 1;
	_403_t11 = 72;
	*(((int64_t*)(&((&_404_x)->_0)))+_403_t10) = _403_t11;
	_403_t12 = *&((&_404_x)->_0);
	_403_t13 = 1;
	_403_t14 = *(((int64_t*)(&((&_404_x)->_0)))+_403_t13);
	_403_$retval = _403_t14;
	return _403_$retval;
}


int main()
{
  printf("%ld",_403_main());
  return 0;
}

#endif
