/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1694153603543008056
#define ORNG_1694153603543008056

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
    int64_t _3;
} struct0;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();
int64_t _4_f();

/* Function definitions */
int64_t _2_main() {
    int64_t _2_t1;
    int64_t _2_t2;
    int64_t _2_t3;
    int64_t _2_t4;
    struct0 _3_x;
    int64_t _2_t5;
    int64_t _2_t7;
    uint8_t _2_t8;
    int64_t _2_t9;
    uint8_t _2_t10;
    int64_t _2_t6;
    int64_t _2_$retval;
BB0:
    _2_t1 = 0;
    _2_t2 = 0;
    _2_t3 = 0;
    _2_t4 = 0;
    _3_x = (struct0) {_2_t1, _2_t2, _2_t3, _2_t4};
    $lines[$line_idx++] = "tests/integration/lint/array-neg-bounds-check.orng:4:9:\n    x[f()]\n       ^";
    _2_t5 = _4_f();
    $line_idx--;
    _2_t7 = 0;
    _2_t8 = _2_t5 < _2_t7;
    if (_2_t8) {
        goto BB1;
    } else {
        goto BB2;
    }
BB2:
    _2_t9 = 4;
    _2_t10 = _2_t5 >= _2_t9;
    if (_2_t10) {
        goto BB3;
    } else {
        goto BB4;
    }
BB4:
    _2_t6 = *(((int64_t*)(&_3_x))+_2_t5);
    _2_$retval = _2_t6;
    return _2_$retval;
BB3:
    $lines[$line_idx++] = "tests/integration/lint/array-neg-bounds-check.orng:4:7:\n    x[f()]\n     ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
    goto BB4;
BB1:
    $lines[$line_idx++] = "tests/integration/lint/array-neg-bounds-check.orng:4:7:\n    x[f()]\n     ^";
    fprintf(stderr, "panic: index is negative\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
    goto BB2;
}

int64_t _4_f() {
    int64_t _4_$retval;
BB0:
    _4_$retval = -100;
    return _4_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
