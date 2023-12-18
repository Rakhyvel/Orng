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
int64_t _1173_main(void);
int64_t _1179_f(void);

/* Function definitions */
int64_t _1173_main(void){
    int64_t _1173_t1;
    int64_t _1173_t2;
    int64_t _1173_t3;
    int64_t _1173_t4;
    struct0 _1174_x;
    int64_t _1173_t6;
    int64_t _1173_t7;
    int64_t* _1173_t8;
    int64_t _1173_t9;
    struct1 _1174_y;
    function2 _1173_t11;
    int64_t _1173_t12;
    int64_t _1173_$retval;
    _1173_t1 = 0;
    _1173_t2 = 0;
    _1173_t3 = 0;
    _1173_t4 = 0;
    _1174_x = (struct0) {_1173_t1, _1173_t2, _1173_t3, _1173_t4};
    _1173_t6 = 0;
    _1173_t7 = 4;
    $bounds_check(_1173_t6, _1173_t7, "tests/integration/lint/slice-copy-neg-bounds-check.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1173_t8 = ((int64_t*)&_1174_x + _1173_t6);
    _1173_t9 = 4;
    _1174_y = (struct1) {_1173_t8, _1173_t9};
    _1173_t11 = _1179_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-copy-neg-bounds-check.orng:5:9:\n    y[f()] = 0\n       ^";
    _1173_t12 = _1173_t11();
    $line_idx--;
    $bounds_check(_1173_t12, _1174_y._1, "tests/integration/lint/slice-copy-neg-bounds-check.orng:5:15:\n    y[f()] = 0\n             ^");
    *((int64_t*)_1174_y._0 + _1173_t12) = 0;
    _1173_$retval = 0;
    return _1173_$retval;
}

int64_t _1179_f(void){
    int64_t _1179_$retval;
    _1179_$retval = -100;
    return _1179_$retval;
}

int main(void) {
  printf("%ld",_1173_main());
  return 0;
}
