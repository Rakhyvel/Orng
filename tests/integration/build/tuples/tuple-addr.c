/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686886319
#define ORNG_1686886319

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t* _0;
	int64_t* _1;
} struct2;

/* Function forward definitions */
int64_t _327_main();

/* Function definitions */
int64_t _327_main() {
	int64_t _328_x;
	int64_t _328_y;
	int64_t* _327_t3;
	int64_t* _327_t4;
	struct2 _328_z;
	int64_t* _327_t5;
	int64_t _327_t6;
	int64_t* _327_t7;
	int64_t _327_t8;
	int64_t _327_$retval;
BB0:
	_328_x = 30;
	_328_y = 29;
	_327_t3 = &_328_x;
	_327_t4 = &_328_y;
	_328_z = (struct2) {_327_t3, _327_t4};
	_327_t5 = _328_z._0;
	_327_t6 = *_327_t5;
	_327_t7 = _328_z._1;
	_327_t8 = *_327_t7;
	_327_$retval = _327_t6 + _327_t8;
	return _327_$retval;
}


int main()
{
  printf("%ld",_327_main());
  return 0;
}

#endif
