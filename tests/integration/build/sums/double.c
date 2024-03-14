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
int64_t _1474_main(void);


/* Function definitions */
int64_t _1474_main(void){
    int64_t _1474_t0;
    struct struct0 _1474_t1;
    struct struct1 _1475_x;
    uint64_t _1474_t5;
    uint64_t _1474_t6;
    uint64_t _1474_t7;
    uint64_t _1474_t8;
    int64_t _1474_$retval;
    _1474_t0 = 4;
    _1474_t1 = (struct struct0) {.tag=0, ._0=_1474_t0};
    _1475_x = (struct struct1) {.tag=0, ._0=_1474_t1};
    _1474_t5 = 0;
    $tag_check(_1474_t5, 0, "tests/integration/sums/double.orng:4:11:\n    x.sum.int = 104\n         ^");
    _1474_t6 = _1475_x._0.tag;
    $tag_check(_1474_t5, 0, "tests/integration/sums/double.orng:4:20:\n    x.sum.int = 104\n                  ^");
    $tag_check(_1474_t6, 0, "tests/integration/sums/double.orng:4:20:\n    x.sum.int = 104\n                  ^");
    _1475_x._0._0 = 104;
    _1474_t7 = _1475_x.tag;
    $tag_check(_1474_t7, 0, "tests/integration/sums/double.orng:5:11:\n    x.sum.int\n         ^");
    _1474_t8 = _1475_x._0.tag;
    $tag_check(_1474_t7, 0, "tests/integration/sums/double.orng:2:3:\nfn main() -> Int {\n ^");
    $tag_check(_1474_t8, 0, "tests/integration/sums/double.orng:2:3:\nfn main() -> Int {\n ^");
    _1474_$retval = _1475_x._0._0;
    return _1474_$retval;
}


int main(void) {
  printf("%ld",_1474_main());
  return 0;
}
