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

/* Function forward definitions */
int64_t _1_main();
int64_t _3_f();

/* Function definitions */
int64_t _1_main() {
    struct0 _2_x;
    int64_t* _1_t9;
    struct1 _2_y;
    int64_t _1_t11;
    int64_t _1_t12;
    int64_t* _1_t15;
    int64_t* _1_t16;
    struct1 _2_z;
    int64_t _1_$retval;
    _2_x = (struct0) {0, 0, 0, 0};
    _1_t9 = (int64_t*)&_2_x;
    _2_y = (struct1) {_1_t9, 4};
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:17:\n    let z = y[f()..1]\n               ^";
    _1_t11 = _3_f();
    $line_idx--;
    _1_t12 = 1;
    if (_1_t11 > _1_t12) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _1_t15 = _2_y._0;
    _1_t16 = _1_t15 + _1_t11;
    _2_z = (struct1) {_1_t16, (_1_t12 - _1_t11)};
    $bounds_check(0, _1_t12 - _1_t11, "tests/integration/lint/subslice-bounds.orng:6:7:\n    z[0]\n     ^");
    _1_$retval = *(int64_t*)_2_z._0;
    return _1_$retval;
}

int64_t _3_f() {
    int64_t _3_$retval;
    _3_$retval = 2;
    return _3_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
