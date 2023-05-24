/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684895194
#define ORNG_1684895194

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	uint8_t _94_t0;
	uint8_t _95_found;
	int64_t _94_t2;
	int64_t _96_n;
	uint8_t _94_t3;
	int64_t _94_t4;
	uint8_t _94_t5;
	int64_t _94_t7;
	uint8_t _94_t9;
	int64_t _94_t10;
	uint8_t _94_t11;
	uint8_t _94_t12;
	int64_t _94_t13;
	int64_t _94_t14;
	int64_t _94_t15;
	int64_t _94_t16;
	int64_t _94_t17;
BB0: // 1
	_94_t0 = 0;
	_95_found = _94_t0;
	_94_t2 = 0;
	_96_n = _94_t2;
	goto BB1;
BB1: // 2
	_94_t4 = 10;
	_94_t5 = _96_n < _94_t4;
	if (!_94_t5) {
		goto BB19;
	} else {
		goto BB2;
	}
BB2: // 1
	_94_t3 = 1;
	goto BB3;
BB3: // 2
	if (!_94_t3) {
		goto BB15;
	} else {
		goto BB4;
	}
BB4: // 1
	if (!_95_found) {
		goto BB6;
	} else {
		goto BB5;
	}
BB5: // 1
	_94_t7 = 10;
	_96_n = _94_t7;
_96_n;
	goto BB6;
BB6: // 2
	_94_t10 = 6;
	_94_t11 = _96_n == _94_t10;
	if (!_94_t11) {
		goto BB12;
	} else {
		goto BB7;
	}
BB7: // 1
	_94_t9 = 1;
	goto BB8;
BB8: // 2
	if (!_94_t9) {
		goto BB10;
	} else {
		goto BB9;
	}
BB9: // 1
	_94_t12 = 1;
	_95_found = _94_t12;
_95_found;
	goto BB10;
BB10: // 2
;
	_94_t13 = 1;
	_94_t14 = _96_n + _94_t13;
	_96_n = _94_t14;
	goto BB1;
BB12: // 1
	_94_t9 = 0;
	goto BB8;
BB15: // 1
	if (!_95_found) {
		goto BB18;
	} else {
		goto BB16;
	}
BB16: // 1
	_94_t16 = 15;
	_94_t15 = _94_t16;
	goto BB17;
BB17: // 2
	retval = _94_t15;
	goto end;
BB18: // 1
	_94_t17 = 4;
	_94_t15 = _94_t17;
	goto BB17;
BB19: // 1
	_94_t3 = 0;
	goto BB3;
end:
	return retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
