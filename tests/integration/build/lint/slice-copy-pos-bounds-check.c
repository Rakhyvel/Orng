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
int64_t _55_main(void);
int64_t _61_f(void);

/* Function definitions */
int64_t _55_main(void){
    int64_t _55_t1;
    int64_t _55_t2;
    int64_t _55_t3;
    int64_t _55_t4;
    struct0 _56_x;
    int64_t _55_t6;
    int64_t _55_t7;
    int64_t* _55_t8;
    int64_t _55_t9;
    struct1 _56_y;
    function2 _55_t11;
    int64_t _55_t12;
    int64_t _55_$retval;
    _55_t1 = 0;
    _55_t2 = 0;
    _55_t3 = 0;
    _55_t4 = 0;
    _56_x = (struct0) {_55_t1, _55_t2, _55_t3, _55_t4};
    _55_t6 = 0;
    _55_t7 = 4;
    $bounds_check(_55_t6, _55_t7, "tests/integration/lint/slice-copy-pos-bounds-check.orng:4:19:\n    let y = [mut]x\n                 ^");
    _55_t8 = ((int64_t*)&_56_x + _55_t6);
    _55_t9 = 4;
    _56_y = (struct1) {_55_t8, _55_t9};
    _55_t11 = _61_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-copy-pos-bounds-check.orng:5:9:\n    y[f()] = 0\n       ^";
    _55_t12 = _55_t11();
    $line_idx--;
    $bounds_check(_55_t12, _56_y._1, "tests/integration/lint/slice-copy-pos-bounds-check.orng:5:15:\n    y[f()] = 0\n             ^");
    *((int64_t*)_56_y._0 + _55_t12) = 0;
    _55_$retval = 0;
    return _55_$retval;
}

int64_t _61_f(void){
    int64_t _61_$retval;
    _61_$retval = 100;
    return _61_$retval;
}

int main(void) {
  printf("%ld",_55_main());
  return 0;
}
