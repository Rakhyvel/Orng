/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686104538
#define ORNG_1686104538

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _63_main();

int64_t _63_main() {
	int64_t _63_t1;
	int64_t* _63_t5;
	int64_t _63_t6;
	int64_t _63_t7;
	int64_t _63_t9;
	uint8_t _63_t4;
	int64_t _63_t3;
	int64_t _63_$retval;
BB0:
	_63_t1 = 1;
	_63_t5 = &_63_t1;
	_63_t6 = *_63_t5;
	_63_t7 = -_63_t6;
	_63_t9 = -1;
	_63_t4 = _63_t7 == _63_t9;
	if (!_63_t4) {
		goto BB9;
	} else {
		goto BB1;
	}
BB1:
	_63_t3 = 32;
	goto BB6;
BB6:
	_63_$retval = _63_t3;
	return _63_$retval;
BB9:
	_63_t3 = 10;
	goto BB6;
}


int main()
{
  printf("%ld",_63_main());
  return 0;
}

#endif
