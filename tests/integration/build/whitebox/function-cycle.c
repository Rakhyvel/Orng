/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686018921452919797
#define ORNG_1686018921452919797

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */

/* Function forward definitions */
int64_t _2_main();
int64_t _3_a(int64_t _3_n);
int64_t _4_b(int64_t _4_n);
int64_t _5_c(int64_t _5_n);

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t0;
	int64_t _2_$retval;
BB0:
	_2_t1 = 47;
	_2_t0 = _3_a(_2_t1);
	_2_$retval = _2_t0;
	return _2_$retval;
}

int64_t _3_a(int64_t _3_n) {
	int64_t _3_t0;
	int64_t _3_$retval;
BB0:
	_3_t0 = _4_b(_3_n);
	_3_$retval = _3_t0;
	return _3_$retval;
}

int64_t _4_b(int64_t _4_n) {
	int64_t _4_t0;
	int64_t _4_$retval;
BB0:
	_4_t0 = _5_c(_4_n);
	_4_$retval = _4_t0;
	return _4_$retval;
}

int64_t _5_c(int64_t _5_n) {
	int64_t _5_t2;
	uint8_t _5_t1;
	int64_t _5_t0;
	int64_t _5_$retval;
	int64_t _5_t4;
BB0:
	_5_t2 = 47;
	_5_t1 = _5_n == _5_t2;
	if (!_5_t1) {
		goto BB9;
	} else {
		goto BB1;
	}
BB1:
	_5_t0 = 47;
	goto BB6;
BB6:
	_5_$retval = _5_t0;
	return _5_$retval;
BB9:
	_5_t4 = _3_a(_5_n);
	_5_t0 = _5_t4;
	goto BB6;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
