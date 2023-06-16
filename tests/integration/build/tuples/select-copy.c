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
int64_t _311_main();

/* Function definitions */
int64_t _311_main() {
	int64_t _311_t1;
	int64_t _311_t2;
	struct3 _312_x;
	int64_t _311_t3;
	int64_t _311_t4;
	int64_t _311_t5;
	int64_t _311_$retval;
BB0:
	_311_t1 = 50;
	_311_t2 = 5;
	_312_x = (struct3) {_311_t1, _311_t2};
	_311_t3 = 6;
	_312_x._1 = _311_t3;
	_311_t4 = _312_x._0;
	_311_t5 = _312_x._1;
	_311_$retval = _311_t4 + _311_t5;
	return _311_$retval;
}


int main()
{
  printf("%ld",_311_main());
  return 0;
}

#endif
