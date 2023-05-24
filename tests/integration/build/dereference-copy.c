/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1684895482
#define ORNG_1684895482

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int retval;
	int64_t _72_t0;
	int64_t _73_x;
	int64_t* _72_t1;
	int64_t* _73_y;
	int64_t _72_t2;
	int64_t _72_t3;
	int64_t _0;
BB0: // 1
	_72_t0 = 4;
	_73_x = _72_t0;
	_72_t1 = &_73_x;
	_73_y = _72_t1;
	_72_t2 = 28;
	*_73_y = _72_t2;
	_72_t3 = *_73_y;
	retval = _72_t3;
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
