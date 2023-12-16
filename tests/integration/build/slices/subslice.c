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
int64_t _1322_main(void);
int64_t _1327_sum_up(struct1 _1327_xs);

/* Function definitions */
int64_t _1322_main(void){
    int64_t _1322_t1;
    int64_t _1322_t2;
    int64_t _1322_t3;
    int64_t _1322_t4;
    int64_t _1322_t5;
    int64_t _1322_t6;
    struct0 _1323_x;
    int64_t _1322_t8;
    int64_t* _1322_t9;
    int64_t _1322_t10;
    struct1 _1323_y;
    int64_t _1322_t11;
    int64_t _1322_t14;
    int64_t* _1322_t15;
    struct1 _1323_z;
    int64_t _1322_t18;
    function2 _1322_t19;
    int64_t _1322_t20;
    int64_t _1322_$retval;
    _1322_t1 = 1;
    _1322_t2 = 15;
    _1322_t3 = 24;
    _1322_t4 = 4;
    _1322_t5 = 35;
    _1322_t6 = 6;
    _1323_x = (struct0) {_1322_t1, _1322_t2, _1322_t3, _1322_t4, _1322_t5, _1322_t6};
    _1322_t8 = 0;
    _1322_t9 = ((int64_t*)&_1323_x + _1322_t8);
    _1322_t10 = 6;
    _1323_y = (struct1) {_1322_t9, _1322_t10};
    _1322_t11 = 1;
    _1322_t14 = 4;
    _1322_t15 = _1323_y._0 + _1322_t11;
    _1323_z = (struct1) {_1322_t15, _1322_t14};
    _1322_t18 = 2;
    *((int64_t*)_1323_z._0 + _1322_t18) = 10;
    _1322_t19 = _1327_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1322_t20 = _1322_t19(_1323_z);
    $line_idx--;
    _1322_$retval = _1322_t20;
    return _1322_$retval;
}

int64_t _1327_sum_up(struct1 _1327_xs){
    int64_t _1330_sum;
    int64_t _1331_i;
    uint8_t _1327_t3;
    int64_t _1327_t5;
    int64_t _1327_$retval;
    _1330_sum = 0;
    _1331_i = 0;
    goto BB1;
BB1:
    _1327_t3 = _1331_i < _1327_xs._1;
    if (_1327_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1330_sum = $add_int64_t(_1330_sum, *((int64_t*)_1327_xs._0 + _1331_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1327_t5 = 1;
    _1331_i = $add_int64_t(_1331_i, _1327_t5, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1327_$retval = _1330_sum;
    return _1327_$retval;
}

int main(void) {
  printf("%ld",_1322_main());
  return 0;
}
