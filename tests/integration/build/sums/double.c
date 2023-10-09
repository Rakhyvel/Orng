/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
    union {
        int64_t _0;
        uint8_t _1;
    };
} struct0;

typedef struct {
    uint64_t tag;
    union {
        struct0 _0;
    };
} struct1;

/* Function forward definitions */
int64_t _1_main(void);

/* Function definitions */
int64_t _1_main(void) {
    struct0 _1_t1;
    struct1 _2_x;
    struct0 _1_t6;
    int64_t _1_$retval;
    _1_t1 = (struct0) {.tag=0, ._0=4};
    _2_x = (struct1) {.tag=0, ._0=_1_t1};
    _2_x._0._0 = 104;
    $tag_check(_2_x.tag, 0, "tests/integration/sums/double.orng:5:7:\n    x.sum.int\n     ^");
    _1_t6 = _2_x._0;
    $tag_check(_1_t6.tag, 0, "tests/integration/sums/double.orng:5:11:\n    x.sum.int\n         ^");
    _1_$retval = _2_x._0._0;
    return _1_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
