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
int64_t _1197_main(void);
int64_t _1203_f(void);

/* Function definitions */
int64_t _1197_main(void){
    int64_t _1197_t1;
    int64_t _1197_t2;
    int64_t _1197_t3;
    int64_t _1197_t4;
    struct0 _1198_x;
    int64_t _1197_t6;
    int64_t _1197_t7;
    int64_t* _1197_t8;
    int64_t _1197_t9;
    struct1 _1198_y;
    function2 _1197_t10;
    int64_t _1197_t11;
    int64_t _1197_$retval;
    _1197_t1 = 0;
    _1197_t2 = 0;
    _1197_t3 = 0;
    _1197_t4 = 0;
    _1198_x = (struct0) {_1197_t1, _1197_t2, _1197_t3, _1197_t4};
    _1197_t6 = 0;
    _1197_t7 = 4;
    $bounds_check(_1197_t6, _1197_t7, "tests/integration/lint/slice-pos-bounds-check.orng:4:16:\n    let y = []x\n              ^");
    _1197_t8 = ((int64_t*)&_1198_x + _1197_t6);
    _1197_t9 = 4;
    _1198_y = (struct1) {_1197_t8, _1197_t9};
    _1197_t10 = _1203_f;
    $lines[$line_idx++] = "tests/integration/lint/slice-pos-bounds-check.orng:5:9:\n    y[f()]\n       ^";
    _1197_t11 = _1197_t10();
    $line_idx--;
    $bounds_check(_1197_t11, _1198_y._1, "tests/integration/lint/slice-pos-bounds-check.orng:2:3:\nfn main() -> Int {\n ^");
    _1197_$retval = *((int64_t*)_1198_y._0 + _1197_t11);
    return _1197_$retval;
}

int64_t _1203_f(void){
    int64_t _1203_$retval;
    _1203_$retval = 100;
    return _1203_$retval;
}

int main(void) {
  printf("%ld",_1197_main());
  return 0;
}
