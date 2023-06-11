/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686513839
#define ORNG_1686513839

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();
typedef int64_t(*function1)(int64_t);

/* Function forward definitions */
int64_t _211_main();
int64_t _212_sumDown(int64_t x);

/* Function definitions */
int64_t _211_main() {
	function1 _211_t0;
	int64_t _211_t2;
	int64_t _211_t1;
	int64_t _211_t3;
	int64_t _211_$retval;
BB0:
	_211_t0 = _212_sumDown;
	_211_t2 = 8;
	_211_t1 = _211_t0(_211_t2);
	_211_t3 = 2;
	_211_$retval = _211_t1 + _211_t3;
	return _211_$retval;
}

int64_t _212_sumDown(int64_t x) {
	int64_t _214_i;
	int64_t _212_t4;
	uint8_t _212_t2;
	int64_t _212_t9;
	int64_t _212_$retval;
BB0:
	_214_i = x;
	goto BB1;
BB1:
	_212_t4 = 0;
	_212_t2 = _214_i >= _212_t4;
	if (!_212_t2) {
		goto BB10;
	} else {
		goto BB2;
	}
BB2:
	x = x + _214_i;
	_212_t9 = 1;
	_214_i = _214_i - _212_t9;
	goto BB1;
BB10:
	_212_$retval = x;
	return _212_$retval;
}


int main()
{
  printf("%ld",_211_main());
  return 0;
}

#endif
