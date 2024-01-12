/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;
struct struct1;

/* Typedefs */
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
int64_t _1056_main(void);
int64_t _1058_f(void);

/* Function definitions */
int64_t _1056_main(void){
    int64_t _1056_t1;
    int64_t _1056_t2;
    int64_t _1056_t3;
    int64_t _1056_t4;
    struct struct0 _1057_x;
    int64_t _1056_t6;
    int64_t _1056_t7;
    int64_t* _1056_t8;
    int64_t _1056_t9;
    struct struct1 _1057_y;
    function2 _1056_t11;
    int64_t _1056_t12;
    int64_t _1056_$retval;
    _1056_t1 = 0;
    _1056_t2 = 0;
    _1056_t3 = 0;
    _1056_t4 = 0;
    _1057_x = (struct struct0) {_1056_t1, _1056_t2, _1056_t3, _1056_t4};
    _1056_t6 = 0;
    _1056_t7 = 4;
    $bounds_check(_1056_t6, _1056_t7, "tests/integration/lint/slice-copy-neg-bounds-check.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1056_t8 = ((int64_t*)&_1057_x + _1056_t6);
    _1056_t9 = 4;
    _1057_y = (struct struct1) {_1056_t8, _1056_t9};
    _1056_t11 = _1058_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-copy-neg-bounds-check.orng:5:9:\n    y[f()] = 0\n       ^";
    _1056_t12 = _1056_t11();
    $line_idx--;
    $bounds_check(_1056_t12, _1057_y._1, "tests/integration/lint/slice-copy-neg-bounds-check.orng:5:15:\n    y[f()] = 0\n             ^");
    *((int64_t*)_1057_y._0 + _1056_t12) = 0;
    _1056_$retval = 0;
    return _1056_$retval;
}

int64_t _1058_f(void){
    int64_t _1058_$retval;
    _1058_$retval = -100;
    return _1058_$retval;
}

int main(void) {
  printf("%ld",_1056_main());
  return 0;
}
