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
int64_t _1653_main(void);

/* Function definitions */
int64_t _1653_main(void){
    int64_t _1653_t0;
    struct0 _1654_x;
    uint64_t _1653_t2;
    int64_t _1653_$retval;
    _1653_t0 = 101;
    _1654_x = (struct0) {.tag=0, ._0=_1653_t0};
    _1653_t2 = 0;
    $tag_check(_1653_t2, 0, "tests/integration/sums/inferred.orng:2:3:\nfn main() -> Int {\n ^");
    _1653_$retval = _1654_x._0;
    return _1653_$retval;
}

int main(void) {
  printf("%ld",_1653_main());
  return 0;
}
