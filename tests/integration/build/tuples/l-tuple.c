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
int64_t _325_main();

/* Function definitions */
int64_t _325_main() {
	int64_t _325_t1;
	int64_t _325_t2;
	int64_t _325_t3;
	int64_t _325_t4;
	struct1 _326_x;
	int64_t _325_t5;
	int64_t* _326_y;
	int64_t _325_t7;
	int64_t _325_t8;
	int64_t _325_$retval;
BB0:
	_325_t1 = 1;
	_325_t2 = 2;
	_325_t3 = 3;
	_325_t4 = 4;
	_326_x = (struct1) {_325_t1, _325_t2, _325_t3, _325_t4};
	_326_y = (&_326_x._3);
	_325_t7 = 66;
	*(&_326_x._3) = _325_t7;
	_325_t8 = _326_x._3;
	_325_$retval = _325_t8;
	return _325_$retval;
}


int main()
{
  printf("%ld",_325_main());
  return 0;
}

#endif
