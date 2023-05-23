/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684807658
#define ORNG_1684807658

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int64_t _0;
	int64_t _73_x;
	int64_t* _1;
	int64_t* _73_y;
	int64_t _2;
	int64_t _3;
BB0:;
	_0 = 4;
	_73_x = _0;
	_1 = &_73_x;
	_73_y = _1;
	_2 = 28;
	*_73_y = _2;
	_3 = *_73_y;
	retval = _3;
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
