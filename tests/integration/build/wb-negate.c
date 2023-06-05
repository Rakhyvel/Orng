/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685926483
#define ORNG_1685926483

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _56_main();

int64_t _56_main() {
	int64_t _56_t1;
	int64_t* _56_t5;
	int64_t _56_t6;
	int64_t _56_t7;
	int64_t _56_t9;
	uint8_t _56_t4;
	int64_t _56_t3;
	int64_t _56_$retval;
BB0:
	_56_t1 = 1;
	_56_t5 = &_56_t1;
	_56_t6 = *_56_t5;
	_56_t7 = -_56_t6;
	_56_t9 = -1;
	_56_t4 = _56_t7 == _56_t9;
	if (!_56_t4) {
		goto BB9;
	} else {
		goto BB1;
	}
BB1:
	_56_t3 = 32;
	goto BB6;
BB6:
	_56_$retval = _56_t3;
	return _56_$retval;
BB9:
	_56_t3 = 10;
	goto BB6;
}


int main()
{
  printf("%ld",_56_main());
  return 0;
}

#endif
