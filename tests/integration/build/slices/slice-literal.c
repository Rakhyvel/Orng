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
int64_t _979_main(void);
int64_t _981_sum(struct1 _981_xs);

/* Function definitions */
int64_t _979_main(void) {
    function0 _979_t0;
    int64_t _979_t3;
    int64_t _979_t5;
    int64_t _979_t6;
    int64_t _979_t7;
    struct2 _979_t4;
    int64_t* _979_t8;
    int64_t _979_t9;
    struct1 _979_t2;
    int64_t _979_t1;
    int64_t _979_$retval;
    _979_t0 = _981_sum;
    _979_t3 = 0;
    _979_t5 = 200;
    _979_t6 = 0;
    _979_t7 = 8;
    _979_t4 = (struct2) {_979_t5, _979_t6, _979_t7};
    _979_t8 = ((int64_t*)&_979_t4 + _979_t3);
    _979_t9 = 3;
    _979_t2 = (struct1) {_979_t8, _979_t9};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:3:9:\n    sum([](200, 0, 8)) // Slice of product literal\n       ^";
    _979_t1 = _979_t0(_979_t2);
    $line_idx--;
    _979_$retval = _979_t1;
    return _979_$retval;
}

int64_t _981_sum(struct1 _981_xs) {
    int64_t _981_t1;
    uint8_t _981_t3;
    int64_t _981_t10;
    int64_t* _981_t11;
    struct1 _981_t12;
    int64_t _981_t7;
    int64_t _981_t0;
    int64_t _981_$retval;
    int64_t _981_t5;
    function0 _981_t6;
    int64_t _981_t8;
    uint8_t _981_t9;
    _981_t1 = 0;
    _981_t3 = _981_xs._1 == _981_t1;
    if (_981_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _981_t0 = 0;
    goto BB6;
BB7:
    _981_t5 = 0;
    _981_t6 = _981_sum;
    _981_t8 = 1;
    _981_t9 = _981_t8 > _981_xs._1;
    if (_981_t9) {
        goto BB8;
    } else {
        goto BB9;
    }
BB6:
    _981_$retval = _981_t0;
    return _981_$retval;
BB8:
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^";
    $panic("subslice lower bound is greater than upper bound\n");
BB9:
    _981_t10 = $sub_int64_t(_981_xs._1, _981_t8, "tests/integration/slices/slice-literal.orng:10:24:\n        xs[0] + sum(xs[1..])\n                      ^");
    _981_t11 = _981_xs._0 + _981_t8;
    _981_t12 = (struct1) {_981_t11, _981_t10};
    $lines[$line_idx++] = "tests/integration/slices/slice-literal.orng:10:21:\n        xs[0] + sum(xs[1..])\n                   ^";
    _981_t7 = _981_t6(_981_t12);
    $line_idx--;
    _981_t0 = $add_int64_t(*((int64_t*)_981_xs._0 + _981_t5), _981_t7, "tests/integration/slices/slice-literal.orng:10:16:\n        xs[0] + sum(xs[1..])\n              ^");
    goto BB6;
}

int main(void) {
  printf("%ld",_979_main());
  return 0;
}
