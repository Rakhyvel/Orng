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
} struct1;

/* Function forward definitions */
int64_t _333_main();

/* Function definitions */
int64_t _333_main() {
	int64_t _333_t1;
	int64_t _333_t2;
	struct1 _334_x;
	struct1* _333_t3;
	struct1 _333_t4;
	int64_t _333_t5;
	struct1 _333_t6;
	int64_t _333_t7;
	struct1 _333_t8;
	int64_t _333_t9;
	int64_t _333_$retval;
BB0:
	_333_t1 = 11;
	_333_t2 = 11;
	_334_x = (struct1) {_333_t1, _333_t2};
	_333_t3 = &_334_x;
	_333_t5 = 50;
	(_333_t3)->_0 = _333_t5;
	_333_t7 = *&((_333_t3)->_0);
	_333_t9 = *&((_333_t3)->_1);
	_333_$retval = _333_t7 + _333_t9;
	return _333_$retval;
}


int main()
{
  printf("%ld",_333_main());
  return 0;
}

#endif
