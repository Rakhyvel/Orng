/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1694151893065326790
#define ORNG_1694151893065326790

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
    int64_t _1;
} struct0;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    int64_t _2_t1;
    int64_t _2_t2;
    struct0 _2_t0;
    int64_t _3_x;
    int64_t _3_y;
    int64_t _2_t5;
    int64_t _2_$retval;
BB0:
    _2_t1 = 3;
    _2_t2 = 40;
    _2_t0 = (struct0) {_2_t1, _2_t2};
    _3_x = (&_2_t0)->_0;
    _3_y = (&_2_t0)->_1;
    _2_t5 = 100;
    _3_y = _3_y + _2_t5;
    _2_$retval = _3_x + _3_y;
    return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
