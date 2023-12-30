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
    };
} struct0;

/* Function forward definitions */
int64_t _1103_main(void);

/* Function definitions */
int64_t _1103_main(void){
    int64_t _1103_t0;
    struct0 _1104_x;
    int64_t _1103_t3;
    uint64_t _1103_t5;
    int64_t _1103_$retval;
    _1103_t0 = 4;
    _1104_x = (struct0) {.tag=0, ._0=_1103_t0};
    _1104_x = (struct0) {.tag=1};
    _1103_t3 = 113;
    _1104_x = (struct0) {.tag=0, ._0=_1103_t3};
    _1103_t5 = 0;
    $tag_check(_1103_t5, 0, "tests/integration/optional/optional.orng:2:3:\nfn main() -> Int {\n ^");
    _1103_$retval = _1104_x._0;
    return _1103_$retval;
}

int main(void) {
  printf("%ld",_1103_main());
  return 0;
}
