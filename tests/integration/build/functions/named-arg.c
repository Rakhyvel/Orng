/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688936382076691961
#define ORNG_1688936382076691961

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();
int64_t _4_div(int64_t _4_x,int64_t _4_y);

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t2;
	int64_t _2_t0;
	int64_t _2_$retval;
BB0:
	_2_t1 = 510;
	_2_t2 = 10;
    $lines[$line_idx++] = "fn main() -> Int {div(x = 510, y = 10)}";
	_2_t0 = _4_div(_2_t1, _2_t2);
	_2_$retval = _2_t0;
	return _2_$retval;
}

int64_t _4_div(int64_t _4_x,int64_t _4_y) {
	int64_t _4_$retval;
BB0:
	_4_$retval = _4_x / _4_y;
	return _4_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
