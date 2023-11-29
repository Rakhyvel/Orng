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
} struct1;

typedef int64_t(*function0)(struct1*);

/* Function forward definitions */
int64_t _14_main(void);
int64_t _16_sum(struct1* _16_xs);

/* Function definitions */
int64_t _14_main(void) {
    function0 _14_t0;
    int64_t _14_t3;
    int64_t _14_t4;
    int64_t _14_t5;
    struct1 _14_t2;
    struct1* _14_t6;
    int64_t _14_t1;
    int64_t _14_$retval;
    _14_t0 = _16_sum;
    _14_t3 = 200;
    _14_t4 = 0;
    _14_t5 = 9;
    _14_t2 = (struct1) {_14_t3, _14_t4, _14_t5};
    _14_t6 = &_14_t2;
    $lines[$line_idx++] = "tests/integration/arrays/addr-of-array.orng:3:9:\n    sum(&(200, 0, 9)) // Address of product literal\n       ^";
    _14_t1 = _14_t0(_14_t6);
    $line_idx--;
    _14_$retval = _14_t1;
    return _14_$retval;
}

int64_t _16_sum(struct1* _16_xs) {
    int64_t _16_t0;
    int64_t _16_t1;
    int64_t _16_t2;
    int64_t _16_t3;
    int64_t _16_$retval;
    _16_t0 = 0;
    _16_t1 = 1;
    _16_t2 = $add_int64_t(*((int64_t*)_16_xs + _16_t0), *((int64_t*)_16_xs + _16_t1), "tests/integration/arrays/addr-of-array.orng:7:12:\n    xs[0] + xs[1] + xs[2]\n          ^");
    _16_t3 = 2;
    _16_$retval = $add_int64_t(_16_t2, *((int64_t*)_16_xs + _16_t3), "tests/integration/arrays/addr-of-array.orng:7:20:\n    xs[0] + xs[1] + xs[2]\n                  ^");
    return _16_$retval;
}

int main(void) {
  printf("%ld",_14_main());
  return 0;
}
