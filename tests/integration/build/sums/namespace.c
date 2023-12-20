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
int64_t _1418_main(void);

/* Function definitions */
int64_t _1418_main(void){
    int64_t _1418_t0;
    struct0 _1419_x;
    uint64_t _1418_t2;
    int64_t _1418_$retval;
    _1418_t0 = 104;
    _1419_x = (struct0) {.tag=0, ._0=_1418_t0};
    _1418_t2 = 0;
    $tag_check(_1418_t2, 0, "tests/integration/sums/namespace.orng:4:3:\nfn main() -> Int {\n ^");
    _1418_$retval = _1419_x._0;
    return _1418_$retval;
}

int main(void) {
  printf("%ld",_1418_main());
  return 0;
}
