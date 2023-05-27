/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685225690
#define ORNG_1685225690

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	uint8_t _16_t1;
	double _16_t4;
	uint8_t _16_$retval;
BB0: // 1
	_16_t1 = 1;
	_16_t4 = 3.0e+00;
	_16_t1 = 0;
	_16_t1 = 0;
	_16_$retval = _16_t1;
	goto end;
end:
	return _16_$retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
