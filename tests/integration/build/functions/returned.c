/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687128100
#define ORNG_1687128100

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _39_main();
function0 _41_f();
int64_t _42_addFour(int64_t x);

/* Function definitions */
int64_t _39_main() {
	function0 _39_t0;
	int64_t _39_t2;
	int64_t _39_t1;
	int64_t _39_$retval;
BB0:
	_39_t0 = _41_f();
	_39_t2 = 45;
	_39_t1 = _39_t0(_39_t2);
	_39_$retval = _39_t1;
	return _39_$retval;
}

function0 _41_f() {
	function0 _41_$retval;
BB0:
	_41_$retval = _42_addFour;
	return _41_$retval;
}

int64_t _42_addFour(int64_t x) {
	int64_t _42_t0;
	int64_t _42_$retval;
BB0:
	_42_t0 = 4;
	_42_$retval = x + _42_t0;
	return _42_$retval;
}


int main()
{
  printf("%ld",_39_main());
  return 0;
}

#endif
