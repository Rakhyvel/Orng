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
int64_t _329_main();

/* Function definitions */
int64_t _329_main() {
	int64_t _329_t1;
	int64_t _329_t2;
	struct1 _330_x;
	int64_t _329_t3;
	int64_t _329_t4;
	int64_t _329_$retval;
BB0:
	_329_t1 = 20;
	_329_t2 = 3;
	_330_x = (struct1) {_329_t1, _329_t2};
	_329_t3 = *&((&_330_x)->_0);
	_329_t4 = *&((&_330_x)->_1);
	_329_$retval = _329_t3 * _329_t4;
	return _329_$retval;
}


int main()
{
  printf("%ld",_329_main());
  return 0;
}

#endif
