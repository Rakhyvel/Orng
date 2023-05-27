/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685225690
#define ORNG_1685225690

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _57_x;
	int64_t _56_t1;
	int64_t _56_t2;
	int64_t _56_t3;
	int64_t _56_$retval;
BB0: // 1
	_57_x = 4;
	_56_t1 = 4;
	_56_t2 = 6;
	_56_t3 = _56_t1 + _56_t2;
	_57_x = _56_t3;
	_56_$retval = _56_t3;
	goto end;
end:
	return _56_$retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
