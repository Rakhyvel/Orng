/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1683497400
#define ORNG_1683497400

#include <math.h>
#include <stdio.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int _0;
	int _1;
	int _2;
BB0:;
	_0 = 4;
	_1 = 4;
	_2 = _0 != _1;
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
