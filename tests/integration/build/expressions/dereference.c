/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686712671
#define ORNG_1686712671

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();

/* Function forward definitions */
int64_t _256_main();

/* Function definitions */
int64_t _256_main() {
	int64_t _257_x;
	int64_t* _257_y;
	int64_t _256_$retval;
BB0:
	_257_x = 29;
	_257_y = &_257_x;
	_256_$retval = *_257_y;
	return _256_$retval;
}


int main()
{
  printf("%ld",_256_main());
  return 0;
}

#endif
