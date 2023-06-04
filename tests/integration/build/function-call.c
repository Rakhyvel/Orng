/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685922416
#define ORNG_1685922416

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _116_main();
int64_t _117_add(int64_t _117_x, int64_t _117_y);

int64_t _116_main() {
	int64_t (*_116_t0)(int64_t _117_x, int64_t _117_y);
	int64_t _116_t2;
	int64_t _116_t3;
	int64_t _116_t1;
	int64_t _116_$retval;
BB0:
	_116_t0 = _117_add;
	_116_t2 = 40;
	_116_t3 = 3;
	_116_t1 = _116_t0(_116_t2, _116_t3);
	_116_$retval = _116_t1;
	return _116_$retval;
}

int64_t _117_add(int64_t _117_x, int64_t _117_y) {
	int64_t _117_$retval;
BB0:
	_117_$retval = _117_x + _117_y;
	return _117_$retval;
}


int main()
{
  printf("%ld",_116_main());
  return 0;
}

#endif
