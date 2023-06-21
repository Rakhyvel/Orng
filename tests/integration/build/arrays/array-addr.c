/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687316164
#define ORNG_1687316164

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
int64_t _399_main();

/* Function definitions */
int64_t _399_main() {
	int64_t _400_a;
	int64_t _400_b;
	int64_t _400_c;
	int64_t _400_d;
	int64_t* _399_t5;
	int64_t* _399_t6;
	int64_t* _399_t7;
	int64_t* _399_t8;
	struct2 _400_x;
	int64_t _399_t9;
	int64_t* _399_t10;
	int64_t _399_t11;
	int64_t _399_t12;
	int64_t* _399_t13;
	int64_t _399_t14;
	int64_t _399_$retval;
BB0:
	_400_a = 1;
	_400_b = 2;
	_400_c = 3;
	_400_d = 4;
	_399_t5 = &_400_a;
	_399_t6 = &_400_b;
	_399_t7 = &_400_c;
	_399_t8 = &_400_d;
	_400_x = (struct2) {_399_t5, _399_t6, _399_t7, _399_t8};
	_399_t9 = 2;
	_399_t10 = *(((int64_t**)(&_400_x))+_399_t9);
	_399_t11 = 71;
	**(((int64_t**)(&_400_x))+_399_t9) = _399_t11;
	_399_t12 = 2;
	_399_t13 = *(((int64_t**)(&_400_x))+_399_t12);
	_399_t14 = *_399_t13;
	_399_$retval = _399_t14;
	return _399_$retval;
}


int main()
{
  printf("%ld",_399_main());
  return 0;
}

#endif
