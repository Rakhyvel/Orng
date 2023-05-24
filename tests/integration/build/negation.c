/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684895194
#define ORNG_1684895194

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int64_t _133_t0;
	int64_t _133_t1;
BB0: // 1
	_133_t0 = 10;
	_133_t1 = -_133_t0;
	retval = _133_t1;
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
