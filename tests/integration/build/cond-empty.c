/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685163890
#define ORNG_1685163890

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	uint8_t _124_t1;
	uint8_t _124_t2;
	uint8_t _124_t3;
	int64_t _124_t4;
	int64_t _124_$retval;
BB1: // 1
	_124_t1 = 0;
	_124_t2 = 0;
	_124_t3 = 1;
	_124_t4 = 25;
	_124_$retval = 25;
	goto end;
end:
	return _124_$retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
