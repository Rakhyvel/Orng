/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686709170
#define ORNG_1686709170

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();
typedef struct {
	int64_t _0;
	int64_t _1;
} struct4;
typedef int64_t(*function3)(int64_t, int64_t);

/* Function forward definitions */
int64_t _240_main();
int64_t _241_div(int64_t x,int64_t y);

/* Function definitions */
int64_t _240_main() {
	function3 _240_t0;
	int64_t _240_t2;
	int64_t _240_t3;
	int64_t _240_$retval;
BB0:
	_240_t0 = _241_div;
	_240_t2 = 510;
	_240_t3 = 10;
	_240_$retval = _240_t0(_240_t2, _240_t3);
	return _240_$retval;
}

int64_t _241_div(int64_t x,int64_t y) {
	int64_t _241_$retval;
BB0:
	_241_$retval = x / y;
	return _241_$retval;
}


int main()
{
  printf("%ld",_240_main());
  return 0;
}

#endif
