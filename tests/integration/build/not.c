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
BB0:;
	_0 = 1;
	_1 = !_0;
	retval = _1;
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
