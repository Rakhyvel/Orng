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
int64_t _1137_main(void);
int64_t _1139_f(void);


/* Function definitions */
int64_t _1137_main(void){
    int64_t _1137_t1;
    int64_t _1137_t2;
    int64_t _1137_t3;
    int64_t _1137_t4;
    struct struct0 _1138_x;
    int64_t _1137_t7;
    int64_t _1137_t8;
    int64_t* _1137_t9;
    int64_t _1137_t10;
    struct struct1 _1138_y;
    function2 _1137_t13;
    int64_t _1137_t14;
    int64_t _1137_$retval;
    _1137_t1 = 0;
    _1137_t2 = 0;
    _1137_t3 = 0;
    _1137_t4 = 0;
    _1138_x = (struct struct0) {_1137_t1, _1137_t2, _1137_t3, _1137_t4};
    _1137_t7 = 0;
    _1137_t8 = 4;
    $bounds_check(_1137_t7, _1137_t8, "tests/integration/lint/slice-copy-pos-bounds-check.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1137_t9 = ((int64_t*)&_1138_x + _1137_t7);
    _1137_t10 = 4;
    _1138_y = (struct struct1) {_1137_t9, _1137_t10};
    _1137_t13 = (function2) _1139_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-copy-pos-bounds-check.orng:5:9:\n    y[f()] = 0\n       ^";
    _1137_t14 = _1137_t13();
    $line_idx--;
    $bounds_check(_1137_t14, _1138_y._1, "tests/integration/lint/slice-copy-pos-bounds-check.orng:5:15:\n    y[f()] = 0\n             ^");
    *((int64_t*)_1138_y._0 + _1137_t14) = 0;
    _1137_$retval = 0;
    return _1137_$retval;
}

int64_t _1139_f(void){
    int64_t _1139_$retval;
    _1139_$retval = 100;
    return _1139_$retval;
}


int main(void) {
  printf("%ld",_1137_main());
  return 0;
}
