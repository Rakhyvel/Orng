/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687129465
#define ORNG_1687129465

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
	int64_t _2;
	int64_t _3;
} struct1;

/* Function forward definitions */
int64_t _351_main();

/* Function definitions */
int64_t _351_main() {
	int64_t _351_t1;
	int64_t _351_t2;
	int64_t _351_t3;
	int64_t _351_t4;
	struct1 _352_x;
	int64_t _351_t5;
	int64_t _351_t6;
	int64_t* _352_y;
	int64_t _351_t8;
	int64_t _351_t9;
	int64_t _351_t10;
	int64_t _351_$retval;
BB0:
	_351_t1 = 1;
	_351_t2 = 2;
	_351_t3 = 3;
	_351_t4 = 4;
	_352_x = (struct1) {_351_t1, _351_t2, _351_t3, _351_t4};
	_351_t5 = 0;
	_352_y = (((int64_t*)(&_352_x))+_351_t5);
	_351_t8 = 63;
	*(((int64_t*)(&_352_x))+_351_t5) = _351_t8;
	_351_t9 = 0;
	_351_t10 = ((int64_t*)(&_352_x))[_351_t9];
	_351_$retval = _351_t10;
	return _351_$retval;
}


int main()
{
  printf("%ld",_351_main());
  return 0;
}

#endif
