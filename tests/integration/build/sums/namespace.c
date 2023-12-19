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
int64_t _1675_main(void);

/* Function definitions */
int64_t _1675_main(void){
    int64_t _1675_t0;
    struct0 _1676_x;
    uint64_t _1675_t2;
    int64_t _1675_$retval;
    _1675_t0 = 104;
    _1676_x = (struct0) {.tag=0, ._0=_1675_t0};
    _1675_t2 = 0;
    $tag_check(_1675_t2, 0, "tests/integration/sums/namespace.orng:4:3:\nfn main() -> Int {\n ^");
    _1675_$retval = _1676_x._0;
    return _1675_$retval;
}

int main(void) {
  printf("%ld",_1675_main());
  return 0;
}
