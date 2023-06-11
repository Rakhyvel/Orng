/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686513839
#define ORNG_1686513839

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();
typedef int64_t(*function2)(int64_t);
typedef function2(*function1)();

/* Function forward definitions */
int64_t _226_main();
function2 _228_f();
int64_t _229_addFour(int64_t x);

/* Function definitions */
int64_t _226_main() {
	function1 _226_t0;
	function2 _226_t1;
	int64_t _226_t3;
	int64_t _226_$retval;
BB0:
	_226_t0 = _228_f;
	_226_t1 = _226_t0();
	_226_t3 = 45;
	_226_$retval = _226_t1(_226_t3);
	return _226_$retval;
}

function2 _228_f() {
	function2 _228_t0;
	function2 _228_$retval;
BB0:
	_228_t0 = _229_addFour;
	_228_$retval = _228_t0;
	return _228_$retval;
}

int64_t _229_addFour(int64_t x) {
	int64_t _229_t1;
	int64_t _229_$retval;
BB0:
	_229_t1 = 4;
	_229_$retval = x + _229_t1;
	return _229_$retval;
}


int main()
{
  printf("%ld",_226_main());
  return 0;
}

#endif
