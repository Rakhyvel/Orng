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
int64_t _82_main(void);
int64_t _88_f(void);

/* Function definitions */
int64_t _82_main(void){
    int64_t _82_t1;
    int64_t _82_t2;
    int64_t _82_t3;
    int64_t _82_t4;
    struct0 _83_x;
    int64_t _82_t6;
    int64_t _82_t7;
    int64_t* _82_t8;
    int64_t _82_t9;
    struct1 _83_y;
    function2 _82_t10;
    int64_t _82_t11;
    int64_t _82_t12;
    uint8_t _82_t13;
    int64_t _82_t14;
    int64_t* _82_t15;
    struct1 _83_z;
    int64_t _82_t17;
    int64_t _82_$retval;
    _82_t1 = 0;
    _82_t2 = 0;
    _82_t3 = 0;
    _82_t4 = 0;
    _83_x = (struct0) {_82_t1, _82_t2, _82_t3, _82_t4};
    _82_t6 = 0;
    _82_t7 = 4;
    $bounds_check(_82_t6, _82_t7, "tests/integration/lint/subslice-bounds.orng:4:16:\n    let y = []x\n              ^");
    _82_t8 = ((int64_t*)&_83_x + _82_t6);
    _82_t9 = 4;
    _83_y = (struct1) {_82_t8, _82_t9};
    _82_t10 = _88_f;
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:17:\n    let z = y[f()..1]\n               ^";
    _82_t11 = _82_t10();
    $line_idx--;
    _82_t12 = 1;
    _82_t13 = _82_t11 > _82_t12;
    if (_82_t13) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _82_t14 = $sub_int64_t(_82_t12, _82_t11, "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^");
    _82_t15 = _83_y._0 + _82_t11;
    _83_z = (struct1) {_82_t15, _82_t14};
    _82_t17 = 0;
    $bounds_check(_82_t17, _83_z._1, "tests/integration/lint/subslice-bounds.orng:2:3:\nfn main() -> Int {\n ^");
    _82_$retval = *((int64_t*)_83_z._0 + _82_t17);
    return _82_$retval;
}

int64_t _88_f(void){
    int64_t _88_$retval;
    _88_$retval = 2;
    return _88_$retval;
}

int main(void) {
  printf("%ld",_82_main());
  return 0;
}
