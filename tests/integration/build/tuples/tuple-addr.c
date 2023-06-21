/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687313477
#define ORNG_1687313477

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t* _0;
	int64_t* _1;
} struct2;

/* Function forward definitions */
int64_t _38_main();

/* Function definitions */
int64_t _38_main() {
	int64_t _39_x;
	int64_t _39_y;
	int64_t* _38_t3;
	int64_t* _38_t4;
	struct2 _39_z;
	int64_t* _38_t5;
	int64_t _38_t6;
	int64_t* _38_t7;
	int64_t _38_t8;
	int64_t _38_$retval;
BB0:
	_39_x = 30;
	_39_y = 29;
	_38_t3 = &_39_x;
	_38_t4 = &_39_y;
	_39_z = (struct2) {_38_t3, _38_t4};
	_38_t5 = *&((&_39_z)->_0);
	_38_t6 = *_38_t5;
	_38_t7 = *&((&_39_z)->_1);
	_38_t8 = *_38_t7;
	_38_$retval = _38_t6 + _38_t8;
	return _38_$retval;
}


int main()
{
  printf("%ld",_38_main());
  return 0;
}

#endif
