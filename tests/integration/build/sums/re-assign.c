/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct0;

/* Typedefs */
struct struct0 {
    uint64_t tag;
    union {
        int64_t _0;
        uint8_t _1;
    };
};

/* Function forward definitions */
int64_t _1456_main(void);

/* Function definitions */
int64_t _1456_main(void){
    int64_t _1456_t0;
    struct struct0 _1457_x;
    uint64_t _1456_t3;
    uint64_t _1456_t4;
    int64_t _1456_$retval;
    _1456_t0 = 4;
    _1457_x = (struct struct0) {.tag=0, ._0=_1456_t0};
    _1456_t3 = 0;
    $tag_check(_1456_t3, 0, "tests/integration/sums/re-assign.orng:6:16:\n    x.int = 103\n              ^");
    _1457_x._0 = 103;
    _1456_t4 = _1457_x.tag;
    $tag_check(_1456_t4, 0, "tests/integration/sums/re-assign.orng:4:3:\nfn main() -> Int {\n ^");
    _1456_$retval = _1457_x._0;
    return _1456_$retval;
}

int main(void) {
  printf("%ld",_1456_main());
  return 0;
}
