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
int64_t _1025_main(void);
int64_t _1027_f(void);

/* Function definitions */
int64_t _1025_main(void){
    int64_t _1025_t1;
    int64_t _1025_t2;
    int64_t _1025_t3;
    int64_t _1025_t4;
    struct0 _1026_x;
    int64_t _1025_t6;
    int64_t _1025_t7;
    int64_t* _1025_t8;
    int64_t _1025_t9;
    struct1 _1026_y;
    function2 _1025_t11;
    int64_t _1025_t12;
    int64_t _1025_$retval;
    _1025_t1 = 0;
    _1025_t2 = 0;
    _1025_t3 = 0;
    _1025_t4 = 0;
    _1026_x = (struct0) {_1025_t1, _1025_t2, _1025_t3, _1025_t4};
    _1025_t6 = 0;
    _1025_t7 = 4;
    $bounds_check(_1025_t6, _1025_t7, "tests/integration/lint/slice-copy-neg-bounds-check.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1025_t8 = ((int64_t*)&_1026_x + _1025_t6);
    _1025_t9 = 4;
    _1026_y = (struct1) {_1025_t8, _1025_t9};
    _1025_t11 = _1027_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-copy-neg-bounds-check.orng:5:9:\n    y[f()] = 0\n       ^";
    _1025_t12 = _1025_t11();
    $line_idx--;
    $bounds_check(_1025_t12, _1026_y._1, "tests/integration/lint/slice-copy-neg-bounds-check.orng:5:15:\n    y[f()] = 0\n             ^");
    *((int64_t*)_1026_y._0 + _1025_t12) = 0;
    _1025_$retval = 0;
    return _1025_$retval;
}

int64_t _1027_f(void){
    int64_t _1027_$retval;
    _1027_$retval = -100;
    return _1027_$retval;
}

int main(void) {
  printf("%ld",_1025_main());
  return 0;
}
