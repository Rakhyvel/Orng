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
int64_t _1218_main(void);

/* Function definitions */
int64_t _1218_main(void){
    int64_t _1218_t0;
    struct0 _1219_x;
    uint64_t _1218_t2;
    int64_t _1218_$retval;
    _1218_t0 = 125;
    _1219_x = (struct0) {.tag=1, ._1=_1218_t0};
    _1218_t2 = 1;
    $tag_check(_1218_t2, 1, "tests/integration/optional/expected-option-if-else.orng:2:3:\nfn main() -> Int {\n ^");
    _1218_$retval = _1219_x._1;
    return _1218_$retval;
}

int main(void) {
  printf("%ld",_1218_main());
  return 0;
}
