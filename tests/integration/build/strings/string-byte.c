/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688935684845966977
#define ORNG_1688935684845966977

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	uint8_t* _0;
	int64_t _1;
} struct0;

/* Interned Strings */
char* string_0 = "\x5B";

/* Function forward definitions */
uint8_t _2_main();

/* Function definitions */
uint8_t _2_main() {
	struct0 _3_x;
	int64_t _2_t1;
	uint8_t _2_t2;
	uint8_t _2_$retval;
BB0:
	_3_x = (struct0) {string_0, 5};
	_2_t1 = 0;
	_2_t2 = *(((uint8_t*)((&_3_x)->_0))+_2_t1);
	_2_$retval = _2_t2;
	return _2_$retval;
}


int main()
{
  printf("%d",_2_main());
  return 0;
}

#endif