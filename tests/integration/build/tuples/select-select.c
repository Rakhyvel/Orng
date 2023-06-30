/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687313475067567065
#define ORNG_1687313475067567065

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
} struct1;
typedef struct {
	struct1 _0;
	struct1 _1;
} struct2;

/* Function forward definitions */
int64_t _337_main();

/* Function definitions */
int64_t _337_main() {
	int64_t _337_t2;
	int64_t _337_t3;
	struct1 _337_t1;
	int64_t _337_t5;
	int64_t _337_t6;
	struct1 _337_t4;
	struct2 _338_x;
	struct1 _337_t7;
	int64_t _337_t8;
	struct1 _337_t9;
	int64_t _337_t10;
	int64_t _337_$retval;
BB0:
	_337_t2 = 1;
	_337_t3 = 2;
	_337_t1 = (struct1) {_337_t2, _337_t3};
	_337_t5 = 3;
	_337_t6 = 4;
	_337_t4 = (struct1) {_337_t5, _337_t6};
	_338_x = (struct2) {_337_t1, _337_t4};
	_337_t8 = 77;
	(&((&_338_x)->_0))->_0 = _337_t8;
	_337_t9 = *&((&_338_x)->_0);
	_337_t10 = *&((&((&_338_x)->_0))->_0);
	_337_$retval = _337_t10;
	return _337_$retval;
}


int main()
{
  printf("%ld",_337_main());
  return 0;
}

#endif
