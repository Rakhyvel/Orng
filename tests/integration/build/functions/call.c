/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686109156
#define ORNG_1686109156

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _8_main();
int64_t _9_add(int64_t x,int64_t y);

int64_t _8_main() {
	int64_t (*_8_t0)(int64_t, int64_t);
	int64_t _8_t2;
	int64_t _8_t3;
	int64_t _8_$retval;
BB0:
	_8_t0 = _9_add;
	_8_t2 = 40;
	_8_t3 = 3;
	_8_$retval = _8_t0(_8_t2, _8_t3);
	return _8_$retval;
}

int64_t _9_add(int64_t x,int64_t y) {
	int64_t _9_$retval;
BB0:
	_9_$retval = x + y;
	return _9_$retval;
}


int main()
{
  printf("%ld",_8_main());
  return 0;
}

#endif
