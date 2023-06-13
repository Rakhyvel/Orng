/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686626563
#define ORNG_1686626563

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();
typedef struct {
	int64_t _0;
	int64_t _1;
} struct3;

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t2;
	struct3 _2_t0;
	struct3 _3_x;
	struct3 _2_t3;
	int64_t _2_t4;
	struct3 _2_t5;
	int64_t _2_t6;
	int64_t _2_$retval;
BB0:
	_2_t1 = 50;
	_2_t2 = 5;
	_2_t0 = (struct3) {_2_t1, _2_t2};
	_3_x = _2_t0;
	_2_t3 = _3_x;
	_2_t4 = _2_t3._0;
	_2_t5 = _3_x;
	_2_t6 = _2_t5._1;
	_2_$retval = _2_t4 + _2_t6;
	return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
