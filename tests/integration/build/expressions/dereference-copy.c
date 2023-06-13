/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686626623
#define ORNG_1686626623

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();

/* Function forward definitions */
int64_t _290_main();

/* Function definitions */
int64_t _290_main() {
	int64_t _290_t1;
	int64_t* _291_y;
	int64_t _290_t4;
	int64_t _290_$retval;
BB0:
	_290_t1 = 4;
	_291_y = &_290_t1;
	_290_t4 = 28;
	*_291_y = _290_t4;
	_290_$retval = *_291_y;
	return _290_$retval;
}


int main()
{
  printf("%ld",_290_main());
  return 0;
}

#endif
