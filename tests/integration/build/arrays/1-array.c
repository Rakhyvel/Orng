/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1691899681445729255
#define ORNG_1691899681445729255

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include<stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */
typedef struct {
    int64_t _0;
} struct0;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    int64_t _2_t1;
    struct0 _3_x;
    int64_t _2_t2;
    int64_t _2_t3;
    int64_t _2_$retval;
BB0:
    _2_t1 = 120;
    _3_x = (struct0) {_2_t1};
    _2_t2 = 0;
    _2_t3 = *(((int64_t*)(&_3_x))+_2_t2);
    _2_$retval = _2_t3;
    return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
