/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687227438
#define ORNG_1687227438

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t* _0;
	int64_t* _1;
	int64_t* _2;
	int64_t* _3;
} struct2;

/* Function forward definitions */
int64_t _372_main();

/* Function definitions */
int64_t _372_main() {
	int64_t _373_a;
	int64_t _373_b;
	int64_t _373_c;
	int64_t _373_d;
	int64_t* _372_t5;
	int64_t* _372_t6;
	int64_t* _372_t7;
	int64_t* _372_t8;
	struct2 _373_x;
	int64_t _372_t9;
	int64_t* _372_t10;
	int64_t _372_t11;
	int64_t _372_t12;
	int64_t* _372_t13;
	int64_t _372_t14;
	int64_t _372_$retval;
BB0:
	_373_a = 1;
	_373_b = 2;
	_373_c = 3;
	_373_d = 4;
	_372_t5 = &_373_a;
	_372_t6 = &_373_b;
	_372_t7 = &_373_c;
	_372_t8 = &_373_d;
	_373_x = (struct2) {_372_t5, _372_t6, _372_t7, _372_t8};
	_372_t9 = 2;
	_372_t10 = *(((int64_t**)(&_373_x))+_372_t9);
	_372_t11 = 71;
	**(((int64_t**)(&_373_x))+_372_t9) = _372_t11;
	_372_t12 = 2;
	_372_t13 = *(((int64_t**)(&_373_x))+_372_t12);
	_372_t14 = *_372_t13;
	_372_$retval = _372_t14;
	return _372_$retval;
}


int main()
{
  printf("%ld",_372_main());
  return 0;
}

#endif
