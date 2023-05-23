/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684812568
#define ORNG_1684812568

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	uint8_t _1;
	int64_t _4;
	uint8_t _2;
	uint8_t _3;
BB0:;
	goto BB1;
BB1:;
	_1 = 0;
	if (!_1) {
		goto BB5;
	} else {
		goto BB4;
	}
BB4:;
	_4 = 25;
	retval = _4;
	goto end;
BB5:;
	_2 = 0;
	if (!_2) {
		goto BB8;
	} else {
		goto BB4;
	}
BB8:;
	_3 = 1;
	goto BB4;
end:
	return retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
