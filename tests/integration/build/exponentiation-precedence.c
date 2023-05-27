/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685225690
#define ORNG_1685225690

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _121_t0;
	int64_t _121_t1;
	int64_t _121_t2;
	int64_t _121_t3;
	int64_t _121_t4;
	int64_t _121_t5;
	int64_t _121_$retval;
BB0: // 1
	_121_t0 = 3;
	_121_t1 = 2;
	_121_t2 = powf(_121_t1, _121_t0);
	_121_t3 = 2;
	_121_t4 = powf(_121_t3, _121_t2);
	_121_t5 = -_121_t4;
	_121_$retval = _121_t5;
	goto end;
end:
	return _121_$retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
