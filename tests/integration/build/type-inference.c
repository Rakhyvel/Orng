/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685229659
#define ORNG_1685229659

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _2_t0;
	int64_t _2_t1;
	int64_t _2_t2;
	int64_t _2_$retval;
BB0: // 1
// Versions: 1
	_2_t0 = 20;
// Versions: 1
	_2_t1 = 7;
// Versions: 1
	_2_t2 = _2_t0 + _2_t1;
// Versions: 1
	_2_$retval = _2_t2;
	goto end;
end:
	return _2_$retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
