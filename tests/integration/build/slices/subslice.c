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
int64_t _1306_main(void);
int64_t _1311_sum_up(struct1 _1311_xs);

/* Function definitions */
int64_t _1306_main(void) {
    int64_t _1306_t1;
    int64_t _1306_t2;
    int64_t _1306_t3;
    int64_t _1306_t4;
    int64_t _1306_t5;
    int64_t _1306_t6;
    struct0 _1307_x;
    int64_t _1306_t8;
    int64_t* _1306_t9;
    int64_t _1306_t10;
    struct1 _1307_y;
    int64_t _1306_t11;
    int64_t _1306_t14;
    int64_t* _1306_t15;
    struct1 _1307_z;
    int64_t _1306_t18;
    function2 _1306_t19;
    int64_t _1306_t20;
    int64_t _1306_$retval;
    _1306_t1 = 1;
    _1306_t2 = 15;
    _1306_t3 = 24;
    _1306_t4 = 4;
    _1306_t5 = 35;
    _1306_t6 = 6;
    _1307_x = (struct0) {_1306_t1, _1306_t2, _1306_t3, _1306_t4, _1306_t5, _1306_t6};
    _1306_t8 = 0;
    _1306_t9 = ((int64_t*)&_1307_x + _1306_t8);
    _1306_t10 = 6;
    _1307_y = (struct1) {_1306_t9, _1306_t10};
    _1306_t11 = 1;
    _1306_t14 = 4;
    _1306_t15 = _1307_y._0 + _1306_t11;
    _1307_z = (struct1) {_1306_t15, _1306_t14};
    _1306_t18 = 2;
    *((int64_t*)_1307_z._0 + _1306_t18) = 10;
    _1306_t19 = _1311_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1306_t20 = _1306_t19(_1307_z);
    $line_idx--;
    _1306_$retval = _1306_t20;
    return _1306_$retval;
}

int64_t _1311_sum_up(struct1 _1311_xs) {
    int64_t _1313_sum;
    int64_t _1315_i;
    uint8_t _1311_t3;
    int64_t _1311_t5;
    int64_t _1311_$retval;
    _1313_sum = 0;
    _1315_i = 0;
    goto BB1;
BB1:
    _1311_t3 = _1315_i < _1311_xs._1;
    if (_1311_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1313_sum = $add_int64_t(_1313_sum, *((int64_t*)_1311_xs._0 + _1315_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1311_t5 = 1;
    _1315_i = $add_int64_t(_1315_i, _1311_t5, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1311_$retval = _1313_sum;
    return _1311_$retval;
}

int main(void) {
  printf("%ld",_1306_main());
  return 0;
}
