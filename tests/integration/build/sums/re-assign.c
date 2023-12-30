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

/* Function forward definitions */
int64_t _1453_main(void);

/* Function definitions */
int64_t _1453_main(void){
    int64_t _1453_t0;
    struct0 _1454_x;
    uint64_t _1453_t3;
    uint64_t _1453_t4;
    int64_t _1453_$retval;
    _1453_t0 = 4;
    _1454_x = (struct0) {.tag=0, ._0=_1453_t0};
    _1453_t3 = 0;
    $tag_check(_1453_t3, 0, "tests/integration/sums/re-assign.orng:6:16:\n    x.int = 103\n              ^");
    _1454_x._0 = 103;
    _1453_t4 = _1454_x.tag;
    $tag_check(_1453_t4, 0, "tests/integration/sums/re-assign.orng:4:3:\nfn main() -> Int {\n ^");
    _1453_$retval = _1454_x._0;
    return _1453_$retval;
}

int main(void) {
  printf("%ld",_1453_main());
  return 0;
}
