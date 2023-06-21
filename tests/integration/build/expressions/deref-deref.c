/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687316164
#define ORNG_1687316164

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _314_main();

/* Function definitions */
int64_t _314_main() {
	int64_t _315_x;
	int64_t* _314_t1;
	int64_t* _315_y;
	int64_t** _314_t2;
	int64_t* _314_t3;
	int64_t _314_t4;
	int64_t* _314_t5;
	int64_t _314_t6;
	int64_t _314_$retval;
BB0:
	_315_x = 75;
	_314_t1 = &_315_x;
	_315_y = _314_t1;
	_314_t2 = &_315_y;
	_314_t4 = 75;
	**_314_t2 = _314_t4;
	_314_t5 = *_314_t2;
	_314_t6 = *_314_t5;
	_314_$retval = _314_t6;
	return _314_$retval;
}


int main()
{
  printf("%ld",_314_main());
  return 0;
}

#endif
