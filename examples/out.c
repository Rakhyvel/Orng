/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1682391946
#define ORNG_1682391946

#include <math.h>
#include <stdio.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int _0;
	int test_x_0;
	int _1;
	int test_y_0;
BB0:;
	_0 = 4;
	test_x_0 = _0;
	_1 = &test_x_0;
	test_y_0 = _1;
	retval = test_y_0;
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
