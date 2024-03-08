/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;

/* Struct, union, and function definitions */
struct struct0 {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
};

struct struct1 {
    int64_t* _0;
    int64_t _1;
};

typedef int64_t(*function2)(void);

/* Function forward definitions */
int64_t _1093_main(void);
int64_t _1095_f(void);


/* Function definitions */
int64_t _1093_main(void){
    int64_t _1093_t1;
    int64_t _1093_t2;
    int64_t _1093_t3;
    int64_t _1093_t4;
    struct struct0 _1094_x;
    int64_t _1093_t6;
    int64_t _1093_t7;
    int64_t* _1093_t8;
    int64_t _1093_t9;
    struct struct1 _1094_y;
    function2 _1093_t11;
    int64_t _1093_t12;
    int64_t _1093_$retval;
    _1093_t1 = 0;
    _1093_t2 = 0;
    _1093_t3 = 0;
    _1093_t4 = 0;
    _1094_x = (struct struct0) {_1093_t1, _1093_t2, _1093_t3, _1093_t4};
    _1093_t6 = 0;
    _1093_t7 = 4;
    $bounds_check(_1093_t6, _1093_t7, "tests/integration/lint/slice-copy-pos-bounds-check.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1093_t8 = ((int64_t*)&_1094_x + _1093_t6);
    _1093_t9 = 4;
    _1094_y = (struct struct1) {_1093_t8, _1093_t9};
    _1093_t11 = (function2) _1095_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-copy-pos-bounds-check.orng:5:9:\n    y[f()] = 0\n       ^";
    _1093_t12 = _1093_t11();
    $line_idx--;
    $bounds_check(_1093_t12, _1094_y._1, "tests/integration/lint/slice-copy-pos-bounds-check.orng:5:15:\n    y[f()] = 0\n             ^");
    *((int64_t*)_1094_y._0 + _1093_t12) = 0;
    _1093_$retval = 0;
    return _1093_$retval;
}

int64_t _1095_f(void){
    int64_t _1095_$retval;
    _1095_$retval = 100;
    return _1095_$retval;
}


int main(void) {
  printf("%ld",_1093_main());
  return 0;
}
