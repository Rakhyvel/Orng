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
} struct1;

/* Function forward definitions */
int64_t _345_main();

/* Function definitions */
int64_t _345_main() {
	int64_t _345_t1;
	int64_t _345_t2;
	struct1 _346_x;
	int64_t _345_t3;
	int64_t _345_t4;
	int64_t _345_$retval;
BB0:
	_345_t1 = 50;
	_345_t2 = 5;
	_346_x = (struct1) {_345_t1, _345_t2};
	_345_t3 = *&((&_346_x)->_0);
	_345_t4 = *&((&_346_x)->_1);
	_345_$retval = _345_t3 + _345_t4;
	return _345_$retval;
}


int main()
{
  printf("%ld",_345_main());
  return 0;
}

#endif
