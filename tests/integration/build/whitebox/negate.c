/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686626622
#define ORNG_1686626622

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef int64_t(*function0)();

/* Function forward definitions */
int64_t _47_main();

/* Function definitions */
int64_t _47_main() {
	int64_t _47_t1;
	int64_t* _47_t5;
	int64_t _47_t6;
	int64_t _47_t7;
	int64_t _47_t9;
	uint8_t _47_t4;
	int64_t _47_t3;
	int64_t _47_$retval;
BB0:
	_47_t1 = 1;
	_47_t5 = &_47_t1;
	_47_t6 = *_47_t5;
	_47_t7 = -_47_t6;
	_47_t9 = -1;
	_47_t4 = _47_t7 == _47_t9;
	if (!_47_t4) {
		goto BB9;
	} else {
		goto BB1;
	}
BB1:
	_47_t3 = 32;
	goto BB6;
BB6:
	_47_$retval = _47_t3;
	return _47_$retval;
BB9:
	_47_t3 = 10;
	goto BB6;
}


int main()
{
  printf("%ld",_47_main());
  return 0;
}

#endif
