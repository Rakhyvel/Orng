/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1692244640261273638
#define ORNG_1692244640261273638

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
    int64_t _2_t3;
    int64_t _2_t4;
    int64_t _2_t5;
    uint8_t _2_t2;
    int64_t _2_t0;
    int64_t _2_$retval;
    int64_t _2_t11;
    int64_t _2_t12;
    int64_t _2_t13;
    uint8_t _2_t10;
    int64_t _2_t7;
    int64_t _2_t8;
    int64_t _2_t9;
    uint8_t _2_t6;
BB0:
    _3_x = 4;
    _2_t3 = 4;
    _2_t4 = _3_x - _2_t3;
    _2_t5 = 1;
    _2_t2 = _2_t4 == _2_t5;
    if (_2_t2) {
        goto BB2;
    } else {
        goto BB22;
    }
BB22:
    _2_t7 = 3;
    _2_t8 = _3_x - _2_t7;
    _2_t9 = 1;
    _2_t6 = _2_t8 == _2_t9;
    if (_2_t6) {
        goto BB9;
    } else {
        goto BB21;
    }
BB21:
    _2_t11 = 2;
    _2_t12 = _3_x - _2_t11;
    _2_t13 = 1;
    _2_t10 = _2_t12 == _2_t13;
    if (_2_t10) {
        goto BB14;
    } else {
        goto BB20;
    }
BB20:
    $lines[$line_idx++] = "tests/integration/control-flow/case-let.orng:7:32:\n    | else       => unreachable\n                              ^";
    fprintf(stderr, "panic: reached unreachable code\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
    goto BB7;
BB7:
    _2_$retval = _2_t0;
    return _2_$retval;
BB14:
    _2_t0 = 10;
    goto BB7;
BB9:
    _2_t0 = 23;
    goto BB7;
BB2:
    _2_t0 = 10;
    goto BB7;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
