/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687316164
#define ORNG_1687316164

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t* _0;
	int64_t* _1;
} struct2;

/* Function forward definitions */
int64_t _357_main();

/* Function definitions */
int64_t _357_main() {
	int64_t _358_x;
	int64_t _358_y;
	int64_t* _357_t3;
	int64_t* _357_t4;
	struct2 _358_z;
	int64_t* _357_t5;
	int64_t _357_t6;
	int64_t* _357_t7;
	int64_t _357_t8;
	int64_t _357_$retval;
BB0:
	_358_x = 30;
	_358_y = 29;
	_357_t3 = &_358_x;
	_357_t4 = &_358_y;
	_358_z = (struct2) {_357_t3, _357_t4};
	_357_t5 = *&((&_358_z)->_0);
	_357_t6 = *_357_t5;
	_357_t7 = *&((&_358_z)->_1);
	_357_t8 = *_357_t7;
	_357_$retval = _357_t6 + _357_t8;
	return _357_$retval;
}


int main()
{
  printf("%ld",_357_main());
  return 0;
}

#endif
