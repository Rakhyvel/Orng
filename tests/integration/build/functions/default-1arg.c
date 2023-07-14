/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1688936290631932279
#define ORNG_1688936290631932279

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
int64_t _4_return53(int64_t _4_x);

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t1;
	int64_t _2_t0;
	int64_t _2_$retval;
BB0:
	_2_t1 = 53;
    $lines[$line_idx++] = "fn main() -> Int {return53()}";
	_2_t0 = _4_return53(_2_t1);
	_2_$retval = _2_t0;
	return _2_$retval;
}

int64_t _4_return53(int64_t _4_x) {
	int64_t _4_$retval;
BB1:
	_4_$retval = _4_x;
	return _4_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
