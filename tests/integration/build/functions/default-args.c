/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686513839
#define ORNG_1686513839

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();
typedef int64_t(*function1)(int64_t, int64_t);

/* Function forward definitions */
int64_t _207_main();
int64_t _208_add(int64_t x,int64_t y);

/* Function definitions */
int64_t _207_main() {
	function1 _207_t0;
	function1 _207_t2;
	int64_t _207_t4;
	int64_t _207_t5;
	int64_t _207_t3;
	function1 _207_t6;
	int64_t _207_t8;
	int64_t _207_t9;
	int64_t _207_t7;
	int64_t _207_$retval;
BB0:
	_207_t0 = _208_add;
	_207_t2 = _208_add;
	_207_t4 = 47;
	_207_t5 = 1;
	_207_t3 = _207_t2(_207_t4, _207_t5);
	_207_t6 = _208_add;
	_207_t8 = 1;
	_207_t9 = 1;
	_207_t7 = _207_t6(_207_t8, _207_t9);
	_207_$retval = _207_t0(_207_t3, _207_t7);
	return _207_$retval;
}

int64_t _208_add(int64_t x,int64_t y) {
	int64_t _208_$retval;
BB0:
	_208_$retval = x + y;
	return _208_$retval;
}


int main()
{
  printf("%ld",_207_main());
  return 0;
}

#endif
