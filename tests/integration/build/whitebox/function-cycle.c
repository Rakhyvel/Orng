/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686537897
#define ORNG_1686537897

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();
typedef int64_t(*function1)(int64_t);

/* Function forward definitions */
int64_t _37_main();
int64_t _38_a(int64_t n);
int64_t _39_b(int64_t n);
int64_t _40_c(int64_t n);

/* Function definitions */
int64_t _37_main() {
	function1 _37_t0;
	int64_t _37_t2;
	int64_t _37_$retval;
BB0:
	_37_t0 = _38_a;
	_37_t2 = 47;
	_37_$retval = _37_t0(_37_t2);
	return _37_$retval;
}

int64_t _38_a(int64_t n) {
	function1 _38_t0;
	int64_t _38_$retval;
BB0:
	_38_t0 = _39_b;
	_38_$retval = _38_t0(n);
	return _38_$retval;
}

int64_t _39_b(int64_t n) {
	function1 _39_t0;
	int64_t _39_$retval;
BB0:
	_39_t0 = _40_c;
	_39_$retval = _39_t0(n);
	return _39_$retval;
}

int64_t _40_c(int64_t n) {
	int64_t _40_t3;
	uint8_t _40_t1;
	int64_t _40_t0;
	int64_t _40_$retval;
	function1 _40_t5;
BB0:
	_40_t3 = 47;
	_40_t1 = n == _40_t3;
	if (!_40_t1) {
		goto BB9;
	} else {
		goto BB1;
	}
BB1:
	_40_t0 = 47;
	goto BB6;
BB6:
	_40_$retval = _40_t0;
	return _40_$retval;
BB9:
	_40_t5 = _38_a;
	_40_t0 = _40_t5(n);
	goto BB6;
}


int main()
{
  printf("%ld",_37_main());
  return 0;
}

#endif
