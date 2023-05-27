/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685229662
#define ORNG_1685229662

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _112_t3;
	int64_t _112_t4;
	int64_t _112_t5;
	int64_t _112_$retval;
BB0: // 1
// Versions: 1
	_112_t3 = 4;
// Versions: 1
	_112_t4 = 7;
// Versions: 1
	_112_t5 = _112_t3 + _112_t4;
// Versions: 1
	_112_$retval = _112_t5;
	goto end;
end:
	return _112_$retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
