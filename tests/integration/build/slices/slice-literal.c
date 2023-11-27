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
int64_t _944_main(void);
int64_t _946_sum(struct1 _946_xs);

/* Function definitions */
int64_t _944_main(void) {
    function0 _944_t0;
    int64_t _944_t3;
    int64_t _944_t5;
    int64_t _944_t6;
    int64_t _944_t7;
    struct2 _944_t4;
    int64_t* _944_t8;
    int64_t _944_t9;
    struct1 _944_t2;
    int64_t _944_t1;
    int64_t _944_$retval;
    _944_t0 = _946_sum;
    _944_t3 = 0;
    _944_t5 = 200;
    _944_t6 = 0;
    _944_t7 = 8;
    _944_t4 = (struct2) {_944_t5, _944_t6, _944_t7};
    _944_t8 = ((int64_t*)&_944_t4 + _944_t3);
    _944_t9 = 3;
    _944_t2 = (struct1) {_944_t8, _944_t9};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:3:9:\n    sum([](200, 0, 8)) // Slice of product literal\n       ^";
    _944_t1 = _944_t0(_944_t2);
    $line_idx--;
    _944_$retval = _944_t1;
    return _944_$retval;
}

int64_t _946_sum(struct1 _946_xs) {
    int64_t _946_t1;
    uint8_t _946_t3;
    int64_t _946_t10;
    int64_t* _946_t11;
    struct1 _946_t12;
    int64_t _946_t7;
    int64_t _946_t0;
    int64_t _946_$retval;
    int64_t _946_t5;
    function0 _946_t6;
    int64_t _946_t8;
    uint8_t _946_t9;
    _946_t1 = 0;
    _946_t3 = _946_xs._1 == _946_t1;
    if (_946_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _946_t0 = 0;
    goto BB6;
BB7:
    _946_t5 = 0;
    _946_t6 = _946_sum;
    _946_t8 = 1;
    _946_t9 = _946_t8 > _946_xs._1;
    if (_946_t9) {
        goto BB8;
    } else {
        goto BB9;
    }
BB6:
    _946_$retval = _946_t0;
    return _946_$retval;
BB8:
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB9:
    _946_t10 = $sub_int64_t(_946_xs._1, _946_t8, "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^");
    _946_t11 = _946_xs._0 + _946_t8;
    _946_t12 = (struct1) {_946_t11, _946_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:21:\n        xs[0] + sum(xs[1..])\n                   ^";
    _946_t7 = _946_t6(_946_t12);
    $line_idx--;
    _946_t0 = $add_int64_t(*((int64_t*)_946_xs._0 + _946_t5), _946_t7, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    goto BB6;
}

int main(void) {
  printf("%ld",_944_main());
  return 0;
}
