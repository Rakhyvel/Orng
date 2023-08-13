/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1691899681445729255
#define ORNG_1691899681445729255

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */
typedef struct {
	int64_t* _0;
	int64_t* _1;
	int64_t* _2;
	int64_t* _3;
} struct0;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _3_a;
	int64_t _3_b;
	int64_t _3_c;
	int64_t _3_d;
	int64_t* _2_t5;
	int64_t* _2_t6;
	int64_t* _2_t7;
	int64_t* _2_t8;
	struct0 _3_x;
	int64_t _2_t9;
	int64_t _2_t11;
	int64_t _2_t12;
	int64_t* _2_t13;
	int64_t _2_$retval;
BB0:
	_3_a = 1;
	_3_b = 2;
	_3_c = 3;
	_3_d = 4;
	_2_t5 = &_3_a;
	_2_t6 = &_3_b;
	_2_t7 = &_3_c;
	_2_t8 = &_3_d;
	_3_x = (struct0) {_2_t5, _2_t6, _2_t7, _2_t8};
	_2_t9 = 2;
	_2_t11 = 71;
	**(((int64_t**)(&_3_x))+_2_t9) = _2_t11;
	_2_t12 = 2;
	_2_t13 = *(((int64_t**)(&_3_x))+_2_t12);
	_2_$retval = *_2_t13;
	return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
