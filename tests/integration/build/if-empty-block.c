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
	uint8_t _76_t1;
	int64_t _76_t2;
BB0: // 1
	_76_t1 = 1;
	goto BB2;
BB2: // 1
	_76_t2 = 24;
	retval = _76_t2;
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
