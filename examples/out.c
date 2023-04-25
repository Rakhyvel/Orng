/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1682391290
#define ORNG_1682391290

#include <math.h>
#include <stdio.h>

/* Function Definitions */
int test_main();
int test_f();

int test_main() {
	int retval;
	int (*_0)();
	int _1;
BB0:;
	_0 = test_f;
	_1 = _0();
	retval = _1;
	goto end;
end:
	return retval;
}

int test_f() {
	int retval;
	int _0;
BB0:;
	_0 = 5;
	retval = _0;
	goto end;
end:
	return retval;
}


int main()
{
  printf("Result: %d\n", test_main());
  return 0;
}

#endif
