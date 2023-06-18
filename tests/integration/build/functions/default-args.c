/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687128100
#define ORNG_1687128100

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _16_main();
int64_t _17_add(int64_t x,int64_t y);

/* Function definitions */
int64_t _16_main() {
	int64_t _16_t2;
	int64_t _16_t3;
	int64_t _16_t1;
	int64_t _16_t5;
	int64_t _16_t6;
	int64_t _16_t4;
	int64_t _16_t0;
	int64_t _16_$retval;
BB0:
	_16_t2 = 47;
	_16_t3 = 1;
	_16_t1 = _17_add(_16_t2, _16_t3);
	_16_t5 = 1;
	_16_t6 = 1;
	_16_t4 = _17_add(_16_t5, _16_t6);
	_16_t0 = _17_add(_16_t1, _16_t4);
	_16_$retval = _16_t0;
	return _16_$retval;
}

int64_t _17_add(int64_t x,int64_t y) {
	int64_t _17_$retval;
BB0:
	_17_$retval = x + y;
	return _17_$retval;
}


int main()
{
  printf("%ld",_16_main());
  return 0;
}

#endif
