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
int64_t _46_main(void);
int64_t _52_f(void);

/* Function definitions */
int64_t _46_main(void){
    int64_t _46_t1;
    int64_t _46_t2;
    int64_t _46_t3;
    int64_t _46_t4;
    struct0 _47_x;
    int64_t _46_t6;
    int64_t _46_t7;
    int64_t* _46_t8;
    int64_t _46_t9;
    struct1 _47_y;
    function2 _46_t11;
    int64_t _46_t12;
    int64_t _46_$retval;
    _46_t1 = 0;
    _46_t2 = 0;
    _46_t3 = 0;
    _46_t4 = 0;
    _47_x = (struct0) {_46_t1, _46_t2, _46_t3, _46_t4};
    _46_t6 = 0;
    _46_t7 = 4;
    $bounds_check(_46_t6, _46_t7, "tests/integration/lint/slice-copy-neg-bounds-check.orng:4:19:\n    let y = [mut]x\n                 ^");
    _46_t8 = ((int64_t*)&_47_x + _46_t6);
    _46_t9 = 4;
    _47_y = (struct1) {_46_t8, _46_t9};
    _46_t11 = _52_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-copy-neg-bounds-check.orng:5:9:\n    y[f()] = 0\n       ^";
    _46_t12 = _46_t11();
    $line_idx--;
    $bounds_check(_46_t12, _47_y._1, "tests/integration/lint/slice-copy-neg-bounds-check.orng:5:15:\n    y[f()] = 0\n             ^");
    *((int64_t*)_47_y._0 + _46_t12) = 0;
    _46_$retval = 0;
    return _46_$retval;
}

int64_t _52_f(void){
    int64_t _52_$retval;
    _52_$retval = -100;
    return _52_$retval;
}

int main(void) {
  printf("%ld",_46_main());
  return 0;
}
