/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684812568
#define ORNG_1684812568

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int64_t _0;
	int64_t _10_x;
	int64_t* _1;
	int64_t* _10_y;
	int64_t* _2;
	int64_t _3;
	int64_t _4;
BB0:;
	_0 = 29;
	_10_x = _0;
	_1 = &_10_x;
	_10_y = _1;
	_2 = &_10_x;
	_3 = *_10_y;
	_4 = *_10_y;
	retval = _4;
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
