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
} struct0;

/* Function forward definitions */
int64_t _1_main(void);
int64_t _3_sum(struct0* _3_xs);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _1_t1;
    struct0* _1_t5;
    int64_t _1_t0;
    int64_t _1_$retval;
    _1_t1 = (struct0) {200, 0, 9};
    _1_t5 = &_1_t1;
    $lines[$line_idx++] = "tests/integration/arrays/addr-of-array.orng:3:9:\n    sum(&(200, 0, 9)) // Address of product literal\n       ^";
    _1_t0 = _3_sum(_1_t5);
    $line_idx--;
    _1_$retval = _1_t0;
    return _1_$retval;
}

int64_t _3_sum(struct0* _3_xs) {
    int64_t _3_$retval;
    _3_$retval = $add_int64_t($add_int64_t(*(int64_t*)_3_xs, *((int64_t*)_3_xs + 1), "tests/integration/arrays/addr-of-array.orng:7:12:\n    xs[0] + xs[1] + xs[2]\n          ^"), *((int64_t*)_3_xs + 2), "tests/integration/arrays/addr-of-array.orng:7:20:\n    xs[0] + xs[1] + xs[2]\n                  ^");
    return _3_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
