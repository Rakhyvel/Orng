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
void _4_f();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_$retval;
BB0:
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()";
	_4_f();
	_2_$retval = 48;
	return _2_$retval;
}

void _4_f() {
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
