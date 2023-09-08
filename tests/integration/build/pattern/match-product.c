/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1694153983858059212
#define ORNG_1694153983858059212

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
    int64_t _2;
} struct0;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    int64_t _2_t2;
    int64_t _2_t3;
    int64_t _2_t4;
    struct0 _2_t1;
    int64_t _2_t5;
    int64_t _2_t6;
    uint8_t _2_t7;
    int64_t _5_x;
    int64_t _5_y;
    int64_t _2_t13;
    int64_t _2_t14;
    int64_t _2_t0;
    int64_t _2_$retval;
BB0:
    _2_t2 = 100;
    _2_t3 = 60;
    _2_t4 = 8;
    _2_t1 = (struct0) {_2_t2, _2_t3, _2_t4};
    _2_t5 = (&_2_t1)->_0;
    _2_t6 = 100;
    _2_t7 = _2_t5 == _2_t6;
    if (_2_t7) {
        goto BB2;
    } else {
        goto BB7;
    }
BB7:
    $lines[$line_idx++] = "tests/integration/pattern/match-product.orng:5:28:\n        else => unreachable\n                          ^";
    fprintf(stderr, "panic: reached unreachable code\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
    goto BB5;
BB5:
    _2_$retval = _2_t0;
    return _2_$retval;
BB2:
    _5_x = (&_2_t1)->_1;
    _5_y = (&_2_t1)->_2;
    _2_t13 = 100;
    _2_t14 = _2_t13 + _5_x;
    _2_t0 = _2_t14 + _5_y;
    goto BB5;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
