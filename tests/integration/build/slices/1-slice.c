/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
} struct0;

typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _1_main(void);
int64_t _3_first(struct1 _3_xs);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _1_t2;
    int64_t* _1_t7;
    struct1 _1_t1;
    int64_t _1_t0;
    int64_t _1_$retval;
    _1_t2 = (struct0) {233};
    _1_t7 = (int64_t*)&_1_t2;
    _1_t1 = (struct1) {_1_t7, 1};
    $lines[$line_idx++] = "tests/integration/slices/1-slice.orng:3:11:\n    first([](233,))\n         ^";
    _1_t0 = _3_first(_1_t1);
    $line_idx--;
    _1_$retval = _1_t0;
    return _1_$retval;
}

int64_t _3_first(struct1 _3_xs) {
    int64_t _3_$retval;
    $bounds_check(0, _3_xs._1, "tests/integration/slices/1-slice.orng:7:8:\n    xs[0]\n      ^");
    _3_$retval = *(int64_t*)_3_xs._0;
    return _3_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
