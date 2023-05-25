/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684986347
#define ORNG_1684986347

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int64_t _121_t0;
	int64_t _121_t1;
	int64_t _121_t2;
	int64_t _121_t3;
	int64_t _121_t4;
	int64_t _121_t5;
	int64_t _0;
BB0: // 1
	_121_t0 = 3;
	_121_t1 = 2;
	_121_t2 = powf(_121_t1, _121_t0);
	_121_t3 = 2;
	_121_t4 = powf(_121_t3, _121_t2);
	_121_t5 = -_121_t4;
	retval = _121_t5;
	goto end;
end:
	return retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
