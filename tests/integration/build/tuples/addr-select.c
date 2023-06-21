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
	int64_t _3;
} struct1;

/* Function forward definitions */
int64_t _321_main();

/* Function definitions */
int64_t _321_main() {
	int64_t _321_t1;
	int64_t _321_t2;
	int64_t _321_t3;
	int64_t _321_t4;
	struct1 _322_x;
	int64_t _321_t5;
	int64_t* _321_t6;
	int64_t _321_t7;
	int64_t _321_t8;
	int64_t _321_$retval;
BB0:
	_321_t1 = 1;
	_321_t2 = 2;
	_321_t3 = 3;
	_321_t4 = 4;
	_322_x = (struct1) {_321_t1, _321_t2, _321_t3, _321_t4};
	_321_t5 = *&((&_322_x)->_3);
	_321_t6 = &((&_322_x)->_3);
	_321_t7 = 66;
	**&_321_t6 = _321_t7;
	_321_t8 = *&((&_322_x)->_3);
	_321_$retval = _321_t8;
	return _321_$retval;
}


int main()
{
  printf("%ld",_321_main());
  return 0;
}

#endif
