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
} struct1;

/* Function forward definitions */
int64_t _349_main();

/* Function definitions */
int64_t _349_main() {
	int64_t _349_t1;
	int64_t _349_t2;
	struct1 _350_x;
	int64_t _349_t3;
	int64_t _349_t4;
	int64_t _349_t5;
	int64_t _349_$retval;
BB0:
	_349_t1 = 50;
	_349_t2 = 5;
	_350_x = (struct1) {_349_t1, _349_t2};
	_349_t3 = 6;
	(&_350_x)->_1 = _349_t3;
	_349_t4 = *&((&_350_x)->_0);
	_349_t5 = *&((&_350_x)->_1);
	_349_$retval = _349_t4 + _349_t5;
	return _349_$retval;
}


int main()
{
  printf("%ld",_349_main());
  return 0;
}

#endif
