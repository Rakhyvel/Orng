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
int64_t _1268_main(void);

/* Function definitions */
int64_t _1268_main(void){
    int64_t _1268_t0;
    struct0 _1269_x;
    int64_t _1268_t3;
    uint64_t _1268_t5;
    int64_t _1268_$retval;
    _1268_t0 = 4;
    _1269_x = (struct0) {.tag=1, ._1=_1268_t0};
    _1269_x = (struct0) {.tag=0};
    _1268_t3 = 113;
    _1269_x = (struct0) {.tag=1, ._1=_1268_t3};
    _1268_t5 = 1;
    $tag_check(_1268_t5, 1, "tests/integration/optional/optional.orng:2:3:\nfn main() -> Int {\n ^");
    _1268_$retval = _1269_x._1;
    return _1268_$retval;
}

int main(void) {
  printf("%ld",_1268_main());
  return 0;
}
