/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1689305971721079895
#define ORNG_1689305971721079895

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	uint64_t tag;
	union {
		int64_t _1;
	};
} struct0;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();
struct0 _4_f(uint8_t _4_fail);
struct0 _9_g();

/* Function definitions */
int64_t _2_main() {
	uint8_t _2_t2;
	struct0 _2_t1;
	uint8_t _2_t3;
	int64_t _2_t0;
	uint8_t _2_t8;
	struct0 _2_t7;
	uint8_t _2_t9;
	int64_t _2_t6;
	int64_t _2_$retval;
BB0:
	_2_t2 = 1;
	_2_t1 = _4_f(_2_t2);
	_2_t3 = _2_t1.tag;
	if (!_2_t3) {
		goto BB7;
	} else {
		goto BB1;
	}
BB1:
	_2_t0 = (&_2_t1)->_1;
	goto BB2;
BB2:
	_2_t8 = 0;
	_2_t7 = _4_f(_2_t8);
	_2_t9 = _2_t7.tag;
	if (!_2_t9) {
		goto BB6;
	} else {
		goto BB3;
	}
BB3:
	_2_t6 = (&_2_t7)->_1;
	goto BB4;
BB4:
	_2_$retval = _2_t0 + _2_t6;
	return _2_$retval;
BB6:
	_2_t6 = 122;
	goto BB4;
BB7:
	_2_t0 = 122;
	goto BB2;
}

struct0 _4_f(uint8_t _4_fail) {
	struct0 _4_t1;
	uint8_t _4_t2;
	int64_t _7_x;
	struct0 _4_t0;
	struct0 _4_$retval;
	int64_t _4_t6;
BB0:
	if (!_4_fail) {
		goto BB8;
	} else {
		goto BB1;
	}
BB1:
	_4_t1 = _9_g();
	_4_t2 = _4_t1.tag;
	if (!_4_t2) {
		goto BB7;
	} else {
		goto BB2;
	}
BB2:
	_7_x = (&_4_t1)->_1;
	_4_t0 = (struct0) {.tag=1, ._1=_7_x};
	goto BB7;
BB7:
	_4_$retval = _4_t0;
	return _4_$retval;
BB8:
	_4_t6 = 0;
	_4_t0 = (struct0) {.tag=1, ._1=_4_t6};
	goto BB7;
}

struct0 _9_g() {
	struct0 _9_$retval;
BB0:
	_9_$retval = (struct0) {.tag=0};
	return _9_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
