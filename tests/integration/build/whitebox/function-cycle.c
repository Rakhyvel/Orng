/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687127760
#define ORNG_1687127760

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _37_main();
int64_t _38_a(int64_t n);
int64_t _39_b(int64_t n);
int64_t _40_c(int64_t n);

/* Function definitions */
int64_t _37_main() {
	int64_t _37_t1;
	int64_t _37_t0;
	int64_t _37_$retval;
BB0:
	_37_t1 = 47;
	_37_t0 = _38_a(_37_t1);
	_37_$retval = _37_t0;
	return _37_$retval;
}

int64_t _38_a(int64_t n) {
	int64_t _38_t0;
	int64_t _38_$retval;
BB0:
	_38_t0 = _39_b(n);
	_38_$retval = _38_t0;
	return _38_$retval;
}

int64_t _39_b(int64_t n) {
	int64_t _39_t0;
	int64_t _39_$retval;
BB0:
	_39_t0 = _40_c(n);
	_39_$retval = _39_t0;
	return _39_$retval;
}

int64_t _40_c(int64_t n) {
	int64_t _40_t2;
	uint8_t _40_t1;
	int64_t _40_t0;
	int64_t _40_$retval;
	int64_t _40_t4;
BB0:
	_40_t2 = 47;
	_40_t1 = n == _40_t2;
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
	_40_t4 = _38_a(n);
	_40_t0 = _40_t4;
	goto BB6;
}


int main()
{
  printf("%ld",_37_main());
  return 0;
}

#endif
