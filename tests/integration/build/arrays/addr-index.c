/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687052042
#define ORNG_1687052042

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
int64_t _7_main();

/* Function definitions */
int64_t _7_main() {
	int64_t _7_t1;
	int64_t _7_t2;
	int64_t _7_t3;
	int64_t _7_t4;
	struct1 _8_x;
	int64_t _7_t5;
	int64_t _7_t6;
	int64_t* _8_y;
	int64_t _7_t8;
	int64_t _7_t9;
	int64_t _7_t10;
	int64_t _7_$retval;
BB0:
	_7_t1 = 1;
	_7_t2 = 2;
	_7_t3 = 3;
	_7_t4 = 4;
	_8_x = (struct1) {_7_t1, _7_t2, _7_t3, _7_t4};
	_7_t5 = 0;
	_7_t6 = ((int64_t*)(&_8_x))[_7_t5];
	_8_y = &_7_t6;
	_7_t8 = 63;
	*_8_y = _7_t8;
	_7_t9 = 0;
	_7_t10 = ((int64_t*)(&_8_x))[_7_t9];
	_7_$retval = _7_t10;
	return _7_$retval;
}


int main()
{
  printf("%ld",_7_main());
  return 0;
}

#endif
