/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686278317
#define ORNG_1686278317

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();
typedef int64_t(*function2)(int64_t);
typedef function2(*function1)();

/* Function forward definitions */
int64_t _222_main();
function2 _224_f();
int64_t _225_addFour(int64_t x);

/* Function definitions */
int64_t _222_main() {
	function1 _222_t0;
	function2 _222_t1;
	int64_t _222_t3;
	int64_t _222_$retval;
BB0:
	_222_t0 = _224_f;
	_222_t1 = _222_t0();
	_222_t3 = 45;
	_222_$retval = _222_t1(_222_t3);
	return _222_$retval;
}

function2 _224_f() {
	function2 _224_t0;
	function2 _224_$retval;
BB0:
	_224_t0 = _225_addFour;
	_224_$retval = _224_t0;
	return _224_$retval;
}

int64_t _225_addFour(int64_t x) {
	int64_t _225_t1;
	int64_t _225_$retval;
BB0:
	_225_t1 = 4;
	_225_$retval = x + _225_t1;
	return _225_$retval;
}


int main()
{
  printf("%ld",_222_main());
  return 0;
}

#endif
