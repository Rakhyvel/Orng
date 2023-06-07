/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686104538
#define ORNG_1686104538

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _146_main();
int64_t _147_add(int64_t x,int64_t y);

int64_t _146_main() {
	int64_t (*_146_t0)(int64_t, int64_t);
	int64_t _146_t2;
	int64_t _146_t3;
	int64_t _146_$retval;
BB0:
	_146_t0 = _147_add;
	_146_t2 = 40;
	_146_t3 = 3;
	_146_$retval = _146_t0(_146_t2, _146_t3);
	return _146_$retval;
}

int64_t _147_add(int64_t x,int64_t y) {
	int64_t _147_$retval;
BB0:
	_147_$retval = x + y;
	return _147_$retval;
}


int main()
{
  printf("%ld",_146_main());
  return 0;
}

#endif
