/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687316164
#define ORNG_1687316164

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _215_main();
int64_t _216_add(int64_t _216_x,int64_t _216_y);

/* Function definitions */
int64_t _215_main() {
	int64_t _215_t2;
	int64_t _215_t3;
	int64_t _215_t1;
	int64_t _215_t5;
	int64_t _215_t6;
	int64_t _215_t4;
	int64_t _215_t0;
	int64_t _215_$retval;
BB0:
	_215_t2 = 47;
	_215_t3 = 1;
	_215_t1 = _216_add(_215_t2, _215_t3);
	_215_t5 = 1;
	_215_t6 = 1;
	_215_t4 = _216_add(_215_t5, _215_t6);
	_215_t0 = _216_add(_215_t1, _215_t4);
	_215_$retval = _215_t0;
	return _215_$retval;
}

int64_t _216_add(int64_t _216_x,int64_t _216_y) {
	int64_t _216_$retval;
BB0:
	_216_$retval = _216_x + _216_y;
	return _216_$retval;
}


int main()
{
  printf("%ld",_215_main());
  return 0;
}

#endif
