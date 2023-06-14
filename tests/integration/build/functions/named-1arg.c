/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686709170
#define ORNG_1686709170

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();
typedef int64_t(*function3)(int64_t);

/* Function forward definitions */
int64_t _215_main();
int64_t _216_id(int64_t x);

/* Function definitions */
int64_t _215_main() {
	function3 _215_t0;
	int64_t _215_t2;
	int64_t _215_$retval;
BB0:
	_215_t0 = _216_id;
	_215_t2 = 52;
	_215_$retval = _215_t0(_215_t2);
	return _215_$retval;
}

int64_t _216_id(int64_t x) {
	int64_t _216_$retval;
BB0:
	_216_$retval = x;
	return _216_$retval;
}


int main()
{
  printf("%ld",_215_main());
  return 0;
}

#endif
