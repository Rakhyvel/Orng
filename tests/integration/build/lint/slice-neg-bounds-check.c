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
int64_t _40_main(void);
int64_t _42_f(void);

/* Function definitions */
int64_t _40_main(void) {
    int64_t _40_t1;
    int64_t _40_t2;
    int64_t _40_t3;
    int64_t _40_t4;
    struct0 _41_x;
    int64_t _40_t6;
    int64_t* _40_t7;
    int64_t _40_t8;
    struct1 _41_y;
    function2 _40_t9;
    int64_t _40_t10;
    int64_t _40_$retval;
    _40_t1 = 0;
    _40_t2 = 0;
    _40_t3 = 0;
    _40_t4 = 0;
    _41_x = (struct0) {_40_t1, _40_t2, _40_t3, _40_t4};
    _40_t6 = 0;
    _40_t7 = ((int64_t*)&_41_x + _40_t6);
    _40_t8 = 4;
    _41_y = (struct1) {_40_t7, _40_t8};
    _40_t9 = _42_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-neg-bounds-check.orng:5:9:\n    y[f()]\n       ^";
    _40_t10 = _40_t9();
    $line_idx--;
    _40_$retval = *((int64_t*)&_41_y._0 + _40_t10);
    return _40_$retval;
}

int64_t _42_f(void) {
    int64_t _42_$retval;
    _42_$retval = -100;
    return _42_$retval;
}

int main(void) {
  printf("%ld",_40_main());
  return 0;
}
