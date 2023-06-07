/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686104538
#define ORNG_1686104538

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _269_main();

int64_t _269_main() {
	int64_t _270_x;
	int64_t _269_t4;
	uint8_t _269_t2;
	int64_t _269_t8;
	uint8_t _269_t6;
	int64_t _269_t10;
	int64_t _269_$retval;
	int64_t _269_t13;
BB0:
	_270_x = 0;
	goto BB1;
BB1:
	_269_t4 = 100;
	_269_t2 = _270_x < _269_t4;
	if (!_269_t2) {
		goto BB8;
	} else {
		goto BB2;
	}
BB2:
	_269_t8 = 40;
	_269_t6 = _270_x == _269_t8;
	if (!_269_t6) {
		goto BB14;
	} else {
		goto BB5;
	}
BB5:
	_269_t10 = 1;
	_270_x = _270_x + _269_t10;
	goto BB8;
BB8:
	_269_$retval = _270_x;
	return _269_$retval;
BB14:
	_269_t13 = 1;
	_270_x = _270_x + _269_t13;
	goto BB1;
}


int main()
{
  printf("%ld",_269_main());
  return 0;
}

#endif
