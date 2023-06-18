/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687128490
#define ORNG_1687128490

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
int64_t _18_main();

/* Function definitions */
int64_t _18_main() {
	int64_t _18_t1;
	int64_t _18_t2;
	int64_t _18_t3;
	int64_t _18_t4;
	struct1 _19_x;
	int64_t _18_t5;
	int64_t* _19_y;
	int64_t _18_t7;
	int64_t _18_t8;
	int64_t _18_$retval;
BB0:
	_18_t1 = 1;
	_18_t2 = 2;
	_18_t3 = 3;
	_18_t4 = 4;
	_19_x = (struct1) {_18_t1, _18_t2, _18_t3, _18_t4};
	_19_y = (&_19_x._3);
	_18_t7 = 66;
	*(&_19_x._3) = _18_t7;
	_18_t8 = _19_x._3;
	_18_$retval = _18_t8;
	return _18_$retval;
}


int main()
{
  printf("%ld",_18_main());
  return 0;
}

#endif
