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
	goto BB1;
BB1:;
	_1 = 0;
	if (!_1) {
		goto BB3;
	} else {
		goto BB2;
	}
BB2:;
	goto BB1;
BB3:;
	goto BB4;
BB4:;
	_2 = 25;
	retval = _2;
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
