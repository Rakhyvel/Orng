/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686884233
#define ORNG_1686884233

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
int64_t _315_main();

/* Function definitions */
int64_t _315_main() {
	int64_t _315_t1;
	int64_t _315_t2;
	struct3 _316_x;
	int64_t _315_t3;
	int64_t _315_t4;
	int64_t _315_$retval;
BB0:
	_315_t1 = 50;
	_315_t2 = 7;
	_316_x = (struct3) {_315_t1, _315_t2};
	_315_t3 = _316_x._0;
	_315_t4 = _316_x._1;
	_315_$retval = _315_t3 + _315_t4;
	return _315_$retval;
}


int main()
{
  printf("%ld",_315_main());
  return 0;
}

#endif
