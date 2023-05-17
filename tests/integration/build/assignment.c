/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684291386
#define ORNG_1684291386

#include <math.h>
#include <stdio.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int _0;
	int tests_integration_assignment_x_0;
	int _1;
	int _2;
	int tests_integration_assignment_x_1;
BB0:;
	_0 = 4;
	tests_integration_assignment_x_0 = _0;
	_1 = 6;
	_2 = tests_integration_assignment_x_0 + _1;
	tests_integration_assignment_x_1 = _2;
	retval = tests_integration_assignment_x_1;
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
