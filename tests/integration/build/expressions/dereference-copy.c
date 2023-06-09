/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686278317
#define ORNG_1686278317

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();

/* Function forward definitions */
int64_t _270_main();

/* Function definitions */
int64_t _270_main() {
	int64_t _270_t1;
	int64_t* _271_y;
	int64_t _270_t4;
	int64_t _270_$retval;
BB0:
	_270_t1 = 4;
	_271_y = &_270_t1;
	_270_t4 = 28;
	*_271_y = _270_t4;
	_270_$retval = *_271_y;
	return _270_$retval;
}


int main()
{
  printf("%ld",_270_main());
  return 0;
}

#endif
