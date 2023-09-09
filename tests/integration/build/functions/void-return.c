/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1694153480996604002
#define ORNG_1694153480996604002

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();
void _4_void();

/* Function definitions */
int64_t _2_main() {
    int64_t _2_$retval;
BB0:
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    _4_void();
    $line_idx--;
    _2_$retval = 65;
    return _2_$retval;
}

void _4_void() {
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
