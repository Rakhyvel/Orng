/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1694153866487585864
#define ORNG_1694153866487585864

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
    struct0 _2_t5;
    int64_t _2_t11;
    uint8_t _2_t10;
    int64_t _2_t13;
    uint8_t _2_t12;
    int64_t _2_t8;
    int64_t _2_$retval;
BB0:
    _2_t1 = 1;
    _2_t2 = 2;
    _2_t0 = (struct0) {_2_t1, _2_t2};
    _3_x = (&_2_t0)->_0;
    _3_y = (&_2_t0)->_1;
    _2_t5 = (struct0) {_3_x, _3_y};
    _3_y = (&_2_t5)->_0;
    _3_x = (&_2_t5)->_1;
    _2_t11 = 1;
    _2_t10 = _3_y == _2_t11;
    if (_2_t10) {
        goto BB1;
    } else {
        goto BB11;
    }
BB11:
    $lines[$line_idx++] = "tests/integration/pattern/assign-swap.orng:8:20:\n        unreachable\n                  ^";
    fprintf(stderr, "panic: reached unreachable code\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
    goto BB10;
BB10:
    _2_$retval = _2_t8;
    return _2_$retval;
BB1:
    _2_t13 = 2;
    _2_t12 = _3_x == _2_t13;
    if (_2_t12) {
        goto BB4;
    } else {
        goto BB11;
    }
BB4:
    _2_t8 = 159;
    goto BB10;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
