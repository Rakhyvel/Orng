/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687227438
#define ORNG_1687227438

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _321_main();

/* Function definitions */
int64_t _321_main() {
	int64_t _321_t1;
	int64_t _321_t2;
	struct1 _322_x;
	struct1* _321_t3;
	struct1 _321_t4;
	int64_t _321_t5;
	struct1 _321_t6;
	int64_t _321_t7;
	int64_t _321_$retval;
BB0:
	_321_t1 = 50;
	_321_t2 = 11;
	_322_x = (struct1) {_321_t1, _321_t2};
	_321_t3 = &_322_x;
	_321_t4 = *_321_t3;
	_321_t5 = *&(_321_t4._0);
	_321_t6 = *_321_t3;
	_321_t7 = *&(_321_t6._1);
	_321_$retval = _321_t5 + _321_t7;
	return _321_$retval;
}


int main()
{
  printf("%ld",_321_main());
  return 0;
}

#endif
