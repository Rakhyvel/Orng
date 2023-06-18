/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687131173
#define ORNG_1687131173

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _313_main();

/* Function definitions */
int64_t _313_main() {
	int64_t _313_t1;
	int64_t _313_t4;
	struct1 _314_x;
	struct1* _314_y;
	struct1 _313_t6;
	int64_t _313_t7;
	struct1 _313_t8;
	int64_t _313_t9;
	int64_t _313_$retval;
BB0:
	_313_t1 = 19;
	_313_t4 = 39;
	_314_x = (struct1) {_313_t1, _313_t4};
	_314_y = &_314_x;
	_313_t6 = *_314_y;
	_313_t7 = _313_t6._0;
	_313_t8 = *_314_y;
	_313_t9 = _313_t8._1;
	_313_$retval = _313_t7 + _313_t9;
	return _313_$retval;
}


int main()
{
  printf("%ld",_313_main());
  return 0;
}

#endif
