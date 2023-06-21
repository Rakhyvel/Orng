/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687313803
#define ORNG_1687313803

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
int64_t _35_main();

/* Function definitions */
int64_t _35_main() {
	int64_t _36_a;
	int64_t _36_b;
	int64_t _36_c;
	int64_t _36_d;
	int64_t* _35_t5;
	int64_t* _35_t6;
	int64_t* _35_t7;
	int64_t* _35_t8;
	struct2 _36_x;
	int64_t _35_t9;
	int64_t* _35_t10;
	int64_t _35_t11;
	int64_t _35_t12;
	int64_t* _35_t13;
	int64_t _35_t14;
	int64_t _35_$retval;
BB0:
	_36_a = 1;
	_36_b = 2;
	_36_c = 3;
	_36_d = 4;
	_35_t5 = &_36_a;
	_35_t6 = &_36_b;
	_35_t7 = &_36_c;
	_35_t8 = &_36_d;
	_36_x = (struct2) {_35_t5, _35_t6, _35_t7, _35_t8};
	_35_t9 = 2;
	_35_t10 = *(((int64_t**)(&_36_x))+_35_t9);
	_35_t11 = 71;
	**(((int64_t**)(&_36_x))+_35_t9) = _35_t11;
	_35_t12 = 2;
	_35_t13 = *(((int64_t**)(&_36_x))+_35_t12);
	_35_t14 = *_35_t13;
	_35_$retval = _35_t14;
	return _35_$retval;
}


int main()
{
  printf("%ld",_35_main());
  return 0;
}

#endif
