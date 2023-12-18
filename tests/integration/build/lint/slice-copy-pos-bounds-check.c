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
int64_t _1179_main(void);
int64_t _1185_f(void);

/* Function definitions */
int64_t _1179_main(void){
    int64_t _1179_t1;
    int64_t _1179_t2;
    int64_t _1179_t3;
    int64_t _1179_t4;
    struct0 _1180_x;
    int64_t _1179_t6;
    int64_t _1179_t7;
    int64_t* _1179_t8;
    int64_t _1179_t9;
    struct1 _1180_y;
    function2 _1179_t11;
    int64_t _1179_t12;
    int64_t _1179_$retval;
    _1179_t1 = 0;
    _1179_t2 = 0;
    _1179_t3 = 0;
    _1179_t4 = 0;
    _1180_x = (struct0) {_1179_t1, _1179_t2, _1179_t3, _1179_t4};
    _1179_t6 = 0;
    _1179_t7 = 4;
    $bounds_check(_1179_t6, _1179_t7, "tests/integration/lint/slice-copy-pos-bounds-check.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1179_t8 = ((int64_t*)&_1180_x + _1179_t6);
    _1179_t9 = 4;
    _1180_y = (struct1) {_1179_t8, _1179_t9};
    _1179_t11 = _1185_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-copy-pos-bounds-check.orng:5:9:\n    y[f()] = 0\n       ^";
    _1179_t12 = _1179_t11();
    $line_idx--;
    $bounds_check(_1179_t12, _1180_y._1, "tests/integration/lint/slice-copy-pos-bounds-check.orng:5:15:\n    y[f()] = 0\n             ^");
    *((int64_t*)_1180_y._0 + _1179_t12) = 0;
    _1179_$retval = 0;
    return _1179_$retval;
}

int64_t _1185_f(void){
    int64_t _1185_$retval;
    _1185_$retval = 100;
    return _1185_$retval;
}

int main(void) {
  printf("%ld",_1179_main());
  return 0;
}
