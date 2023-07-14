/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688935589672149152
#define ORNG_1688935589672149152

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	uint8_t* _0;
	int64_t _1;
} struct1;
typedef struct {
	uint64_t tag;
	union {
		struct1 _0;
		int64_t _1;
	};
} struct0;

/* Interned Strings */
char* string_0 = "\x66\x69\x7A\x7A\x62\x75\x7A\x7A";
char* string_1 = "\x62\x75\x7A\x7A";
char* string_2 = "\x66\x69\x7A\x7A";

/* Function forward definitions */
struct1 _2_main();
struct0 _4_fizzbuzz(int64_t _4_n);

/* Function definitions */
struct1 _2_main() {
	int64_t _2_t1;
	struct0 _2_t0;
	struct1 _2_$retval;
BB0:
	_2_t1 = 30;
	_2_t0 = _4_fizzbuzz(_2_t1);
	_2_$retval = (&_2_t0)->_0;
	return _2_$retval;
}

struct0 _4_fizzbuzz(int64_t _4_n) {
	int64_t _4_t2;
	int64_t _4_t3;
	int64_t _4_t4;
	uint8_t _4_t1;
	struct1 _4_t13;
	struct0 _4_t0;
	struct0 _4_$retval;
	struct1 _4_t15;
	struct1 _4_t17;
	int64_t _4_t10;
	int64_t _4_t11;
	int64_t _4_t12;
	uint8_t _4_t9;
	int64_t _4_t6;
	int64_t _4_t7;
	int64_t _4_t8;
	uint8_t _4_t5;
BB1:
	_4_t2 = 15;
	_4_t3 = _4_n % _4_t2;
	_4_t4 = 0;
	_4_t1 = _4_t3 == _4_t4;
	if (_4_t1) {
		goto BB2;
	} else {
		goto BB22;
	}
BB22:
	_4_t6 = 5;
	_4_t7 = _4_n % _4_t6;
	_4_t8 = 0;
	_4_t5 = _4_t7 == _4_t8;
	if (_4_t5) {
		goto BB9;
	} else {
		goto BB21;
	}
BB21:
	_4_t10 = 3;
	_4_t11 = _4_n % _4_t10;
	_4_t12 = 0;
	_4_t9 = _4_t11 == _4_t12;
	if (_4_t9) {
		goto BB14;
	} else {
		goto BB20;
	}
BB20:
	_4_t0 = (struct0) {.tag=1, ._1=_4_n};
	goto BB7;
BB7:
	_4_$retval = _4_t0;
	return _4_$retval;
BB14:
	_4_t17 = (struct1) {string_2, 5};
	_4_t0 = (struct0) {.tag=0, ._0=_4_t17};
	goto BB7;
BB9:
	_4_t15 = (struct1) {string_1, 5};
	_4_t0 = (struct0) {.tag=0, ._0=_4_t15};
	goto BB7;
BB2:
	_4_t13 = (struct1) {string_0, 9};
	_4_t0 = (struct0) {.tag=0, ._0=_4_t13};
	goto BB7;
}


int main()
{
  printf("%s",_2_main()._0);
  return 0;
}

#endif
