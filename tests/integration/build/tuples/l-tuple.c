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
	int64_t _2;
	int64_t _3;
} struct1;

/* Function forward definitions */
int64_t _26_main();

/* Function definitions */
int64_t _26_main() {
	int64_t _26_t1;
	int64_t _26_t2;
	int64_t _26_t3;
	int64_t _26_t4;
	struct1 _27_x;
	int64_t _26_t5;
	int64_t* _26_t6;
	int64_t _26_t7;
	int64_t _26_t8;
	int64_t _26_$retval;
BB0:
	_26_t1 = 1;
	_26_t2 = 2;
	_26_t3 = 3;
	_26_t4 = 4;
	_27_x = (struct1) {_26_t1, _26_t2, _26_t3, _26_t4};
	_26_t6 = &((&_27_x)->_3);
	_26_t7 = 66;
	**&_26_t6 = _26_t7;
	_26_t8 = *&((&_27_x)->_3);
	_26_$retval = _26_t8;
	return _26_$retval;
}


int main()
{
  printf("%ld",_26_main());
  return 0;
}

#endif
