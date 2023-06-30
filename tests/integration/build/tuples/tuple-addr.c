/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686796984487473394
#define ORNG_1686796984487473394

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t* _0;
	int64_t* _1;
} struct2;

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _3_x;
	int64_t _3_y;
	int64_t* _2_t3;
	int64_t* _2_t4;
	struct2 _3_z;
	int64_t* _2_t5;
	int64_t _2_t6;
	int64_t* _2_t7;
	int64_t _2_t8;
	int64_t _2_$retval;
BB0:
	_3_x = 30;
	_3_y = 29;
	_2_t3 = &_3_x;
	_2_t4 = &_3_y;
	_3_z = (struct2) {_2_t3, _2_t4};
	_2_t5 = *&((&_3_z)->_0);
	_2_t6 = *_2_t5;
	_2_t7 = *&((&_3_z)->_1);
	_2_t8 = *_2_t7;
	_2_$retval = _2_t6 + _2_t8;
	return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
