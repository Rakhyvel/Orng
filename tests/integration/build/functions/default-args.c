/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686463458
#define ORNG_1686463458

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();
typedef int64_t(*function1)(int64_t, int64_t);

/* Function forward definitions */
int64_t _12_main();
int64_t _13_add(int64_t x,int64_t y);

/* Function definitions */
int64_t _12_main() {
	function1 _12_t0;
	int64_t _12_t2;
	int64_t _12_t3;
	int64_t _12_$retval;
BB0:
	_12_t0 = _13_add;
	_12_t2 = 25;
	_12_t3 = 25;
	_12_$retval = _12_t0(_12_t2, _12_t3);
	return _12_$retval;
}

int64_t _13_add(int64_t x,int64_t y) {
	int64_t _13_$retval;
BB0:
	_13_$retval = x + y;
	return _13_$retval;
}


int main()
{
  printf("%ld",_12_main());
  return 0;
}

#endif
