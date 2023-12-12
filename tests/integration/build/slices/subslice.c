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
int64_t _1022_main(void);
int64_t _1024_sum_up(struct1 _1024_xs);

/* Function definitions */
int64_t _1022_main(void) {
    int64_t _1022_t1;
    int64_t _1022_t2;
    int64_t _1022_t3;
    int64_t _1022_t4;
    int64_t _1022_t5;
    int64_t _1022_t6;
    struct0 _1023_x;
    int64_t _1022_t8;
    int64_t* _1022_t9;
    int64_t _1022_t10;
    struct1 _1023_y;
    int64_t _1022_t11;
    int64_t _1022_t14;
    int64_t* _1022_t15;
    struct1 _1023_z;
    int64_t _1022_t18;
    function2 _1022_t19;
    int64_t _1022_t20;
    int64_t _1022_$retval;
    _1022_t1 = 1;
    _1022_t2 = 15;
    _1022_t3 = 24;
    _1022_t4 = 4;
    _1022_t5 = 35;
    _1022_t6 = 6;
    _1023_x = (struct0) {_1022_t1, _1022_t2, _1022_t3, _1022_t4, _1022_t5, _1022_t6};
    _1022_t8 = 0;
    _1022_t9 = ((int64_t*)&_1023_x + _1022_t8);
    _1022_t10 = 6;
    _1023_y = (struct1) {_1022_t9, _1022_t10};
    _1022_t11 = 1;
    _1022_t14 = 4;
    _1022_t15 = _1023_y._0 + _1022_t11;
    _1023_z = (struct1) {_1022_t15, _1022_t14};
    _1022_t18 = 2;
    *((int64_t*)_1023_z._0 + _1022_t18) = 10;
    _1022_t19 = _1024_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1022_t20 = _1022_t19(_1023_z);
    $line_idx--;
    _1022_$retval = _1022_t20;
    return _1022_$retval;
}

int64_t _1024_sum_up(struct1 _1024_xs) {
    int64_t _1025_sum;
    int64_t _1026_i;
    uint8_t _1024_t3;
    int64_t _1024_t5;
    int64_t _1024_$retval;
    _1025_sum = 0;
    _1026_i = 0;
    goto BB1;
BB1:
    _1024_t3 = _1026_i < _1024_xs._1;
    if (_1024_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1025_sum = $add_int64_t(_1025_sum, *((int64_t*)_1024_xs._0 + _1026_i), "tests/integration/slices/subslice.orng:13:15:\n        sum += xs[i]\n             ^");
    _1024_t5 = 1;
    _1026_i = $add_int64_t(_1026_i, _1024_t5, "tests/integration/slices/subslice.orng:12:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1024_$retval = _1025_sum;
    return _1024_$retval;
}

int main(void) {
  printf("%ld",_1022_main());
  return 0;
}
