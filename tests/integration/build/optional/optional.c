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
        int64_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _1262_main(void);

/* Function definitions */
int64_t _1262_main(void){
    int64_t _1262_t0;
    struct0 _1263_x;
    int64_t _1262_t4;
    uint64_t _1262_t6;
    int64_t _1262_$retval;
    _1262_t0 = 4;
    _1263_x = (struct0) {.tag=1, ._1=_1262_t0};
    _1263_x = (struct0) {.tag=0};
    _1262_t4 = 113;
    _1263_x = (struct0) {.tag=1, ._1=_1262_t4};
    _1262_t6 = 1;
    $tag_check(_1262_t6, 1, "tests/integration/optional/optional.orng:2:3:\nfn main() -> Int {\n ^");
    _1262_$retval = _1263_x._1;
    return _1262_$retval;
}

int main(void) {
  printf("%ld",_1262_main());
  return 0;
}
