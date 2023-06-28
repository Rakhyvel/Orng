/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687143985591819355
#define ORNG_1687143985591819355

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
int64_t _403_main();

/* Function definitions */
int64_t _403_main() {
	int64_t _404_a;
	int64_t _404_b;
	int64_t _404_c;
	int64_t _404_d;
	int64_t* _403_t5;
	int64_t* _403_t6;
	int64_t* _403_t7;
	int64_t* _403_t8;
	struct2 _404_x;
	int64_t _403_t9;
	int64_t* _403_t10;
	int64_t _403_t11;
	int64_t _403_t12;
	int64_t* _403_t13;
	int64_t _403_t14;
	int64_t _403_$retval;
BB0:
	_404_a = 1;
	_404_b = 2;
	_404_c = 3;
	_404_d = 4;
	_403_t5 = &_404_a;
	_403_t6 = &_404_b;
	_403_t7 = &_404_c;
	_403_t8 = &_404_d;
	_404_x = (struct2) {_403_t5, _403_t6, _403_t7, _403_t8};
	_403_t9 = 2;
	_403_t10 = *(((int64_t**)(&_404_x))+_403_t9);
	_403_t11 = 71;
	**(((int64_t**)(&_404_x))+_403_t9) = _403_t11;
	_403_t12 = 2;
	_403_t13 = *(((int64_t**)(&_404_x))+_403_t12);
	_403_t14 = *_403_t13;
	_403_$retval = _403_t14;
	return _403_$retval;
}


int main()
{
  printf("%ld",_403_main());
  return 0;
}

#endif
