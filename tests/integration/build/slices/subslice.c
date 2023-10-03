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

/* Function forward definitions */
int64_t _1_main();
int64_t _3_sum_up(struct1 _3_xs);

/* Function definitions */
int64_t _1_main() {
    struct0 _2_x;
    int64_t* _1_t11;
    int64_t* _1_t18;
    struct1 _2_z;
    int64_t _1_t23;
    int64_t _1_$retval;
    _2_x = (struct0) {1, 15, 24, 4, 35, 6};
    _1_t11 = (int64_t*)&_2_x;
    _1_t18 = _1_t11 + 1;
    _2_z = (struct1) {_1_t18, 4};
    *((int64_t*)_2_z._0 + 2) = 10;
    $lines[$line_idx++] = "tests/integration/slices/subslice.orng:7:12:\n    sum_up(z)\n          ^";
    _1_t23 = _3_sum_up(_2_z);
    $line_idx--;
    _1_$retval = _1_t23;
    return _1_$retval;
}

int64_t _3_sum_up(struct1 _3_xs) {
    int64_t _4_sum;
    int64_t _5_i;
    int64_t _3_$retval;
    _4_sum = 0;
    _5_i = 0;
BB1:
    if (_5_i < _3_xs._1) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    $bounds_check(_5_i, _3_xs._1, "tests/integration/slices/subslice.orng:13:19:\n        sum += xs[i]\n                 ^");
    _4_sum = $add_int64_t(_4_sum, *((int64_t*)_3_xs._0 + _5_i), "tests/integration/slices/subslice.orng:13:12:\n        sum += xs[i]\n          ^");
    _5_i = $add_int64_t(_5_i, 1, "tests/integration/slices/subslice.orng:12:47:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                             ^");
    goto BB1;
BB7:
    _3_$retval = _4_sum;
    return _3_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
