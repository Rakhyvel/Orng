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
    int64_t _4;
    int64_t _5;
} struct0;

typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

typedef int64_t(*function2)(struct1);

/* Function forward definitions */
int64_t _1509_main(void);
int64_t _1514_sum_up(struct1 _1514_xs);

/* Function definitions */
int64_t _1509_main(void){
    int64_t _1509_t1;
    int64_t _1509_t2;
    int64_t _1509_t3;
    int64_t _1509_t4;
    int64_t _1509_t5;
    int64_t _1509_t6;
    struct0 _1510_x;
    int64_t _1509_t8;
    int64_t _1509_t9;
    int64_t* _1509_t10;
    int64_t _1509_t11;
    struct1 _1510_y;
    int64_t _1509_t15;
    int64_t* _1509_t16;
    struct1 _1510_z;
    function2 _1509_t18;
    int64_t _1509_t19;
    int64_t _1509_$retval;
    _1509_t1 = 100;
    _1509_t2 = 8;
    _1509_t3 = 2;
    _1509_t4 = 4;
    _1509_t5 = 35;
    _1509_t6 = 6;
    _1510_x = (struct0) {_1509_t1, _1509_t2, _1509_t3, _1509_t4, _1509_t5, _1509_t6};
    _1509_t8 = 0;
    _1509_t9 = 6;
    $bounds_check(_1509_t8, _1509_t9, "tests/integration/slices/infer-lower.orng:4:19:\n    let y = [mut]x\n                 ^");
    _1509_t10 = ((int64_t*)&_1510_x + _1509_t8);
    _1509_t11 = 6;
    _1510_y = (struct1) {_1509_t10, _1509_t11};
    _1509_t15 = 3;
    _1509_t16 = _1510_y._0;
    _1510_z = (struct1) {_1509_t16, _1509_t15};
    _1509_t18 = _1514_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1509_t19 = _1509_t18(_1510_z);
    $line_idx--;
    _1509_$retval = _1509_t19;
    return _1509_$retval;
}

int64_t _1514_sum_up(struct1 _1514_xs){
    int64_t _1517_sum;
    int64_t _1518_i;
    uint8_t _1514_t3;
    int64_t _1514_t5;
    int64_t _1514_$retval;
    _1517_sum = 0;
    _1518_i = 0;
    goto BB1;
BB1:
    _1514_t3 = _1518_i < _1514_xs._1;
    if (_1514_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    $bounds_check(_1518_i, _1514_xs._1, "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1517_sum = $add_int64_t(_1517_sum, *((int64_t*)_1514_xs._0 + _1518_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1514_t5 = 1;
    _1518_i = $add_int64_t(_1518_i, _1514_t5, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1514_$retval = _1517_sum;
    return _1514_$retval;
}

int main(void) {
  printf("%ld",_1509_main());
  return 0;
}
