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
int64_t _1182_main(void);
int64_t _1188_f(void);

/* Function definitions */
int64_t _1182_main(void){
    int64_t _1182_t1;
    int64_t _1182_t2;
    int64_t _1182_t3;
    int64_t _1182_t4;
    struct0 _1183_x;
    int64_t _1182_t6;
    int64_t _1182_t7;
    int64_t* _1182_t8;
    int64_t _1182_t9;
    struct1 _1183_y;
    function2 _1182_t11;
    int64_t _1182_t12;
    int64_t _1182_$retval;
    _1182_t1 = 0;
    _1182_t2 = 0;
    _1182_t3 = 0;
    _1182_t4 = 0;
    _1183_x = (struct0) {_1182_t1, _1182_t2, _1182_t3, _1182_t4};
    _1182_t6 = 0;
    _1182_t7 = 4;
    $bounds_check(_1182_t6, _1182_t7, "tests/integration/lint/slice-copy-pos-bounds-check.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1182_t8 = ((int64_t*)&_1183_x + _1182_t6);
    _1182_t9 = 4;
    _1183_y = (struct1) {_1182_t8, _1182_t9};
    _1182_t11 = _1188_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-copy-pos-bounds-check.orng:5:9:\n    y[f()] = 0\n       ^";
    _1182_t12 = _1182_t11();
    $line_idx--;
    $bounds_check(_1182_t12, _1183_y._1, "tests/integration/lint/slice-copy-pos-bounds-check.orng:5:15:\n    y[f()] = 0\n             ^");
    *((int64_t*)_1183_y._0 + _1182_t12) = 0;
    _1182_$retval = 0;
    return _1182_$retval;
}

int64_t _1188_f(void){
    int64_t _1188_$retval;
    _1188_$retval = 100;
    return _1188_$retval;
}

int main(void) {
  printf("%ld",_1182_main());
  return 0;
}
