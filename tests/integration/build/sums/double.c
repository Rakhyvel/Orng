/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;
struct struct1;

/* Struct, union, and function definitions */
struct struct0 {
    uint64_t tag;
    union {
        int64_t _0;
        uint8_t _1;
    };
};

struct struct1 {
    uint64_t tag;
    union {
        struct struct0 _0;
    };
};

/* Function forward definitions */
int64_t _1466_main(void);


/* Function definitions */
int64_t _1466_main(void){
    int64_t _1466_t0;
    struct struct0 _1466_t1;
    struct struct1 _1467_x;
    uint64_t _1466_t4;
    uint64_t _1466_t5;
    uint64_t _1466_t6;
    uint64_t _1466_t7;
    int64_t _1466_$retval;
    _1466_t0 = 4;
    _1466_t1 = (struct struct0) {.tag=0, ._0=_1466_t0};
    _1467_x = (struct struct1) {.tag=0, ._0=_1466_t1};
    _1466_t4 = 0;
    $tag_check(_1466_t4, 0, "tests/integration/sums/double.orng:4:11:\n    x.sum.int = 104\n         ^");
    _1466_t5 = _1467_x._0.tag;
    $tag_check(_1466_t4, 0, "tests/integration/sums/double.orng:4:20:\n    x.sum.int = 104\n                  ^");
    $tag_check(_1466_t5, 0, "tests/integration/sums/double.orng:4:20:\n    x.sum.int = 104\n                  ^");
    _1467_x._0._0 = 104;
    _1466_t6 = _1467_x.tag;
    $tag_check(_1466_t6, 0, "tests/integration/sums/double.orng:5:11:\n    x.sum.int\n         ^");
    _1466_t7 = _1467_x._0.tag;
    $tag_check(_1466_t6, 0, "tests/integration/sums/double.orng:2:3:\nfn main() -> Int {\n ^");
    $tag_check(_1466_t7, 0, "tests/integration/sums/double.orng:2:3:\nfn main() -> Int {\n ^");
    _1466_$retval = _1467_x._0._0;
    return _1466_$retval;
}


int main(void) {
  printf("%ld",_1466_main());
  return 0;
}
