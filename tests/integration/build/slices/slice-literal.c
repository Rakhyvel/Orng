/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
        int64_t* _0;
        int64_t _1;
} struct1;

typedef int64_t(*function0)(struct1);

typedef struct {
        int64_t _0;
        int64_t _1;
        int64_t _2;
} struct2;

/* Function forward definitions */
int64_t _1306_main(void);
int64_t _1308_sum(struct1 _1308_xs);

/* Function definitions */
int64_t _1306_main(void){
    function0 _1306_t0;
    int64_t _1306_t4;
    int64_t _1306_t5;
    int64_t _1306_t6;
    struct2 _1306_t3;
    int64_t _1306_t7;
    int64_t _1306_t8;
    int64_t* _1306_t9;
    int64_t _1306_t10;
    struct1 _1306_t2;
    int64_t _1306_t1;
    int64_t _1306_$retval;
    _1306_t0 = _1308_sum;
    _1306_t4 = 200;
    _1306_t5 = 0;
    _1306_t6 = 8;
    _1306_t3 = (struct2) {_1306_t4, _1306_t5, _1306_t6};
    _1306_t7 = 0;
    _1306_t8 = 3;
    $bounds_check(_1306_t7, _1306_t8, "tests/integration/slices/slice-literal.orng:3:16:\n    sum([](200, 0, 8)) // Slice of product literal\n              ^");
    _1306_t9 = ((int64_t*)&_1306_t3 + _1306_t7);
    _1306_t10 = 3;
    _1306_t2 = (struct1) {_1306_t9, _1306_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:3:9:\n    sum([](200, 0, 8)) // Slice of product literal\n       ^";
    _1306_t1 = _1306_t0(_1306_t2);
    $line_idx--;
    _1306_$retval = _1306_t1;
    return _1306_$retval;
}

int64_t _1308_sum(struct1 _1308_xs){
    int64_t _1308_t1;
    uint8_t _1308_t3;
    int64_t _1308_t10;
    int64_t* _1308_t11;
    struct1 _1308_t12;
    int64_t _1308_t7;
    int64_t _1308_t0;
    int64_t _1308_$retval;
    int64_t _1308_t5;
    function0 _1308_t6;
    int64_t _1308_t8;
    uint8_t _1308_t9;
    _1308_t1 = 0;
    _1308_t3 = _1308_xs._1==_1308_t1;
    if (_1308_t3) {
        goto BB1616;
    } else {
        goto BB1620;
    }
BB1616:
    _1308_t0 = 0;
    goto BB1619;
BB1620:
    _1308_t5 = 0;
    _1308_t6 = _1308_sum;
    _1308_t8 = 1;
    _1308_t9 = _1308_t8>_1308_xs._1;
    if (_1308_t9) {
        goto BB1621;
    } else {
        goto BB1622;
    }
BB1619:
    _1308_$retval = _1308_t0;
    return _1308_$retval;
BB1621:
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB1622:
    _1308_t10 = $sub_int64_t(_1308_xs._1, _1308_t8, "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^");
    _1308_t11 = _1308_xs._0+_1308_t8;
    _1308_t12 = (struct1) {_1308_t11, _1308_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:21:\n        xs[0] + sum(xs[1..])\n                   ^";
    _1308_t7 = _1308_t6(_1308_t12);
    $line_idx--;
    $bounds_check(_1308_t5, _1308_xs._1, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    _1308_t0 = $add_int64_t(*((int64_t*)_1308_xs._0 + _1308_t5), _1308_t7, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    goto BB1619;
}

int main(void) {
  printf("%ld",_1306_main());
  return 0;
}
