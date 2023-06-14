/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686712671
#define ORNG_1686712671

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
int64_t _244_main();
int64_t _245_add(int64_t x,int64_t y);

/* Function definitions */
int64_t _244_main() {
	int64_t _244_t1;
	int64_t _244_t2;
	int64_t _244_t0;
	int64_t _244_$retval;
BB0:
	_244_t1 = 4;
	_244_t2 = 50;
	_244_t0 = _245_add(_244_t1, _244_t2);
	_244_$retval = _244_t0;
	return _244_$retval;
}

int64_t _245_add(int64_t x,int64_t y) {
	int64_t _245_$retval;
BB0:
	_245_$retval = x + y;
	return _245_$retval;
}


int main()
{
  printf("%ld",_244_main());
  return 0;
}

#endif
