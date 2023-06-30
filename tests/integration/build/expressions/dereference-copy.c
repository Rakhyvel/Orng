/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684727580815608943
#define ORNG_1684727580815608943

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _304_main();

/* Function definitions */
int64_t _304_main() {
	int64_t _305_x;
	int64_t* _304_t1;
	int64_t _304_t2;
	int64_t _304_t3;
	int64_t _304_$retval;
BB0:
	_305_x = 4;
	_304_t1 = &_305_x;
	_304_t2 = 28;
	**&_304_t1 = _304_t2;
	_304_t3 = *_304_t1;
	_304_$retval = _304_t3;
	return _304_$retval;
}


int main()
{
  printf("%ld",_304_main());
  return 0;
}

#endif
