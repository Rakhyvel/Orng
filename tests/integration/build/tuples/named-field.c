/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687129465
#define ORNG_1687129465

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
	int64_t _313_t2;
	struct1 _314_x;
	int64_t _313_t3;
	int64_t _313_t4;
	int64_t _313_$retval;
BB0:
	_313_t1 = 20;
	_313_t2 = 3;
	_314_x = (struct1) {_313_t1, _313_t2};
	_313_t3 = _314_x._0;
	_313_t4 = _314_x._1;
	_313_$retval = _313_t3 * _313_t4;
	return _313_$retval;
}


int main()
{
  printf("%ld",_313_main());
  return 0;
}

#endif
