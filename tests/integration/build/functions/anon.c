/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687130061
#define ORNG_1687130061

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _205_main();
int64_t _207_$anon0(int64_t _207_x);
int64_t _208_apply(function0 _208_f,int64_t _208_x);

/* Function definitions */
int64_t _205_main() {
	function0 _205_t0;
	int64_t _205_t2;
	int64_t _205_t1;
	int64_t _205_$retval;
BB0:
	_205_t0 = _207_$anon0;
	_205_t2 = 43;
	_205_t1 = _208_apply(_205_t0, _205_t2);
	_205_$retval = _205_t1;
	return _205_$retval;
}

int64_t _207_$anon0(int64_t _207_x) {
	int64_t _207_$retval;
BB0:
	_207_$retval = _207_x;
	return _207_$retval;
}

int64_t _208_apply(function0 _208_f,int64_t _208_x) {
	int64_t _208_t0;
	int64_t _208_$retval;
BB0:
	_208_t0 = _208_f(_208_x);
	_208_$retval = _208_t0;
	return _208_$retval;
}


int main()
{
  printf("%ld",_205_main());
  return 0;
}

#endif
