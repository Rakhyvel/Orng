/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687227438
#define ORNG_1687227438

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t* _0;
	int64_t* _1;
} struct2;

/* Function forward definitions */
int64_t _341_main();

/* Function definitions */
int64_t _341_main() {
	int64_t _342_x;
	int64_t _342_y;
	int64_t* _341_t3;
	int64_t* _341_t4;
	struct2 _342_z;
	int64_t* _341_t5;
	int64_t _341_t6;
	int64_t* _341_t7;
	int64_t _341_t8;
	int64_t _341_$retval;
BB0:
	_342_x = 30;
	_342_y = 29;
	_341_t3 = &_342_x;
	_341_t4 = &_342_y;
	_342_z = (struct2) {_341_t3, _341_t4};
	_341_t5 = *&(_342_z._0);
	_341_t6 = *_341_t5;
	_341_t7 = *&(_342_z._1);
	_341_t8 = *_341_t7;
	_341_$retval = _341_t6 + _341_t8;
	return _341_$retval;
}


int main()
{
  printf("%ld",_341_main());
  return 0;
}

#endif
