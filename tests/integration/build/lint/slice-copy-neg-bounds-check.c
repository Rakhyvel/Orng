/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

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

typedef int64_t(*function2)(void);

/* Function forward definitions */
int64_t _30_main(void);
int64_t _32_f(void);

/* Function definitions */
int64_t _30_main(void) {
    int64_t _30_t1;
    int64_t _30_t2;
    int64_t _30_t3;
    int64_t _30_t4;
    struct0 _31_x;
    int64_t _30_t6;
    int64_t* _30_t7;
    int64_t _30_t8;
    struct1 _31_y;
    function2 _30_t10;
    int64_t _30_t11;
    int64_t _30_$retval;
    _30_t1 = 0;
    _30_t2 = 0;
    _30_t3 = 0;
    _30_t4 = 0;
    _31_x = (struct0) {_30_t1, _30_t2, _30_t3, _30_t4};
    _30_t6 = 0;
    _30_t7 = ((int64_t*)&_31_x + _30_t6);
    _30_t8 = 4;
    _31_y = (struct1) {_30_t7, _30_t8};
    _30_t10 = _32_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-copy-neg-bounds-check.orng:5:9:\n    y[f()] = 0\n       ^";
    _30_t11 = _30_t10();
    $line_idx--;
    *((int64_t*)&_31_y._0 + _30_t11) = 0;
    _30_$retval = 0;
    return _30_$retval;
}

int64_t _32_f(void) {
    int64_t _32_$retval;
    _32_$retval = -100;
    return _32_$retval;
}

int main(void) {
  printf("%ld",_30_main());
  return 0;
}
