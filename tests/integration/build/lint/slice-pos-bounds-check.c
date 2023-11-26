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
int64_t _45_main(void);
int64_t _47_f(void);

/* Function definitions */
int64_t _45_main(void) {
    int64_t _45_t1;
    int64_t _45_t2;
    int64_t _45_t3;
    int64_t _45_t4;
    struct0 _46_x;
    int64_t _45_t6;
    int64_t* _45_t7;
    int64_t _45_t8;
    struct1 _46_y;
    function2 _45_t9;
    int64_t _45_t10;
    int64_t _45_$retval;
    _45_t1 = 0;
    _45_t2 = 0;
    _45_t3 = 0;
    _45_t4 = 0;
    _46_x = (struct0) {_45_t1, _45_t2, _45_t3, _45_t4};
    _45_t6 = 0;
    _45_t7 = ((int64_t*)&_46_x + _45_t6);
    _45_t8 = 4;
    _46_y = (struct1) {_45_t7, _45_t8};
    _45_t9 = _47_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-pos-bounds-check.orng:5:9:\n    y[f()]\n       ^";
    _45_t10 = _45_t9();
    $line_idx--;
    _45_$retval = *((int64_t*)&_46_y._0 + _45_t10);
    return _45_$retval;
}

int64_t _47_f(void) {
    int64_t _47_$retval;
    _47_$retval = 100;
    return _47_$retval;
}

int main(void) {
  printf("%ld",_45_main());
  return 0;
}
