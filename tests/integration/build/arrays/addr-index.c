/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687313803
#define ORNG_1687313803

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
int64_t _16_main();

/* Function definitions */
int64_t _16_main() {
	int64_t _16_t1;
	int64_t _16_t2;
	int64_t _16_t3;
	int64_t _16_t4;
	struct1 _17_x;
	int64_t _16_t5;
	int64_t _16_t6;
	int64_t* _16_t7;
	int64_t _16_t8;
	int64_t _16_t9;
	int64_t _16_t10;
	int64_t _16_$retval;
BB0:
	_16_t1 = 1;
	_16_t2 = 2;
	_16_t3 = 3;
	_16_t4 = 4;
	_17_x = (struct1) {_16_t1, _16_t2, _16_t3, _16_t4};
	_16_t5 = 0;
	_16_t7 = (((int64_t*)(&_17_x))+_16_t5);
	_16_t8 = 63;
	**&_16_t7 = _16_t8;
	_16_t9 = 0;
	_16_t10 = *(((int64_t*)(&_17_x))+_16_t9);
	_16_$retval = _16_t10;
	return _16_$retval;
}


int main()
{
  printf("%ld",_16_main());
  return 0;
}

#endif
