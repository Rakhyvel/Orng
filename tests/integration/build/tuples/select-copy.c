/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686794864
#define ORNG_1686794864

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
int64_t _307_main();

/* Function definitions */
int64_t _307_main() {
	int64_t _307_t1;
	int64_t _307_t2;
	struct3 _308_x;
	int64_t _307_t3;
	int64_t _307_t4;
	int64_t _307_t5;
	int64_t _307_$retval;
BB0:
	_307_t1 = 50;
	_307_t2 = 5;
	_308_x = (struct3) {_307_t1, _307_t2};
	_307_t3 = 6;
	_308_x._1 = _307_t3;
	_307_t4 = _308_x._0;
	_307_t5 = _308_x._1;
	_307_$retval = _307_t4 + _307_t5;
	return _307_$retval;
}


int main()
{
  printf("%ld",_307_main());
  return 0;
}

#endif
