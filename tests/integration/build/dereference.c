/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684898822
#define ORNG_1684898822

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int64_t _9_t0;
	int64_t _10_x;
	int64_t* _9_t1;
	int64_t* _10_y;
	int64_t* _9_t2;
	int64_t _9_t3;
	int64_t _9_t4;
	int64_t _0;
BB0: // 1
	_9_t0 = 29;
	_10_x = _9_t0;
	_9_t1 = &_10_x;
	_10_y = _9_t1;
	_9_t2 = &_10_x;
	_9_t3 = *_10_y;
	_9_t4 = *_10_y;
	retval = _9_t4;
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
