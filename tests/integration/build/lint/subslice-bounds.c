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
int64_t _50_main(void);
int64_t _52_f(void);

/* Function definitions */
int64_t _50_main(void) {
    int64_t _50_t1;
    int64_t _50_t2;
    int64_t _50_t3;
    int64_t _50_t4;
    struct0 _51_x;
    int64_t _50_t6;
    int64_t* _50_t7;
    int64_t _50_t8;
    struct1 _51_y;
    function2 _50_t9;
    int64_t _50_t10;
    int64_t _50_t11;
    uint8_t _50_t12;
    int64_t _50_t13;
    int64_t* _50_t14;
    struct1 _51_z;
    int64_t _50_t16;
    int64_t _50_$retval;
    _50_t1 = 0;
    _50_t2 = 0;
    _50_t3 = 0;
    _50_t4 = 0;
    _51_x = (struct0) {_50_t1, _50_t2, _50_t3, _50_t4};
    _50_t6 = 0;
    _50_t7 = ((int64_t*)&_51_x + _50_t6);
    _50_t8 = 4;
    _51_y = (struct1) {_50_t7, _50_t8};
    _50_t9 = _52_f;
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:17:\n    let z = y[f()..1]\n               ^";
    _50_t10 = _50_t9();
    $line_idx--;
    _50_t11 = 1;
    _50_t12 = _50_t10 > _50_t11;
    if (_50_t12) {
        goto BB1;
    } else {
        goto BB2;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB2:
    _50_t13 = $sub_int64_t(_50_t11, _50_t10, "tests/integration/lint/subslice-bounds.orng:5:15:\n    let z = y[f()..1]\n             ^");
    _50_t14 = _51_y._0 + _50_t10;
    _51_z = (struct1) {_50_t14, _50_t13};
    _50_t16 = 0;
    _50_$retval = *((int64_t*)&_51_z._0 + _50_t16);
    return _50_$retval;
}

int64_t _52_f(void) {
    int64_t _52_$retval;
    _52_$retval = 2;
    return _52_$retval;
}

int main(void) {
  printf("%ld",_50_main());
  return 0;
}
