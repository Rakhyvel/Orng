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
int64_t _35_main(void);
int64_t _37_f(void);

/* Function definitions */
int64_t _35_main(void) {
    int64_t _35_t1;
    int64_t _35_t2;
    int64_t _35_t3;
    int64_t _35_t4;
    struct0 _36_x;
    int64_t _35_t6;
    int64_t* _35_t7;
    int64_t _35_t8;
    struct1 _36_y;
    function2 _35_t10;
    int64_t _35_t11;
    int64_t _35_$retval;
    _35_t1 = 0;
    _35_t2 = 0;
    _35_t3 = 0;
    _35_t4 = 0;
    _36_x = (struct0) {_35_t1, _35_t2, _35_t3, _35_t4};
    _35_t6 = 0;
    _35_t7 = ((int64_t*)&_36_x + _35_t6);
    _35_t8 = 4;
    _36_y = (struct1) {_35_t7, _35_t8};
    _35_t10 = _37_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-copy-pos-bounds-check.orng:5:9:\n    y[f()] = 0\n       ^";
    _35_t11 = _35_t10();
    $line_idx--;
    *((int64_t*)&_36_y._0 + _35_t11) = 0;
    _35_$retval = 0;
    return _35_$retval;
}

int64_t _37_f(void) {
    int64_t _37_$retval;
    _37_$retval = 100;
    return _37_$retval;
}

int main(void) {
  printf("%ld",_35_main());
  return 0;
}
