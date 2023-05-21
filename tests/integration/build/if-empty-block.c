/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684711326
#define ORNG_1684711326

#include <math.h>
#include <stdio.h>

/* Function Definitions */
int test_main();

int test_main() {
	// Bookkeeping
	int retval;
	int _0;
	int _1;
	int _2;
BB0:;
	_1 = 1;
	if (!_1) {
		goto BB3;
	} else {
		goto BB1;
	}
BB1:;
	goto BB2;
BB2:;
	_2 = 24;
	retval = _2;
	goto end;
BB3:;
	goto BB2;
end:
	return retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
