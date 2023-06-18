/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687127760
#define ORNG_1687127760

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
int64_t _331_main();
struct3 _333_get_array(int64_t a,int64_t b);

/* Function definitions */
int64_t _331_main() {
	int64_t _332_z;
	int64_t* _331_t5;
	struct2 _332_y;
	int64_t _331_t6;
	int64_t _331_$retval;
BB0:
	_332_z = 64;
	_331_t5 = &_332_z;
	_332_y = (struct2) {_332_z, _331_t5};
	_331_t6 = _332_y._0;
	_331_$retval = _331_t6;
	return _331_$retval;
}

struct3 _333_get_array(int64_t a,int64_t b) {
	struct3 _333_$retval;
BB0:
	_333_$retval = (struct3) {a, b, a, b};
	return _333_$retval;
}


int main()
{
  printf("%ld",_331_main());
  return 0;
}

#endif
