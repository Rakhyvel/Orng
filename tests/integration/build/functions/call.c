/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686626622
#define ORNG_1686626622

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
int64_t _207_main();
int64_t _208_add(int64_t x,int64_t y);

/* Function definitions */
int64_t _207_main() {
	function3 _207_t0;
	int64_t _207_t2;
	int64_t _207_t3;
	int64_t _207_$retval;
BB0:
	_207_t0 = _208_add;
	_207_t2 = 40;
	_207_t3 = 3;
	_207_$retval = _207_t0(_207_t2, _207_t3);
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
