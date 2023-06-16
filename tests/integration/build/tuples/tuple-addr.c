/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686884233
#define ORNG_1686884233

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();
typedef struct {
	int64_t* _0;
	int64_t* _1;
} struct4;

/* Function forward definitions */
int64_t _319_main();

/* Function definitions */
int64_t _319_main() {
	int64_t _320_x;
	int64_t _320_y;
	int64_t* _319_t3;
	int64_t* _319_t4;
	struct4 _320_z;
	int64_t* _319_t5;
	int64_t _319_t6;
	int64_t* _319_t7;
	int64_t _319_t8;
	int64_t _319_$retval;
BB0:
	_320_x = 30;
	_320_y = 29;
	_319_t3 = &_320_x;
	_319_t4 = &_320_y;
	_320_z = (struct4) {_319_t3, _319_t4};
	_319_t5 = _320_z._0;
	_319_t6 = *_319_t5;
	_319_t7 = _320_z._1;
	_319_t8 = *_319_t7;
	_319_$retval = _319_t6 + _319_t8;
	return _319_$retval;
}


int main()
{
  printf("%ld",_319_main());
  return 0;
}

#endif
