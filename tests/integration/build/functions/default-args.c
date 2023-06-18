/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687129465
#define ORNG_1687129465

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _211_main();
int64_t _212_add(int64_t _212_x,int64_t _212_y);

/* Function definitions */
int64_t _211_main() {
	int64_t _211_t2;
	int64_t _211_t3;
	int64_t _211_t1;
	int64_t _211_t5;
	int64_t _211_t6;
	int64_t _211_t4;
	int64_t _211_t0;
	int64_t _211_$retval;
BB0:
	_211_t2 = 47;
	_211_t3 = 1;
	_211_t1 = _212_add(_211_t2, _211_t3);
	_211_t5 = 1;
	_211_t6 = 1;
	_211_t4 = _212_add(_211_t5, _211_t6);
	_211_t0 = _212_add(_211_t1, _211_t4);
	_211_$retval = _211_t0;
	return _211_$retval;
}

int64_t _212_add(int64_t _212_x,int64_t _212_y) {
	int64_t _212_$retval;
BB0:
	_212_$retval = _212_x + _212_y;
	return _212_$retval;
}


int main()
{
  printf("%ld",_211_main());
  return 0;
}

#endif
