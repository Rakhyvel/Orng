/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687129465
#define ORNG_1687129465

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _296_main();

/* Function definitions */
int64_t _296_main() {
	int64_t _297_x;
	int64_t* _297_y;
	int64_t _296_t2;
	int64_t _296_$retval;
BB0:
	_297_x = 4;
	_297_y = &_297_x;
	_296_t2 = 28;
	*&_297_x = _296_t2;
	_296_$retval = *_297_y;
	return _296_$retval;
}


int main()
{
  printf("%ld",_296_main());
  return 0;
}

#endif
