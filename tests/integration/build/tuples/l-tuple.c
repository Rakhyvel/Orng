/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687131173
#define ORNG_1687131173

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
int64_t _329_main();

/* Function definitions */
int64_t _329_main() {
	int64_t _329_t1;
	int64_t _329_t2;
	int64_t _329_t3;
	int64_t _329_t4;
	struct1 _330_x;
	int64_t _329_t5;
	int64_t* _330_y;
	int64_t _329_t7;
	int64_t _329_t8;
	int64_t _329_$retval;
BB0:
	_329_t1 = 1;
	_329_t2 = 2;
	_329_t3 = 3;
	_329_t4 = 4;
	_330_x = (struct1) {_329_t1, _329_t2, _329_t3, _329_t4};
	_330_y = (&_330_x._3);
	_329_t7 = 66;
	*(&_330_x._3) = _329_t7;
	_329_t8 = _330_x._3;
	_329_$retval = _329_t8;
	return _329_$retval;
}


int main()
{
  printf("%ld",_329_main());
  return 0;
}

#endif
