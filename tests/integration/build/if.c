/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685163890
#define ORNG_1685163890

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _112_t1;
	int64_t _113_x;
	uint8_t _112_t2;
	int64_t _112_t3;
	int64_t _112_t4;
	int64_t _112_t5;
	int64_t _112_t0;
	int64_t _112_$retval;
BB0: // 1
	_112_t1 = 4;
	_113_x = 4;
	_112_t2 = 1;
	_112_t3 = _113_x;
	_112_t4 = 7;
	_112_t5 = _112_t3 + _112_t4;
	_112_t0 = _112_t5;
	_112_$retval = _112_t0;
	goto end;
end:
	return _112_$retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
