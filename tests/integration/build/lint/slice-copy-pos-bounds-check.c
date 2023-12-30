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
int64_t _1043_main(void);
int64_t _1045_f(void);

/* Function definitions */
int64_t _1043_main(void){
    int64_t _1043_t1;
    int64_t _1043_t2;
    int64_t _1043_t3;
    int64_t _1043_t4;
    struct0 _1044_x;
    int64_t _1043_t6;
    int64_t _1043_t7;
    int64_t* _1043_t8;
    int64_t _1043_t9;
    struct1 _1044_y;
    function2 _1043_t11;
    int64_t _1043_t12;
    int64_t _1043_$retval;
    _1043_t1 = 0;
    _1043_t2 = 0;
    _1043_t3 = 0;
    _1043_t4 = 0;
    _1044_x = (struct0) {_1043_t1, _1043_t2, _1043_t3, _1043_t4};
    _1043_t6 = 0;
    _1043_t7 = 4;
    $bounds_check(_1043_t6, _1043_t7, "tests/integration/lint/slice-copy-pos-bounds-check.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1043_t8 = ((int64_t*)&_1044_x + _1043_t6);
    _1043_t9 = 4;
    _1044_y = (struct1) {_1043_t8, _1043_t9};
    _1043_t11 = _1045_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-copy-pos-bounds-check.orng:5:9:\n    y[f()] = 0\n       ^";
    _1043_t12 = _1043_t11();
    $line_idx--;
    $bounds_check(_1043_t12, _1044_y._1, "tests/integration/lint/slice-copy-pos-bounds-check.orng:5:15:\n    y[f()] = 0\n             ^");
    *((int64_t*)_1044_y._0 + _1043_t12) = 0;
    _1043_$retval = 0;
    return _1043_$retval;
}

int64_t _1045_f(void){
    int64_t _1045_$retval;
    _1045_$retval = 100;
    return _1045_$retval;
}

int main(void) {
  printf("%ld",_1043_main());
  return 0;
}
