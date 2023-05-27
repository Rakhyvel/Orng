/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685229661
#define ORNG_1685229661

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _83_t1;
	int64_t _83_t2;
	int64_t _83_t3;
	int64_t _83_$retval;
BB0: // 1
// Versions: 1
	_83_t1 = 13;
// Versions: 1
	_83_t2 = 2;
// Versions: 1
	_83_t3 = _83_t1 * _83_t2;
// Versions: 1
	_83_$retval = _83_t3;
	goto end;
end:
	return _83_$retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
