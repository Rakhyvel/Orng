/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1694153619554799580
#define ORNG_1694153619554799580

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
typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

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
    int64_t _2_t6;
    int64_t* _2_t12;
    int64_t _2_t13;
    struct1 _3_y;
    int64_t _2_t14;
    int64_t _2_t15;
    int64_t _2_t16;
    uint8_t _2_t17;
    int64_t _2_t18;
    uint8_t _2_t19;
    int64_t _2_$retval;
BB0:
    _2_t1 = 0;
    _2_t2 = 0;
    _2_t3 = 0;
    _2_t4 = 0;
    _3_x = (struct0) {_2_t1, _2_t2, _2_t3, _2_t4};
    _2_t6 = 0;
    _2_t12 = (((int64_t*)(&_3_x))+_2_t6);
    _2_t13 = 4;
    _3_y = (struct1) {_2_t12, _2_t13};
    _2_t14 = 0;
    $lines[$line_idx++] = "tests/integration/lint/slice-copy-neg-bounds-check.orng:5:9:\n    y[f()] = 0\n       ^";
    _2_t15 = _4_f();
    $line_idx--;
    _2_t16 = 0;
    _2_t17 = _2_t15 < _2_t16;
    if (_2_t17) {
        goto BB5;
    } else {
        goto BB6;
    }
BB6:
    _2_t18 = (&_3_y)->_1;
    _2_t19 = _2_t15 >= _2_t18;
    if (_2_t19) {
        goto BB7;
    } else {
        goto BB8;
    }
BB8:
    *(((int64_t*)((&_3_y)->_0))+_2_t15) = _2_t14;
    _2_$retval = 0;
    return _2_$retval;
BB7:
    $lines[$line_idx++] = "tests/integration/lint/slice-copy-neg-bounds-check.orng:5:7:\n    y[f()] = 0\n     ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
    goto BB8;
BB5:
    $lines[$line_idx++] = "tests/integration/lint/slice-copy-neg-bounds-check.orng:5:7:\n    y[f()] = 0\n     ^";
    fprintf(stderr, "panic: index is negative\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
    goto BB6;
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
