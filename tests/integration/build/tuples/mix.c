/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687738073
#define ORNG_1687738073

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
	int64_t _2;
	int64_t _3;
} struct1;
typedef struct {
	int64_t _0;
	int64_t* _1;
} struct3;

/* Function forward definitions */
int64_t _361_main();
struct1 _363_get_array(int64_t _363_a,int64_t _363_b);

/* Function definitions */
int64_t _361_main() {
	int64_t _361_t1;
	int64_t _361_t2;
	struct1 _361_t0;
	int64_t _362_z;
	int64_t* _361_t5;
	struct3 _362_y;
	int64_t _361_t6;
	int64_t _361_$retval;
BB0:
	_361_t1 = 15;
	_361_t2 = 16;
	_361_t0 = _363_get_array(_361_t1, _361_t2);
	_362_z = 64;
	_361_t5 = &_362_z;
	_362_y = (struct3) {_362_z, _361_t5};
	_361_t6 = *&((&_362_y)->_0);
	_361_$retval = _361_t6;
	return _361_$retval;
}

struct1 _363_get_array(int64_t _363_a,int64_t _363_b) {
	struct1 _363_$retval;
BB0:
	_363_$retval = (struct1) {_363_a, _363_b, _363_a, _363_b};
	return _363_$retval;
}


int main()
{
  printf("%ld",_361_main());
  return 0;
}

#endif
