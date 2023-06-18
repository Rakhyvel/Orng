/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687129465
#define ORNG_1687129465

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _246_main();
int64_t _247_div(int64_t _247_x,int64_t _247_y);

/* Function definitions */
int64_t _246_main() {
	int64_t _246_t1;
	int64_t _246_t2;
	int64_t _246_t0;
	int64_t _246_$retval;
BB0:
	_246_t1 = 510;
	_246_t2 = 10;
	_246_t0 = _247_div(_246_t1, _246_t2);
	_246_$retval = _246_t0;
	return _246_$retval;
}

int64_t _247_div(int64_t _247_x,int64_t _247_y) {
	int64_t _247_$retval;
BB0:
	_247_$retval = _247_x / _247_y;
	return _247_$retval;
}


int main()
{
  printf("%ld",_246_main());
  return 0;
}

#endif
