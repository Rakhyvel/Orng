/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685163890
#define ORNG_1685163890

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _9_t0;
	int64_t _10_x;
	int64_t _9_t1;
	int64_t* _9_t2;
	int64_t* _10_y;
	int64_t _9_t3;
	int64_t* _9_t4;
	int64_t* _9_t5;
	int64_t _9_t6;
	int64_t* _9_t7;
	int64_t _9_t8;
	int64_t _9_$retval;
BB0: // 1
	_9_t0 = 29;
	_10_x = 29;
	_9_t1 = 29;
	_9_t2 = &_9_t1;
	_10_y = _9_t2;
	_9_t3 = 29;
	_9_t4 = &_9_t3;
	_9_t5 = _9_t2;
	_9_t6 = *_9_t5;
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
