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
int64_t _395_main();

/* Function definitions */
int64_t _395_main() {
	int64_t _395_t1;
	int64_t _395_t2;
	int64_t _395_t3;
	int64_t _395_t4;
	struct1 _396_x;
	struct1* _395_t5;
	struct1 _395_t6;
	int64_t _395_t7;
	int64_t _395_t8;
	struct1 _395_t9;
	int64_t _395_t10;
	int64_t _395_t11;
	int64_t _395_$retval;
BB0:
	_395_t1 = 1;
	_395_t2 = 2;
	_395_t3 = 3;
	_395_t4 = 4;
	_396_x = (struct1) {_395_t1, _395_t2, _395_t3, _395_t4};
	_395_t5 = &_396_x;
	_395_t7 = 2;
	_395_t8 = 70;
	*(((int64_t*)(_395_t5))+_395_t7) = _395_t8;
	_395_t10 = 2;
	_395_t11 = *(((int64_t*)(_395_t5))+_395_t10);
	_395_$retval = _395_t11;
	return _395_$retval;
}


int main()
{
  printf("%ld",_395_main());
  return 0;
}

#endif
