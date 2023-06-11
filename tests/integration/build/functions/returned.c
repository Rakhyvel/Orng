/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686463458
#define ORNG_1686463458

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();
typedef int64_t(*function2)(int64_t);
typedef function2(*function1)();

/* Function forward definitions */
int64_t _31_main();
function2 _33_f();
int64_t _34_addFour(int64_t x);

/* Function definitions */
int64_t _31_main() {
	function1 _31_t0;
	function2 _31_t1;
	int64_t _31_t3;
	int64_t _31_$retval;
BB0:
	_31_t0 = _33_f;
	_31_t1 = _31_t0();
	_31_t3 = 45;
	_31_$retval = _31_t1(_31_t3);
	return _31_$retval;
}

function2 _33_f() {
	function2 _33_t0;
	function2 _33_$retval;
BB0:
	_33_t0 = _34_addFour;
	_33_$retval = _33_t0;
	return _33_$retval;
}

int64_t _34_addFour(int64_t x) {
	int64_t _34_t1;
	int64_t _34_$retval;
BB0:
	_34_t1 = 4;
	_34_$retval = x + _34_t1;
	return _34_$retval;
}


int main()
{
  printf("%ld",_31_main());
  return 0;
}

#endif
