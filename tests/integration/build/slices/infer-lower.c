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
int64_t _1328_main(void);
int64_t _1333_sum_up(struct1 _1333_xs);

/* Function definitions */
int64_t _1328_main(void){
    int64_t _1328_t1;
    int64_t _1328_t2;
    int64_t _1328_t3;
    int64_t _1328_t4;
    int64_t _1328_t5;
    int64_t _1328_t6;
    struct0 _1329_x;
    int64_t _1328_t8;
    int64_t* _1328_t9;
    int64_t _1328_t10;
    struct1 _1329_y;
    int64_t _1328_t14;
    int64_t* _1328_t15;
    struct1 _1329_z;
    function2 _1328_t17;
    int64_t _1328_t18;
    int64_t _1328_$retval;
    _1328_t1 = 100;
    _1328_t2 = 8;
    _1328_t3 = 2;
    _1328_t4 = 4;
    _1328_t5 = 35;
    _1328_t6 = 6;
    _1329_x = (struct0) {_1328_t1, _1328_t2, _1328_t3, _1328_t4, _1328_t5, _1328_t6};
    _1328_t8 = 0;
    _1328_t9 = ((int64_t*)&_1329_x + _1328_t8);
    _1328_t10 = 6;
    _1329_y = (struct1) {_1328_t9, _1328_t10};
    _1328_t14 = 3;
    _1328_t15 = _1329_y._0;
    _1329_z = (struct1) {_1328_t15, _1328_t14};
    _1328_t17 = _1333_sum_up;
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _1328_t18 = _1328_t17(_1329_z);
    $line_idx--;
    _1328_$retval = _1328_t18;
    return _1328_$retval;
}

int64_t _1333_sum_up(struct1 _1333_xs){
    int64_t _1336_sum;
    int64_t _1337_i;
    uint8_t _1333_t3;
    int64_t _1333_t5;
    int64_t _1333_$retval;
    _1336_sum = 0;
    _1337_i = 0;
    goto BB1;
BB1:
    _1333_t3 = _1337_i < _1333_xs._1;
    if (_1333_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1336_sum = $add_int64_t(_1336_sum, *((int64_t*)_1333_xs._0 + _1337_i), "tests/integration/slices/infer-lower.orng:12:15:\n        sum += xs[i]\n             ^");
    _1333_t5 = 1;
    _1337_i = $add_int64_t(_1337_i, _1333_t5, "tests/integration/slices/infer-lower.orng:11:50:\n    while let mut i: Int = 0; i < xs.length; i += 1 {\n                                                ^");
    goto BB1;
BB7:
    _1333_$retval = _1336_sum;
    return _1333_$retval;
}

int main(void) {
  printf("%ld",_1328_main());
  return 0;
}
