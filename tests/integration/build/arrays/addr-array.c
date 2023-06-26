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
} struct1;

/* Function forward definitions */
int64_t _399_main();

/* Function definitions */
int64_t _399_main() {
	int64_t _399_t1;
	int64_t _399_t2;
	int64_t _399_t3;
	int64_t _399_t4;
	struct1 _400_x;
	struct1* _399_t5;
	struct1 _399_t6;
	int64_t _399_t7;
	int64_t _399_t8;
	struct1 _399_t9;
	int64_t _399_t10;
	int64_t _399_t11;
	int64_t _399_$retval;
BB0:
	_399_t1 = 1;
	_399_t2 = 2;
	_399_t3 = 3;
	_399_t4 = 4;
	_400_x = (struct1) {_399_t1, _399_t2, _399_t3, _399_t4};
	_399_t5 = &_400_x;
	_399_t7 = 2;
	_399_t8 = 70;
	*(((int64_t*)(_399_t5))+_399_t7) = _399_t8;
	_399_t10 = 2;
	_399_t11 = *(((int64_t*)(_399_t5))+_399_t10);
	_399_$retval = _399_t11;
	return _399_$retval;
}


int main()
{
  printf("%ld",_399_main());
  return 0;
}

#endif
