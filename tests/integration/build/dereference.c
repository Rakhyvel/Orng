/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685225690
#define ORNG_1685225690

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _9_t1;
	int64_t* _9_t2;
	int64_t* _9_t7;
	int64_t _9_t8;
	int64_t _9_$retval;
BB0: // 1
	_9_t1 = 29;
	_9_t2 = &_9_t1;
	_9_t7 = _9_t2;
	_9_t8 = *_9_t7;
	_9_$retval = _9_t8;
	goto end;
end:
	return _9_$retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
