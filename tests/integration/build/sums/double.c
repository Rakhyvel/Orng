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
int64_t _1645_main(void);

/* Function definitions */
int64_t _1645_main(void){
    int64_t _1645_t0;
    struct0 _1645_t1;
    struct1 _1646_x;
    uint64_t _1645_t4;
    uint64_t _1645_t5;
    uint64_t _1645_t6;
    uint64_t _1645_t7;
    int64_t _1645_$retval;
    _1645_t0 = 4;
    _1645_t1 = (struct0) {.tag=0, ._0=_1645_t0};
    _1646_x = (struct1) {.tag=0, ._0=_1645_t1};
    _1645_t4 = 0;
    $tag_check(_1645_t4, 0, "tests/integration/sums/double.orng:4:11:\n    x.sum.int = 104\n         ^");
    _1645_t5 = _1646_x._0.tag;
    $tag_check(_1645_t4, 0, "tests/integration/sums/double.orng:4:20:\n    x.sum.int = 104\n                  ^");
    $tag_check(_1645_t5, 0, "tests/integration/sums/double.orng:4:20:\n    x.sum.int = 104\n                  ^");
    _1646_x._0._0 = 104;
    _1645_t6 = _1646_x.tag;
    $tag_check(_1645_t6, 0, "tests/integration/sums/double.orng:5:11:\n    x.sum.int\n         ^");
    _1645_t7 = _1646_x._0.tag;
    $tag_check(_1645_t6, 0, "tests/integration/sums/double.orng:2:3:\nfn main() -> Int {\n ^");
    $tag_check(_1645_t7, 0, "tests/integration/sums/double.orng:2:3:\nfn main() -> Int {\n ^");
    _1645_$retval = _1646_x._0._0;
    return _1645_$retval;
}

int main(void) {
  printf("%ld",_1645_main());
  return 0;
}
