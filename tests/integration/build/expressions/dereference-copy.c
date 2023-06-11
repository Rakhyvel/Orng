/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686513839
#define ORNG_1686513839

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();

/* Function forward definitions */
int64_t _274_main();

/* Function definitions */
int64_t _274_main() {
	int64_t _274_t1;
	int64_t* _275_y;
	int64_t _274_t4;
	int64_t _274_$retval;
BB0:
	_274_t1 = 4;
	_275_y = &_274_t1;
	_274_t4 = 28;
	*_275_y = _274_t4;
	_274_$retval = *_275_y;
	return _274_$retval;
}


int main()
{
  printf("%ld",_274_main());
  return 0;
}

#endif
