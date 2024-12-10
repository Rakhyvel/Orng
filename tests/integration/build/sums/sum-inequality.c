/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct0;

/* Struct, union, and function definitions */
struct struct0 {
    uint64_t tag;
    union {
        int64_t _0;
    };
};

/* Function forward definitions */
int64_t _1615_main(void);


/* Function definitions */
int64_t _1615_main(void){
    int64_t _1615_t0;
    struct struct0 _1616_x;
    uint64_t _1615_t10;
    int64_t _1615_$retval;
    _1615_t0 = 211;
    _1616_x = (struct struct0) {.tag=0, ._0=_1615_t0};
    _1615_t10 = 0;
    $tag_check(_1615_t10, 0, "tests/integration/sums/sum-inequality.orng:4:20:\n    if x != .none {\n                  ^");
    _1615_$retval = _1616_x._0;
    return _1615_$retval;
}


int main(void) {
  printf("%ld",_1615_main());
  return 0;
}
