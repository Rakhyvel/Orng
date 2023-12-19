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
int64_t _1685_main(void);

/* Function definitions */
int64_t _1685_main(void){
    int64_t _1685_t0;
    struct0 _1686_x;
    uint64_t _1685_t3;
    uint64_t _1685_t4;
    int64_t _1685_$retval;
    _1685_t0 = 4;
    _1686_x = (struct0) {.tag=0, ._0=_1685_t0};
    _1685_t3 = 0;
    $tag_check(_1685_t3, 0, "tests/integration/sums/re-assign.orng:6:16:\n    x.int = 103\n              ^");
    _1686_x._0 = 103;
    _1685_t4 = _1686_x.tag;
    $tag_check(_1685_t4, 0, "tests/integration/sums/re-assign.orng:4:3:\nfn main() -> Int {\n ^");
    _1685_$retval = _1686_x._0;
    return _1685_$retval;
}

int main(void) {
  printf("%ld",_1685_main());
  return 0;
}
