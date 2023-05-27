/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1685230955
#define ORNG_1685230955

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int test_main();

int test_main() {
	int64_t _72_t1;
	int64_t* _72_t2;
	int64_t* _72_t3;
	int64_t _72_t4;
	int64_t* _72_t5;
	int64_t _72_t6;
	int64_t _72_$retval;
BB0: // 1
// Versions: 1
	_72_t1 = 4;
// Versions: 1
	_72_t2 = &_72_t1;
// Versions: 1
	_72_t3 = _72_t2;
// Versions: 1
	_72_t4 = 28;
	*_72_t3 = _72_t4;
// Versions: 1
	_72_t5 = _72_t2;
// Versions: 1
	_72_t6 = *_72_t5;
// Versions: 1
	_72_$retval = _72_t6;
	goto end;
end:
	return _72_$retval;
}


int main()
{
  printf("%d", test_main());
  return 0;
}

#endif
