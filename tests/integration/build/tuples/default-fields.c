/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687313477
#define ORNG_1687313477

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _34_main();

/* Function definitions */
int64_t _34_main() {
	int64_t _34_t1;
	int64_t _34_t2;
	struct1 _35_x;
	int64_t _34_t3;
	int64_t _34_t4;
	int64_t _34_$retval;
BB0:
	_34_t1 = 50;
	_34_t2 = 7;
	_35_x = (struct1) {_34_t1, _34_t2};
	_34_t3 = *&((&_35_x)->_0);
	_34_t4 = *&((&_35_x)->_1);
	_34_$retval = _34_t3 + _34_t4;
	return _34_$retval;
}


int main()
{
  printf("%ld",_34_main());
  return 0;
}

#endif
