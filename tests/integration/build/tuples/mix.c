/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687123271
#define ORNG_1687123271

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t* _1;
} struct2;
typedef struct {
	int64_t _0;
	int64_t _1;
	int64_t _2;
	int64_t _3;
} struct3;

/* Function forward definitions */
int64_t _2_main();
struct3 _4_get_array(int64_t a,int64_t b);

/* Function definitions */
int64_t _2_main() {
	int64_t _3_z;
	int64_t* _2_t5;
	struct2 _3_y;
	int64_t _2_t6;
	int64_t _2_$retval;
BB0:
	_3_z = 64;
	_2_t5 = &_3_z;
	_3_y = (struct2) {_3_z, _2_t5};
	_2_t6 = _3_y._0;
	_2_$retval = _2_t6;
	return _2_$retval;
}

struct3 _4_get_array(int64_t a,int64_t b) {
	struct3 _4_$retval;
BB0:
	_4_$retval = (struct3) {a, b, a, b};
	return _4_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
