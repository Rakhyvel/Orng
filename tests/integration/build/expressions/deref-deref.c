/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1691899681449729182
#define ORNG_1691899681449729182

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include<stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
	int64_t _3_x;
	int64_t* _3_y;
	int64_t** _3_z;
	int64_t _2_t4;
	int64_t* _2_t5;
	int64_t _2_$retval;
BB0:
	_3_x = 75;
	_3_y = &_3_x;
	_3_z = &_3_y;
	_2_t4 = 75;
	**_3_z = _2_t4;
	_2_t5 = *_3_z;
	_2_$retval = *_2_t5;
	return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
