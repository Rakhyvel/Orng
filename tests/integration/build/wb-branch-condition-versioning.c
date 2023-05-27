/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685163890
#define ORNG_1685163890

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	uint8_t _94_t0;
	uint8_t _95_found;
	int64_t _94_t2;
	int64_t _96_n;
	int64_t _94_t4;
	int64_t _94_t5;
	uint8_t _94_t3;
	uint8_t _94_t7;
	int64_t _94_t8;
	int64_t _94_t11;
	int64_t _94_t12;
	uint8_t _94_t10;
	uint8_t _94_t13;
	int64_t _94_t14;
	int64_t _94_t15;
	int64_t _94_t16;
	uint8_t _94_t18;
	int64_t _94_t19;
	int64_t _94_t17;
	int64_t _94_$retval;
	int64_t _94_t20;
BB0: // 1
	_94_t0 = 0;
	_95_found = 0;
	_94_t2 = 0;
	_96_n = 0;
	goto BB1;
BB1: // 2
	_94_t4 = _96_n;
	_94_t5 = 10;
	_94_t3 = _94_t4 < _94_t5;
	if (!_94_t3) {
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
	_94_t7 = _95_found;
	if (!_94_t7) {
		goto BB6;
	} else {
		goto BB5;
	}
BB5: // 1
	_94_t8 = 100;
	_96_n = 100;
	goto BB6;
BB6: // 2
	_94_t11 = _96_n;
	_94_t12 = 6;
	_94_t10 = _94_t11 == _94_t12;
	if (!_94_t10) {
		goto BB12;
	} else {
		goto BB7;
	}
BB7: // 1
	_94_t10 = 1;
	goto BB8;
BB8: // 2
	if (!_94_t10) {
		goto BB10;
	} else {
		goto BB9;
	}
BB9: // 1
	_94_t13 = 1;
	_95_found = 1;
	goto BB10;
BB10: // 2
	_94_t14 = _96_n;
	_94_t15 = 1;
	_94_t16 = _94_t14 + _94_t15;
	_96_n = _94_t16;
	goto BB1;
BB12: // 1
	_94_t10 = 0;
	goto BB8;
BB15: // 1
	_94_t18 = _95_found;
	if (!_94_t18) {
		goto BB18;
	} else {
		goto BB16;
	}
BB16: // 1
	_94_t19 = 15;
	_94_t17 = 15;
	goto BB17;
BB17: // 2
	_94_$retval = _94_t17;
	goto end;
BB18: // 1
	_94_t20 = 4;
	_94_t17 = 4;
	goto BB17;
BB19: // 1
	_94_t3 = 0;
	goto BB3;
end:
	return _94_$retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
