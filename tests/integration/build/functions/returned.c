/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687131173
#define ORNG_1687131173

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _238_main();
function0 _240_f();
int64_t _241_addFour(int64_t _241_x);

/* Function definitions */
int64_t _238_main() {
	function0 _238_t0;
	int64_t _238_t2;
	int64_t _238_t1;
	int64_t _238_$retval;
BB0:
	_238_t0 = _240_f();
	_238_t2 = 45;
	_238_t1 = _238_t0(_238_t2);
	_238_$retval = _238_t1;
	return _238_$retval;
}

function0 _240_f() {
	function0 _240_$retval;
BB0:
	_240_$retval = _241_addFour;
	return _240_$retval;
}

int64_t _241_addFour(int64_t _241_x) {
	int64_t _241_t0;
	int64_t _241_$retval;
BB0:
	_241_t0 = 4;
	_241_$retval = _241_x + _241_t0;
	return _241_$retval;
}


int main()
{
  printf("%ld",_238_main());
  return 0;
}

#endif
