/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686109157911928911
#define ORNG_1686109157911928911

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();
function0 _4_f();
int64_t _5_addFour(int64_t _5_x);

/* Function definitions */
int64_t _2_main() {
	function0 _2_t0;
	int64_t _2_t2;
	int64_t _2_t1;
	int64_t _2_$retval;
BB0:
	_2_t0 = _4_f();
	_2_t2 = 45;
	_2_t1 = _2_t0(_2_t2);
	_2_$retval = _2_t1;
	return _2_$retval;
}

function0 _4_f() {
	function0 _4_$retval;
BB0:
	_4_$retval = _5_addFour;
	return _4_$retval;
}

int64_t _5_addFour(int64_t _5_x) {
	int64_t _5_t0;
	int64_t _5_$retval;
BB0:
	_5_t0 = 4;
	_5_$retval = _5_x + _5_t0;
	return _5_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
