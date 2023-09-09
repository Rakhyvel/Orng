/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1694151941672691958
#define ORNG_1694151941672691958

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
} struct0;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    int64_t _2_t1;
    int64_t _2_t2;
    int64_t _2_t3;
    int64_t _2_t4;
    struct0 _3_x;
    struct0* _3_y;
    int64_t _2_t6;
    struct0 _2_t7;
    int64_t _2_t8;
    struct0 _2_t13;
    int64_t _2_t14;
    int64_t _2_t15;
    int64_t _2_$retval;
BB0:
    _2_t1 = 1;
    _2_t2 = 2;
    _2_t3 = 3;
    _2_t4 = 4;
    _3_x = (struct0) {_2_t1, _2_t2, _2_t3, _2_t4};
    _3_y = &_3_x;
    _2_t6 = 70;
    _2_t7 = *_3_y;
    _2_t8 = 2;
    *(((int64_t*)(_3_y))+_2_t8) = _2_t6;
    _2_t13 = *_3_y;
    _2_t14 = 2;
    _2_t15 = *(((int64_t*)(_3_y))+_2_t14);
    _2_$retval = _2_t15;
    return _2_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
