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
	int64_t _3;
} struct1;

/* Function forward definitions */
int64_t _31_main();

/* Function definitions */
int64_t _31_main() {
	int64_t _31_t1;
	int64_t _31_t2;
	int64_t _31_t3;
	int64_t _31_t4;
	struct1 _32_x;
	struct1* _31_t5;
	struct1 _31_t6;
	int64_t _31_t7;
	int64_t _31_t8;
	struct1 _31_t9;
	int64_t _31_t10;
	int64_t _31_t11;
	int64_t _31_$retval;
BB0:
	_31_t1 = 1;
	_31_t2 = 2;
	_31_t3 = 3;
	_31_t4 = 4;
	_32_x = (struct1) {_31_t1, _31_t2, _31_t3, _31_t4};
	_31_t5 = &_32_x;
	_31_t6 = *_31_t5;
	_31_t7 = 2;
	_31_t8 = 70;
	*(((int64_t*)(_31_t5))+_31_t7) = _31_t8;
	_31_t9 = *_31_t5;
	_31_t10 = 2;
	_31_t11 = *(((int64_t*)(_31_t5))+_31_t10);
	_31_$retval = _31_t11;
	return _31_$retval;
}


int main()
{
  printf("%ld",_31_main());
  return 0;
}

#endif
